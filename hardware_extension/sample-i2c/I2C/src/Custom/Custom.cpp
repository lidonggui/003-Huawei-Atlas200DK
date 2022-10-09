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

#include "i2c.h"

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
    i2c i2c_ctrl;
    unsigned char read_value;

    if(i2c_ctrl.atlas_i2c_write(0x20,0x03,0x3f)==0)  //slave 0x20    reg 0x03  write value 0x3f
    {
        HIAI_ENGINE_LOG("i2c_ctrl write success ! \n");
    }
    else
    {
        HIAI_ENGINE_LOG("i2c_ctrl write error ! \n");
    }

    if(i2c_ctrl.atlas_i2c_read(0x20,0x03,&read_value)==0)
    {
        HIAI_ENGINE_LOG("i2c_ctrl read value = %d  \n",read_value);
    }
    else
    {
        HIAI_ENGINE_LOG("i2c_ctrl read error ! \n");
    }


    //I2C_SMBUS
    if(i2c_ctrl.atlas_setI2CSlave(0x3c) < 0)
    {
        printf("SET SLAVE failed...\r\n");
    }

    unsigned char cmd = 0x00;
    unsigned char data = 0xae;
    i2c_ctrl.atlas_i2c_smbus_write_byte_data(cmd,data);
    
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
