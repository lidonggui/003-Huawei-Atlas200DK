# sample-oled

#### 介绍
本样例介绍如何使用开发板 外接OLED屏的使用方法。

#### 软件架构
软件架构说明 此样例是用MindeStudio 新建一个Custom工程，在此工程基础上添加I2C类（类代码从atlas200dk码云上获取），然后封装了一个 oled类 ，此类在src/oled文件夹中, 在Custom.cpp 中调用oled类函数进行oled显示的控制

#### 使用样例前提：让HwHiAiUser用户获取 gpio i2c uart操作权限，登录开发板  编辑 /etc/rc.local 在exit 0 前 增加如下指令。
    echo 504 >/sys/class/gpio/export
    echo 444 >/sys/class/gpio/export
    chown -R HwHiAiUser /sys/class/gpio/gpio444
    chown -R HwHiAiUser /sys/class/gpio/gpio504
    chown -R HwHiAiUser /sys/class/gpio/gpio444/direction
    chown -R HwHiAiUser /sys/class/gpio/gpio504/direction
    chown -R HwHiAiUser /sys/class/gpio/gpio444/value
    chown -R HwHiAiUser /sys/class/gpio/gpio504/value
    chown -R HwHiAiUser /dev/i2c-1
    chown -R HwHiAiUser /dev/i2c-2
    chown -R HwHiAiUser /dev/ttyAMA0
    chown -R HwHiAiUser /dev/ttyAMA1
    usermod -aG HwHiAiUser HwHiAiUser

#### 使用说明

1.  参考oled类：

    void OLED_Init(void);   //only init one time

    void OLED_CLS(void);//clear screen

    void OLED_ShowStr(unsigned char row,unsigned char col, char *str, unsigned char TextSize);  // row  col show string
    
    void OLED_RowClear(unsigned char row, unsigned char TextSize);  //clear row ram data


2.  参考custom.cpp

    oled_example()函数，介绍如何使用oled类函数

    OLED_Init  OLED_CLS 这两个函数初始化调用一次。

    OLED_ShowStr（。。。）函数指定在某一行，某一列 显示 字符串 str , textsize是字体大小  1->6×8  2->8*16
                        row的范围 1号小字体（0～3） 2号大字体（0～1）

    oled_ctrl.OLED_RowClear(3,1);  函数清除某一行上的显示字符。然后可以在调用OLED_ShowStr 显示字符。

    oled_ctrl.OLED_Screen_display();  让屏幕显示出设定的字符。




