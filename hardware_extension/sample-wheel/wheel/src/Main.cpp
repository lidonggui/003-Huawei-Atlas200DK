/**
* @file Main.cpp
*
* Copyright (c) Huawei Technologies Co., Ltd. 2019. All rights reserved.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#include <unistd.h>
#include <thread>
#include <fstream>
#include <algorithm>
#include <libgen.h>
#include <string.h>
#include "Main.h"
#include "hiaiengine/api.h"

uint32_t graphId = 0;
int flag = 1;
std::mutex mt;

/**
* @brief RecvData RecvData回调，保存文件
* @param [in]
*/
HIAI_StatusT CustomDataRecvInterface::RecvData(const std::shared_ptr<void>& message) {
    std::shared_ptr<std::string> data =  std::static_pointer_cast<std::string>(message);
    mt.lock();
    flag--;
    mt.unlock();
    return HIAI_OK;
}

// if device is disconnected, destroy the graph
HIAI_StatusT DeviceDisconnectCallBack() {
	mt.lock();
	flag = 0;
	mt.unlock();
	return HIAI_OK;
}

// Init and create graph
HIAI_StatusT HIAI_InitAndStartGraph() {
    // Step1: Global System Initialization before using HIAI Engine
    HIAI_StatusT status = HIAI_Init(0);

    // Step2: Create and Start the Graph
    std::list<std::shared_ptr<hiai::Graph>> graphList;
    status = hiai::Graph::CreateGraph("./graph.config",graphList);
    if (status != HIAI_OK) {
        HIAI_ENGINE_LOG(status, "[Main] Failed to start graph");
        return status;
    }

    // Step3
    std::shared_ptr<hiai::Graph> graph = graphList.front();
    if (graph == nullptr) {
        HIAI_ENGINE_LOG("[Main] Failed to get the graph");
        return status;
    }
    graphId = graph->GetGraphId();
    hiai::EnginePortID target_port_config;
    target_port_config.graph_id = graphId;
    target_port_config.engine_id = 611;
    target_port_config.port_id = 0;
    graph->SetDataRecvFunctor(target_port_config, std::shared_ptr<CustomDataRecvInterface>(new CustomDataRecvInterface()));
    graph->RegisterEventHandle(hiai::HIAI_DEVICE_DISCONNECT_EVENT, DeviceDisconnectCallBack);
	return HIAI_OK;
}

int main(int argc, char* argv[]) {
    HIAI_StatusT ret = HIAI_OK;
	char * dirc = strdup(argv[0]);
	if (dirc) {
	    char * dname = ::dirname(dirc);
	    chdir(dname);
	    HIAI_ENGINE_LOG("[Main] chdir to %s", dname);
	    free(dirc);
	}
    // 1.create graph
    ret = HIAI_InitAndStartGraph();
    if (ret != HIAI_OK) {
        HIAI_ENGINE_LOG("[Main] Failed to start graph");;
        return -1;
    }

    // 2.send data
    std::shared_ptr<hiai::Graph> graph = hiai::Graph::GetInstance(graphId);
    if (graph == nullptr) {
        HIAI_ENGINE_LOG("[Main] Failed to get the graph for id %u", graphId);
        return -1;
    }
    // send data to SourceEngine 0 port
    hiai::EnginePortID engineId;
    engineId.graph_id = graphId;
    engineId.engine_id = 611;
    engineId.port_id = 0;
    std::shared_ptr<std::string> data(new std::string);
    ret = graph->SendData(engineId, "string", std::static_pointer_cast<void>(data));
    if (ret != HIAI_OK) {
        HIAI_ENGINE_LOG("[Main] Failed to send data.");;
        return -1;
    }
	for (;;) {
        if(flag <= 0) {
            break;
        } else {
            usleep(100000);
        }
    }
    ret = hiai::Graph::DestroyGraph(graphId);
    if (ret != HIAI_OK) {
        HIAI_ENGINE_LOG("[Main] Failed to destroy graph.");;
        return -1;
    }
    return 0;
}
