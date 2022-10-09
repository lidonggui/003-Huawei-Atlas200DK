/**
* @file wheel.cpp
*/

#include <memory>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include "hiaiengine/log.h"

#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <errno.h>
#include <string.h>

#include "wheel.h"


const unsigned char slave_addr = 0x40;

const unsigned char stop[70] = {0x00,0x04,0xe2,0xe4,0xe8,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,
                                0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,
                                0x00,0x10,0x00,0x00,0x00,0x10};



wheel::wheel(void)
{

}

wheel::~wheel(void)
{

}


int wheel::wheel_init(void)
{
    for(unsigned char i=0;i<70;i++)
    {
         if(i2c_ctrl.atlas_i2c_write(slave_addr,i,stop[i])!=0)
         {
            break;
         }
    }

    return 0;
}

int wheel::wheel_left_move(int direction,unsigned char speed)
{
    unsigned short value = speed*80;;


    if(direction == 1)
    {
        i2c_ctrl.atlas_i2c_write(slave_addr,0x0c,0x00);
        i2c_ctrl.atlas_i2c_write(slave_addr,0x0d,0x00);

        i2c_ctrl.atlas_i2c_write(slave_addr,0x10,value&0xff);
        i2c_ctrl.atlas_i2c_write(slave_addr,0x11,value>>8);

    }
    else if(direction == -1)
    {
        i2c_ctrl.atlas_i2c_write(slave_addr,0x0c,value&0xff);
        i2c_ctrl.atlas_i2c_write(slave_addr,0x0d,value>>8);

        i2c_ctrl.atlas_i2c_write(slave_addr,0x10,0x00);
        i2c_ctrl.atlas_i2c_write(slave_addr,0x11,0x00);
    }


    if(speed == 0)
    {
        i2c_ctrl.atlas_i2c_write(slave_addr,0x08,0x00);
        i2c_ctrl.atlas_i2c_write(slave_addr,0x09,0x00);
    }
    else
    {
        i2c_ctrl.atlas_i2c_write(slave_addr,0x08,0xa0);
        i2c_ctrl.atlas_i2c_write(slave_addr,0x09,0x0f);
    }


    return 0;
}

int wheel::wheel_right_move(int direction,unsigned char speed)
{
    unsigned short value = speed*80 ;;

    if(direction == 1)
    {
        i2c_ctrl.atlas_i2c_write(slave_addr,0x14,0x00);
        i2c_ctrl.atlas_i2c_write(slave_addr,0x15,0x00);

        i2c_ctrl.atlas_i2c_write(slave_addr,0x18,value&0xff);
        i2c_ctrl.atlas_i2c_write(slave_addr,0x19,value>>8);

    }
    else if(direction == -1)
    {
        i2c_ctrl.atlas_i2c_write(slave_addr,0x14,value&0xff);
        i2c_ctrl.atlas_i2c_write(slave_addr,0x15,value>>8);

        i2c_ctrl.atlas_i2c_write(slave_addr,0x18,0x00);
        i2c_ctrl.atlas_i2c_write(slave_addr,0x19,0x00);
    }

    if(speed == 0)
    {
        i2c_ctrl.atlas_i2c_write(slave_addr,0x1c,0x00);
        i2c_ctrl.atlas_i2c_write(slave_addr,0x1d,0x00);
    }
    else
    {
        i2c_ctrl.atlas_i2c_write(slave_addr,0x1c,0xa0);
        i2c_ctrl.atlas_i2c_write(slave_addr,0x1d,0x0f);
    }

    return 0;
}







