/**
* @file Custom.cpp
*
* Copyright (c) Huawei Technologies Co., Ltd. 2019. All rights reserved.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#include <memory>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include "Custom.h"
#include "hiaiengine/log.h"
#include "hiaiengine/data_type_reg.h"
#include "../GPIO/gpio.h"

/**
* @ingroup hiaiengine
* @brief HIAI_DEFINE_PROCESS : implemention of the engine
* @[in]: engine name and the number of input
*/
HIAI_StatusT Custom::Init(const hiai::AIConfig &config,
    const std::vector<hiai::AIModelDescription> &modelDesc)
{
    //TODO:
    //EXAMPLE
    gpio io_ctrl;

    io_ctrl.gpio_set_direction(0,1);
    io_ctrl.gpio_set_direction(1,1);
    io_ctrl.gpio_set_value(0,1);
    io_ctrl.gpio_set_value(1,1);

    int value;
    if(io_ctrl.gpio_get_value(0,&value)==0)
    {
         if(value == 0)
            io_ctrl.gpio_set_value(1,0);
    }

    io_ctrl.gpio_set_direction(3, 1);
    io_ctrl.gpio_set_direction(4, 1);
    io_ctrl.gpio_set_direction(5, 1);
    io_ctrl.gpio_set_direction(6, 1);
    io_ctrl.gpio_set_direction(7, 0);


    io_ctrl.gpio_set_value(3,1);
    io_ctrl.gpio_set_value(4,1);
    io_ctrl.gpio_set_value(5,1);
    io_ctrl.gpio_set_value(6,1);

    int val;
    if (io_ctrl.gpio_get_value(7, &val) == 0)
    {
         if(val==1)
         {
             io_ctrl.gpio_set_value(3,0);
             io_ctrl.gpio_set_value(4,0);
         }
    }

    //end EXAMPLE

    return HIAI_OK;
}

HIAI_IMPL_ENGINE_PROCESS("Custom", Custom, INPUT_SIZE)
{
    //TODO:
	//user code here

	//send data
	std::shared_ptr<std::string> resultData(new std::string);
    HIAI_StatusT ret = SendData(0, "string", std::static_pointer_cast<void>(resultData));
    return ret;
}
