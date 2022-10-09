/**
* @file i2c.cpp
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

#include "i2c.h"

/* I2C Device*/
#define I2C2_DEV_NAME                      "/dev/i2c-2"
#define I2C_RETRIES                        0x0701
#define I2C_TIMEOUT                        0x0702
#define I2C_SLAVE                          0x0703
#define I2C_RDWR                           0x0707
#define I2C_M_RD                           0x01


int i2c::i2c_write(unsigned char slave, unsigned char reg, unsigned char value)
{
    int ret;
    struct i2c_rdwr_ioctl_data ssm_msg = {0};
    unsigned char buf[2] = {0};
    ssm_msg.nmsgs = 1;
    ssm_msg.msgs = (struct i2c_msg *)malloc(ssm_msg.nmsgs * sizeof(struct i2c_msg));
    if (ssm_msg.msgs == NULL) {
        HIAI_ENGINE_LOG("Memory alloc error!\n");
        return -1;
    }
    buf[0] = reg;
    buf[1] = value;
    (ssm_msg.msgs[0]).flags = 0;
    (ssm_msg.msgs[0]).addr = (unsigned short)slave;
    (ssm_msg.msgs[0]).buf = buf;
    (ssm_msg.msgs[0]).len = 2;
    ret = ioctl(fd, I2C_RDWR, &ssm_msg);
    if (ret < 0) {
        HIAI_ENGINE_LOG("write error, ret=%#x, errorno=%#x, %s!\n", ret, errno, strerror(errno));
        free(ssm_msg.msgs);
        ssm_msg.msgs = NULL;
        return -1;
    }
    free(ssm_msg.msgs);
    ssm_msg.msgs = NULL;
    return 0;
}

int i2c::i2c_read(unsigned char slave, unsigned char reg, unsigned char *buf)
{
    int ret;
    struct i2c_rdwr_ioctl_data ssm_msg = {0};
    unsigned char regs[2] = {0};
    regs[0] = reg;
    regs[1] = reg;
    ssm_msg.nmsgs = 2;
    ssm_msg.msgs = (struct i2c_msg *)malloc(ssm_msg.nmsgs * sizeof(struct i2c_msg));
    if (ssm_msg.msgs == NULL) {
        HIAI_ENGINE_LOG("Memory alloc error!\n");
        return -1;
    }
    (ssm_msg.msgs[0]).flags = 0;
    (ssm_msg.msgs[0]).addr = slave;
    (ssm_msg.msgs[0]).buf = regs;
    (ssm_msg.msgs[0]).len = 1;
    (ssm_msg.msgs[1]).flags = I2C_M_RD;
    (ssm_msg.msgs[1]).addr = slave;
    (ssm_msg.msgs[1]).buf = buf;
    (ssm_msg.msgs[1]).len = 1;
    ret = ioctl(fd, I2C_RDWR, &ssm_msg);
    if (ret < 0) {
        HIAI_ENGINE_LOG("read data error,ret=%#x !\n", ret);
        free(ssm_msg.msgs);
        ssm_msg.msgs = NULL;
        return -1;
    }
    free(ssm_msg.msgs);
    ssm_msg.msgs = NULL;
    return 0;
}
/*
 * i2c_init, for access i2c device.
 */
int i2c::i2c_2_init()
{
    // open i2c-2 device
    fd = open(I2C2_DEV_NAME, O_RDWR);
    if (fd < 0) {
        HIAI_ENGINE_LOG("i2c-2 Can't open !\n");
        return -1;
    }
    // set i2c-1 retries time
    if (ioctl(fd, I2C_RETRIES, 1) < 0) {
        close(fd);
        fd = 0;
        HIAI_ENGINE_LOG("set i2c-2 retry fail!\n");
        return -1;
    }
    // set i2c-1 timeout time, 10ms as unit
    if (ioctl(fd, I2C_TIMEOUT, 1) < 0) {
        close(fd);
        fd = 0;
        HIAI_ENGINE_LOG("set i2c-2 timeout fail!\n");
        return -1;
    }
    return 0;
}

i2c::i2c(void)
{
    i2c_2_init();
}

i2c::~i2c(void)
{

}


int i2c::atlas_i2c_write(unsigned char slave, unsigned char reg, unsigned char data)
{
     int ret;
     ret = i2c_write(slave, reg, data);
     if (ret != 0) {
         close(fd);
         fd = 0;
         HIAI_ENGINE_LOG("atlas_i2c_write %#x %#x to %#x fail!\n", slave, data, reg);
         return -1;
      }
      return 0;
}


int i2c::atlas_i2c_read(unsigned char slave, unsigned char reg, unsigned char *data)
{
    int ret;
    ret = i2c_read(slave, reg, data);
    if (ret != 0) {
         close(fd);
         fd = 0;
         HIAI_ENGINE_LOG("atlas_i2c_read %#x %#x to %#x fail!\n",  slave, data, reg);
         return -1;
    }
    return 0;
}






