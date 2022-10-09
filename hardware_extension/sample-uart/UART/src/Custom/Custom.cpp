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

#include "uart.h"
/**
* @ingroup hiaiengine
* @brief HIAI_DEFINE_PROCESS : implemention of the engine
* @[in]: engine name and the number of input
*/

int uart_test_axample(void)
{
     int nread,ret;
     char send_buf[] = "testuartstring1232345\r\n";
     char buff[512];
     bzero(buff, 512);


     uart ctrl_uart;

     if(ctrl_uart.uart_open() < 0)
     {
         perror("uart_open error");
         return -1;
     }

     if((ret=ctrl_uart.uart_set_option(115200,8,'N',1)) < 0)
     {
         perror("uart_set_option error");
         return -1;
     }

     int len = ctrl_uart.uart_send(send_buf, sizeof(send_buf));

     if (len < 0)
     {
         printf("UART write data error");
     }

     while (1)
     {
          usleep(1000000);

          nread = ctrl_uart.uart_read(buff,512);
          printf("nread = %d\n",nread);
          printf("%s\n",buff);

          if(strcmp(buff,"exit123")==0)
          {
               printf("exit receiver loop mode\n");
               break;
          }
          bzero(buff,nread);//clear

     }
     ctrl_uart.uart_close();
     return 0;
}

HIAI_StatusT Custom::Init(const hiai::AIConfig &config,
    const std::vector<hiai::AIModelDescription> &modelDesc)
{
    //TODO:

    //EXAMPLE
    uart_test_axample();
    //EXAMPLE end

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
