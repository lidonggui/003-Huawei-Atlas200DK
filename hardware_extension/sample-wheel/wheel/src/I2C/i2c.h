/**
* @file i2c.h
*/

#ifndef I2C_H_
#define I2C_H_

class i2c {
public:
    i2c(void) ;
    ~i2c(void) ;

    int atlas_i2c_write(unsigned char slave, unsigned char reg, unsigned char data);
    int atlas_i2c_read(unsigned char slave, unsigned char reg, unsigned char *data);

private:
    int i2c_write(unsigned char slave, unsigned char reg, unsigned char value);
    int i2c_read(unsigned char slave, unsigned char reg, unsigned char *buf);
    int i2c_2_init();

private:
    int fd;
    struct i2c_msg {
        unsigned short addr;     /* slave address */
        unsigned short flags;
        unsigned short len;
        unsigned char *buf;     /* message data pointer */
    };
    struct i2c_rdwr_ioctl_data {
        struct i2c_msg *msgs;   /* i2c_msg[] pointer */
        int nmsgs;              /* i2c_msg Nums */
    };
};

#endif // I2C_H_
