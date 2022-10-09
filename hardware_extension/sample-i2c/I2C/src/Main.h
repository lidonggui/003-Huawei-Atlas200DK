/**
* @file Main.h
*
* Copyright (c) Huawei Technologies Co., Ltd. 2019. All rights reserved.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#ifndef MAIN_H_
#define MAIN_H_

#include <string>
#include <hiaiengine/api.h>
#include <hiaiengine/graph.h>


class CustomDataRecvInterface : public hiai::DataRecvInterface {
 public:
    /**
    * @brief init
    * @param [in]desc:std::string
    */
    CustomDataRecvInterface(){}

    /**
    * @brief RecvData RecvData
    * @param [in]
    */
    HIAI_StatusT RecvData(const std::shared_ptr<void>& message);
};
#endif  // MAIN_H_