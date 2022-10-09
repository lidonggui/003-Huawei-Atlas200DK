# sample-wheel

#### 介绍
本样例介绍如何使用Atlas200DK 开发板 小车轮子控制wheel类使用样例


#### 软件架构
软件架构说明 此样例是用MindeStudio 新建一个Custom工程，在此工程基础上添加I2C类（类代码从atlas200dk码云上获取），然后封装了一个 wheel类 ，此类在src/wheel文件夹中, 在Custom.cpp 中调用wheel类函数进行小车轮子的控制

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

1.参考 wheel 类

    int wheel_init(void);   //初始化 只初始化一次

    int wheel_left_move(int direction,unsigned char speed);  //参数 direction 设置方向 -1 后退  1 向前 speed 速度（范围0-15）

    int wheel_right_move(int direction,unsigned char speed); // 同上

2.调用参考 Custom.cpp 中 

    //EXAMPLE

    wheel_ctrl.wheel_init();  //wheel init   only init one time 只调用一次，不要重复调用

    wheel_ctrl.wheel_left_move(1,7);   // left wheel move forward    speed 7 (0-15)  //设置 左轮以7的速度往前

    wheel_ctrl.wheel_right_move(-1,8);  //right wheel move back      speed 8 (0-5)   //设置 右轮以8的速度后退

    //EXAMPLE END

