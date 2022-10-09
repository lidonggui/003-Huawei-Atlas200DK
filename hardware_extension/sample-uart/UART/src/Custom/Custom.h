/**
* @file Custom.h
*
* Copyright (c) Huawei Technologies Co., Ltd. 2019. All rights reserved.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#ifndef CUSTOM_ENGINE_H_
#define CUSTOM_ENGINE_H_

#include <iostream>
#include <string>
#include <dirent.h>
#include <memory>
#include <unistd.h>
#include <vector>
#include <stdint.h>
#include "hiaiengine/engine.h"
#include "hiaiengine/multitype_queue.h"

#define INPUT_SIZE 1
#define OUTPUT_SIZE 1

using hiai::Engine;
using namespace std;
using namespace hiai;

class Custom : public Engine {
public:
    Custom() :
        inputQueue(INPUT_SIZE) {}
    HIAI_StatusT Init(const hiai::AIConfig& config, const std::vector<hiai::AIModelDescription>& modelDesc);
    /**
    * @ingroup hiaiengine
    * @brief HIAI_DEFINE_PROCESS : reload Engine Process
    * @[in]: define the number of input and output
    */
    HIAI_DEFINE_PROCESS(INPUT_SIZE, OUTPUT_SIZE)
private:

    // Private implementation a member variable, which is used to cache the input queue
    hiai::MultiTypeQueue inputQueue;
};

#endif // CUSTOM_ENGINE_H_
