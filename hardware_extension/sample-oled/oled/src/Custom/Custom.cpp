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
#include "oled.h"
/**
* @ingroup hiaiengine
* @brief HIAI_DEFINE_PROCESS : implemention of the engine
* @[in]: engine name and the number of input
*/
namespace{
oled oled_ctrl;
}
int oled_example(void)
{
     int i = 0, j = 0;
     char disbuff[100];
     char show_str[] = "1234567890abcdefgh";

     oled_ctrl.OLED_Init();
     oled_ctrl.OLED_CLS_RAM();


     sprintf(disbuff,"%02d/%02d %02d %02d", i+5, i, i+13, i);
     oled_ctrl.OLED_ShowStr(0, 0, disbuff, 1);

     oled_ctrl.OLED_ShowStr(1, 1, "abcef11111gggghiii", 1);

     oled_ctrl.OLED_ShowStr(2, 6, disbuff, 1);
     sprintf(disbuff,"%02d/%02d %02d %02d", i+1, i, i+123, i);

     oled_ctrl.OLED_RowClear(2,1);
     oled_ctrl.OLED_ShowStr(2, 6, disbuff, 1);

     oled_ctrl.OLED_RowClear(3,1);
     oled_ctrl.OLED_ShowStr(3, 0, show_str, 1);

      //oled_ctrl.OLED_ShowStr(1, 0, "88abcef11111gggghiiitt", 2);

     for(i=0;i<128;i++)   //draw dot
        oled_ctrl.OLED_SetDot(i,31,1);

     oled_ctrl.OLED_Screen_display();
     return 1;
}


HIAI_StatusT Custom::Init(const hiai::AIConfig &config,
    const std::vector<hiai::AIModelDescription> &modelDesc)
{
    //TODO:
    //EXAMPLE
    oled_example();
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
