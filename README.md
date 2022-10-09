# 介绍

​	华为开发平台介绍：

<img src="https://lidongyang-image.obs.cn-east-3.myhuaweicloud.com/typora/image-20221007152050457.png" alt="image-20221007152050457" style="zoom: 50%;" />

​	华为其实也在努力的建立自己的生态，尽可能的互通，包揽尽可能多的方面。这其实是一个很不错的战略，因为毕竟深受人们喜欢的 Apple 成功的原因之一就是生态做的非常棒，真的是非常棒，作为一个苹果用户来说，这是中肯的。当然希望华为也越来越壮大，和大疆一起。

​	Mindspore 开源深度学习框架。（开源）

<img src="https://lidongyang-image.obs.cn-east-3.myhuaweicloud.com/typora/image-20221007152412325.png" alt="image-20221007152412325" style="zoom:50%;" />

​	Mindspore 逻辑架构：

<img src="https://lidongyang-image.obs.cn-east-3.myhuaweicloud.com/typora/image-20221007152457929.png" alt="image-20221007152457929" style="zoom:50%;" />



​	开发平台 MindStudio ：

<img src="https://lidongyang-image.obs.cn-east-3.myhuaweicloud.com/typora/image-20221007152619148.png" alt="image-20221007152619148" style="zoom:50%;" />

​	开发板介绍： Huawei Atlas 200 Developer Kit

<img src="https://lidongyang-image.obs.cn-east-3.myhuaweicloud.com/typora/image-20221007152732458.png" alt="image-20221007152732458" style="zoom:50%;" />







# 玩转 Atlas 200 DK

​	接下来我会详细介绍如何配置 Atlas 200dk 的环境等等内容，都是根据我自己亲自经历和遇到的问题记录的，希望对大家有帮助。如果有问题或者勘误，欢迎联系我：（QQ）2816983830 | （微信）L13315179257 | （邮箱）2816983830@qq.com





## 开发板介绍和说明

### 环境介绍

​	Atlas 200 DK开发者套件 Atlas 200 Developer Kit（以下简称Atlas 200 DK ）是以昇腾310 AI处理器为核心的一个开发者板形态产品，为开发者提供一站式开发套件，助力开发者快速进行AI应用程序的开发。

​	本文主要介绍用户在使用Atlas 200 DK开发、运行AI应用程序前的准备工作，包括硬件的安装，系统启动盘的制作，如何进行Atlas 200 DK与用户PC机的通信连接、如何将Atlas 200 DK接入互联网等。

​	Atlas 200 DK的系统框图如下所示：
![img](https://lidongyang-image.obs.cn-east-3.myhuaweicloud.com/typora/zh-cn_image_0000001234805251.png)

- Atlas 200 AI加速模块是一款高性能的AI智能计算模块，可以实现图像、视频等多种数据分析与推理计算。

- Hi3559 Camera模块为图像/音频接口模块，用于进行图像/音频的采集和处理。

- Atlas 200 DK提供了USB网卡与NIC网卡，开发者可通过USB网卡与用户PC机进行直连通信，可通过NIC网卡将Atlas 200 DK接入互联网。

    其中USB网卡的默认IP地址是192.168.0.2，NIC网卡的默认IP地址是192.168.1.2。



### 安装部署流程（华为官方）

![img](https://lidongyang-image.obs.cn-east-3.myhuaweicloud.com/typora/zh-cn_image_0000001234805259.png)



1. 准备Atlas 200 DK正常工作所需配件及一台PC机，其作用及详细要求可参见[准备配件及PC机](https://www.hiascend.com/document/detail/zh/Atlas200DKDeveloperKit/1012/environment/atlased_04_0003.html)。
2. 进行硬件的安装，包含拆卸上盖及摄像头的安装，请参见[硬件安装](https://www.hiascend.com/document/detail/zh/Atlas200DKDeveloperKit/1012/environment/atlased_04_0004.html)。
3. 通过制作SD卡的方式安装Atlas 200 DK的操作系统及驱动固件，请参见[制作SD卡](https://www.hiascend.com/document/detail/zh/Atlas200DKDeveloperKit/1012/environment/atlased_04_0008.html)
4. 配置Atlas 200 DK的网络连接，使得Atlas 200 DK可与用户PC机通信，同时可通过相关配置将Atlas 200 DK接入互联网，请参见[配置网络连接](https://www.hiascend.com/document/detail/zh/Atlas200DKDeveloperKit/1012/environment/atlased_04_0012.html)。
5. 为提升系统安全性，首次登录Atlas 200 DK请修改操作系统用户密码，请参见[修改用户密码](https://www.hiascend.com/document/detail/zh/Atlas200DKDeveloperKit/1012/environment/atlased_04_0013.html)。
6. 安装CANN相关软件，部署好开发运行环境，详细请参见[安装CANN软件](https://www.hiascend.com/document/detail/zh/Atlas200DKDeveloperKit/1012/environment/atlased_04_0015.html)。



针对Atlas 200 DK，CANN软件有两种部署场景，如下图所示：

<img src="https://lidongyang-image.obs.cn-east-3.myhuaweicloud.com/typora/zh-cn_image_0000001235565223.png" alt="img" style="zoom: 67%;" />

我们使用的是合设环境，也就是开发和运行都在开发板上。





### 硬件介绍

#### LED指示灯

​	Atlas 200 DK 开发者套件（型号 3000）开发者板内有4个LED状态指示灯，如[图1](javascript:;)和[图2](javascript:;)所示。

<img src="https://lidongyang-image.obs.cn-east-3.myhuaweicloud.com/typora/zh-cn_image_0212887921.png" alt="img" style="zoom:50%;" />图一 <img src="https://www.hiascend.com/doc_center/source/zh/Atlas200DKDeveloperKit/1012/productdesc/figure/zh-cn_image_0205566091.png" alt="img" style="zoom: 33%;" />图二



> 说明：
>
> 指示灯丝印信息从左至右依次为MINI_LED2、MINI_LED1、3559_ACT、3559_VEDIO，与指示灯从左至右一一对应。

指示灯状态说明-1：

| MINI_LED2 | MINI_LED1 | 当前Atlas 200 DK 开发者套件（型号 3000）开发者板状态 | 注意事项                                                     |
| --------- | --------- | ---------------------------------------------------- | ------------------------------------------------------------ |
| 灭        | 灭        | Atlas 200 DK 开发者套件（型号 3000）开发者板启动     | 可以对Atlas 200 DK 开发者套件（型号 3000）开发者板断电或重启。 |
| 灭        | 亮        | Ascend 310启动                                       | 可以对Atlas 200 DK 开发者套件（型号 3000）开发者板断电或重启，新版本升级时建议不要断电或重启。 |
| 闪烁      | 闪烁      | 固件升级                                             | 不能执行Atlas 200 DK 开发者套件（型号 3000）开发者板断电或重启操作，否则会导致固件升级不完整，单板损坏。当新版本升级时才会有固件升级流程，升级时间比较久，预计在15分钟内，请您耐心等待。 |
| 亮        | 亮        | Atlas 200 DK 开发者套件（型号 3000）开发者板启动完成 | 可以对Atlas 200 DK 开发者套件（型号 3000）开发者板断电或重启。 |



指示灯状态说明-2：

| 3559_ACT | 3559_VEDIO | 当前Atlas 200 DK 开发者套件（型号 3000）开发者板状态 | 注意事项 |
| -------- | ---------- | ---------------------------------------------------- | -------- |
| 灭       | 灭         | Hi3559C系统未启动                                    | 无       |
| 灭       | 亮         | Hi3559C系统启动中                                    | 无       |
| 亮       | 亮         | Hi3559C系统启动完成                                  | 无       |



#### 上盖的拆卸

​	当Atlas 200 DK开发者板上没有摄像头线缆接出时，向上按压塑料卡扣，使上盖一端松动，如[图1](javascript:;)所示。

<img src="https://lidongyang-image.obs.cn-east-3.myhuaweicloud.com/typora/zh-cn_image_0000001189405318.png" alt="img" style="zoom:67%;" />

​	当Atlas 200 DK开发者板上有摄像头线缆接出时，将一字螺丝刀插入上盖于底板之间的凹槽，旋转螺丝刀，将上盖的一端从盒体上撬出，如[图2](javascript:;)中①所示。

![img](https://lidongyang-image.obs.cn-east-3.myhuaweicloud.com/typora/zh-cn_image_0000001189725284.png)



> Atlas 200 DK有两种型号的主板，分别为IT21DMDA（旧主板）和IT21VDMB（新主板），您可以通过查看产品序号列的前八位来判断主板型号。



#### 安装摄像头

​	将Atlas 200 DK开发者板的摄像头连接器固定件由里向上打开90°。如[图4](javascript:;)所示。

![img](https://lidongyang-image.obs.cn-east-3.myhuaweicloud.com/typora/zh-cn_image_0000001207959801.png)

​	将黑色摄像头排线丝印显示“TO MAIN BD”的一端黑色线朝上，水平插入Atlas 200 DK开发者板的摄像头连接器CAMERA0或者CAMERA1，直至不能移动，并扣上固定件。如[图5](javascript:;)所示。

<img src="https://lidongyang-image.obs.cn-east-3.myhuaweicloud.com/typora/zh-cn_image_0000001162121306.png" alt="img" style="zoom:50%;" />

​	参照拆卸前原位置安装Atlas 200 DK开发者板的上盖。

​	不仅仅是开发板上有锁扣，我使用的树莓派的摄像头也是有锁扣的，两边同时向外推那个黑框就可以了，不清楚的可以上网查。



> 版本配套说明：
>
> Atlas 200 DK是以华为Ascend 310芯片为核心的开发者板形态产品，为开发者提供一站式开发套件，助力开发者进行应用程序的开发。
>
> Atlas 200 DK开发者套件包含：
>
> - 驱动固件包：包含AI软件栈及维测相关软件的驱动、固件及Device侧的文件系统镜像。
> - CANN包：AI异构计算架构。CANN是华为公司针对AI场景推出的异构并行计算架构，通过提供多层次的编程接口，支持用户快速构建基于Ascend平台的AI应用和业务。
>
> Atlas 200 DK的驱动固件包与CANN包的版本配套关系请参见：[Gitee](https://gitee.com/ascend/tools/blob/master/makesd/Version_Mapping_CN.md)。

## 资源列表：

- 华为 Atlas 200 DK开发者套件官方文档：
    - https://www.hiascend.com/document/moreVersion
    - 选择版本即可（[1.0.12直达](https://www.hiascend.com/document/detail/zh/Atlas200DKDeveloperKit/1012/productdesc/atlas200_DK_pdes_19_0003.html)）
- 社区成员分享：开发指南
    - https://bbs.huaweicloud.com/blogs/156757
    - 这篇文章里也有一些其他问题的传送门
- 华为 CANN 商用版官方指南：
    - https://www.hiascend.com/document/detail/zh/canncommercial/51RC1/envdeployment/instg/instg_000002.html
- 华为 MindStudio 官方指南：
    - https://www.hiascend.com/document/detail/zh/mindstudio/50RC1/instg/instg_000016.html
- 大佬记录
    - https://bbs.scumaker.org/t/topic/274




## 开发步骤概览

1. *安装 ubuntu 虚拟机*。有些地方也叫它“ubuntu 服务器”，其实都是一样的，因为 ubuntu 用来做服务器的比较多。
2. *制作系统镜像（sd卡）*。制作开发板上的 ubuntu 系统镜像。方法有两种
    1. 有读卡器（本文主要介绍这种）
    2. 无读卡器（这种可以根据官网的指南进行操作，问题应该不大）
3. *配置主机 ubuntu 网络连接*。
4. *配置开发板 ubuntu 网络连接*。
5. *照张相*。
6. 开个小灶：（因为疫情原因，老师让我们做了几个简单的小练习）
    1. *图像识别*。

7. 待续！！！





<div style="text-align:center">开始咯</div>



## 安装虚拟机



​	安装虚拟机其实是一件很简单的事情，找个网站下载安装包再破解就好了。这里我们使用的虚拟机时 VMware ，破解起来也很简单。

​	资源下载：（百度网盘）[下载页面-佛系软件 (foxirj.com)](https://foxirj.com/download-2?post=3075)——Player为精简版，Pro为专业版，建议使用Pro版本功能更全面

​	百度网盘的高速下载方法，可以去网上找一下，这个网址里也是有说明的。实在不行可以联系我，我帮你想办法。

​	破解方法：就是输入序列号，这个上网上随便找一个都可以。

> VMware Workstation 16 永久激活密钥
> ZF3R0-FHED2-M80TY-8QYGC-NPKYF
> YF390-0HF8P-M81RQ-2DXQE-M2UT6
> ZF71R-DMX85-08DQY-8YMNC-PPHV8
>
> VMware Workstation 15 永久激活密钥
> YG5H2-ANZ0H-M8ERY-TXZZZ-YKRV8
> UG5J2-0ME12-M89WY-NPWXX-WQH88
> UA5DR-2ZD4H-089FY-6YQ5T-YPRX6
> GA590-86Y05-4806Y-X4PEE-ZV8E0
> YA18K-0WY8P-H85DY-L4NZG-X7RAD
> ZF582-0NW5N-H8D2P-0XZEE-Z22VA
>
> 
>
> 说明：仅作学习用，禁止用作商业用途，侵删。



​	安装完虚拟机工具，接下来就是“机”了，也就是我们想要在上边虚拟谁，我选用的是 Ubuntu 系统（我个人比较喜欢这个系统），版本是 20.04，其他的应该也可以，不过要求是linux系统。

> 官方下载地址（外网，可能有点慢，自己懂的话就无所谓了）
>
> https://ubuntu.com/download
>
> Ubuntu中国镜像网站
>
> [Ubuntu系统下载 | Ubuntu](https://cn.ubuntu.com/download)
>
> 清华镜像网站
>
> [Index of /ubuntu-releases/ | 清华大学开源软件镜像站 | Tsinghua Open Source Mirror](https://mirrors.tuna.tsinghua.edu.cn/ubuntu-releases/)
>
> 中科大源
>
> http://mirrors.ustc.edu.cn/ubuntu-releases/
>
> 阿里云开源镜像站
>
> http://mirrors.aliyun.com/ubuntu-releases/?spm=a2c6h.25603864.0.0.23583deciylwHP
>
> 不知名镜像网站
>
> https://mirror.pnl.gov/releases/

​	从上面列举的网站中选择一个速度快的，进行下载，一般选择清华就好了。下载完会得到一个“.iso”文件，那个就是 ubuntu 的系统镜像了。



​	接下来，将 ubuntu 系统安装在 VM 虚拟机上：选择 “新建虚拟机”，选择“典型”就可以，但后选择自己下载的 ubuntu 的“.iso”镜像导入。然后设置主机名、用户名、密码等，然后开机启动即可。



## 制作sd卡

以下的操作都是基于“有读卡器”的情景，如果没有读卡器，请阅读前边提供的官方文档。



> 因为我们是学校的课程，老师提前制作好了镜像文件，我们直接使用<img src="https://lidongyang-image.obs.cn-east-3.myhuaweicloud.com/typora/image-20221007172004418.png" alt="image-20221007172004418" style="zoom:25%;" />balenaEtcher制作sd卡启动文件即可。如遇格式化直接选择取消就行。

资源请私聊

只要四个灯能全亮应该就没问题。





## 配置主机网络连接

​	安装完成 ubuntu 虚拟机后，首先要初始话 root 密码：`sudo passwd root` 然后输入两边新的 root 密码即可

​	切换root用户：`su root`

​	设置vm虚拟机的网络连接为 NAT 网桥连接。

​	新建一个终端来更新以下软件包：`sudo apt update` 然后 `sudo apt upgrade` 。

<img src="https://lidongyang-image.obs.cn-east-3.myhuaweicloud.com/typora/image-20221007173045892.png" alt="image-20221007173045892" style="zoom: 67%;" />

### 配置ssh连接开发板

​	Atlas 支持 usb 连接和网线连接，这里我是用的是 usb 连接：

> Atlas 200 DK开发板与Ubuntu服务器通过USB端口直连场景下，由于Atlas 200 DK的USB网卡的默认IP地址为192.168.1.2，所以需要修改Ubuntu服务器的USB 虚拟网卡的IP地址为192.168.1.x（x取值范围为0\~1，3\~254），使Atlas 200 DK与Ubuntu服务器可以通信。

- 打开主机ubuntu，安装“net-tools”：`sudo apt install net-tools`

- 查看网卡信息：`ifconfig -a`

    - <img src="https://lidongyang-image.obs.cn-east-3.myhuaweicloud.com/typora/image-20221007173552135.png" alt="image-20221007173552135" style="zoom:67%;" />
    - 那个“usb0”的名字可能不尽相同，一个简单的办法就是用usb连上主机和开发板看一次，然后断开看一次，就能找到啦:happy: 。

- 开发板上电后4颗灯全亮代表系统配置成功了，可以进行接下来的操作。

- 添加 usb 网卡的静态ip

    - 进入 root 权限：`su root`

    - 配置netplan：`vi /etc/netplan/01-netcfg.yaml` 添加如下信息

    - ```yaml
        network:
          version: 2
          renderer: NetworkManager
          ethernets:
            usb0:  #要配置的网卡名
              dhcp4: no  #关闭 DHCP4 
              addresses: [192.168.1.223/8]  #设置本机 ip 及掩码
              gateway4: 225.225.225.0  #设置网关
              nameservers:  #设置域名解析服务器
                address: [114.114.114.114]
        ```

    - usb0是 Atlas 200 dk 连接后显示的网卡，根据情况自己选择对应的名称。

- 修改后使配置生效：`netplan apply`

- 重启 `ifconfig -a` 查看是否生效：生效的标志就是你修改的网卡的 inet ip 从原来的ip变成了你修改的ip，例如我的就是“192.168.1.223”

- 然后访问开发板：`ssh HwHiAiUser@192.168.1.2` 密码是：“Mind@123”

    - 如果可以连接成功就代表至此的配置都是成功的。



### 配置开发板联网

- 在 ubuntu 主机切换为 root 用户：`su root` 

- 查看网卡名：`ifconfig -a`

    - 如上图所示，需要找到本机网卡“ens37”，和开发板网卡“usb0”

- 在ubuntu主机配置网络：

    - `echo "1" > /proc/sys/net/ipv4/ip_forward` :允许报文转换

        - 记住这一步，可能下次重新开机的时候会重置为0，如果重置为零的话就把当前这一部分和下一部分的“配置开发板联网”和“配置开发板网络连接”重新按步骤做一遍应该就可以。

    - `iptables -t nat -A POSTROUTING -o ens37 -s 192.168.1.0/24 -j MASQUERADE`

    - `iptables -A FORWARD -i usb0 -o ens37 -m state --state RELATED,ESTABLISHED -j ACCEPT`

    - `iptables -A FORWARD -i usb0 -o ens37 -j ACCEPT`

    - ```bash
        #整理一下：一共有四条指令：
        echo "1" > /proc/sys/net/ipv4/ip_forward
        iptables -t nat -A POSTROUTING -o ens33 -s 192.168.1.0/24 -j MASQUERADE
        iptables -A FORWARD -i usb0 -o ens33 -m state --state RELATED,ESTABLISHED -j ACCEPT
        iptables -A FORWARD -i usb0 -o ens33 -j ACCEPT
        ```

- ubuntu 主机的配置就这么多了，接下来就是开发板的配置了。



## 配置开发板网络连接

- 登录开发板：`ssh HwHiAiUser@192.168.1.2` 密码是：“Mind@123”
- 切换至 root 用户：`su root` 密码同样是：“Mind@123”
- 配置缺省路由：`route add default gw 192.168.1.223 dev usb0` 
- 在开发板添加DNS：`vim /etc/systemd/resolved.conf`
    - 加入：`DNS=114.114.114.114`
    - <img src="https://lidongyang-image.obs.cn-east-3.myhuaweicloud.com/typora/image-20221007180343870.png" alt="image-20221007180343870" style="zoom:67%;" />  
    - 保存退出
- 在开发板重启刚刚修改涉及到的服务：`systemctl restart systemd-resolved.service` 
- 联网验证：`ping e.huawei.com` 如果有较多的返回内容说明成功。



## 照张相

​	前变配置完，我们就可以在 Atlas 上玩耍了 :hankey:

​	<img src="https://lidongyang-image.obs.cn-east-3.myhuaweicloud.com/typora/image-20221007195818288.png" alt="image-20221007195818288" style="zoom: 50%;" />



- 摄像头组装：

    - <img src="https://lidongyang-image.obs.cn-east-3.myhuaweicloud.com/typora/image-20221007195912162.png" alt="image-20221007195912162" style="zoom: 33%;" />
    - <img src="https://lidongyang-image.obs.cn-east-3.myhuaweicloud.com/typora/image-20221007195934571.png" alt="image-20221007195934571" style="zoom: 33%;" />
    - 注意注意注意，一定要注意排线的朝向，哪面朝上，哪面朝下。我这个第一次的时候就自以为然了，导致做错了好久。

- 下载项目文件（到开发板），解压包

    - 这个项目呢是 华为 Asend（昇腾）项目的一个样例项目，在其 Gitee 的官方仓库就可以找到：
    - [Ascend/samples - 码云 - 开源中国 (gitee.com)](https://gitee.com/ascend/samples/tree/master)
    - [cplusplus/level1_single_api/5_200dk_peripheral/ascendcamera · Ascend/samples - 码云 - 开源中国 (gitee.com)](https://gitee.com/ascend/samples/tree/master/cplusplus/level1_single_api/5_200dk_peripheral/ascendcamera)
    - 进到家目录：`cd ${HOME}`
    - 下载项目：`git clone https://gitee.com/ascend/samples.git`
    - 不行的话就下载（或者copy）到ubuntu主机，然后在所在目录执行迁移命令：`scp -r samples_master HwHiAiUser2192.168.1.2:samples` 

- 连接到开发板项目所在目录：

    - 连接：`ssh HwHiAiUser@192.168.1.2`
    - 进入到项目目录：`cd samples/` 

- 部署样例：

    - 设置编译所需要的环境变量：

    - ```
        export DDK_PATH=$HOME/Asend/asend-toolkit/latest/arm64-linux
        export NPU_HOST_LIB=$DDK_PATH/acllib/lib64/stub
        ```

        - 第一个变量“DDK_PATH”是有用的，第二个好像没用到，不过最好还是定义一下。

    - 切换到ascendcamera目录，创建存储编译文件的目录：

        - `cd ~/samples/cplusplus/level1_single_api/5_200dk_peripheral/ascendcamera` 
        - `mkdir -p build/intermediates/host`

    - 切换到host目录，进行编译：

        - `cmake ../../../src -DCMAKE_CXX_COMPILER=aarch64-linux-gnu-g++ -DCMAKE_SKIP_RPATH=TRUE` 
        - 生成编译文件
        - *这个时候就出现错误了*，你肯定会得到报错信息：“有未定义的变量”。

    - 其实这个项目中的CMakeLists.txt文件和我们ppt做测试的那一个是不一样的，而，可以用的是开发板自带的那个“`CMakefile`”。

        - 所以归根到底，这个测试样例项目文件是不需要下载的，直接用开发板自带的就行，前提是你在制作系统镜像时做进去了。
        - 假设已经有了那个文件：
        - 在上述的 “host” 目录进行编译：`cmake ~/samples(自带的那个)/cplusplus/level1_single_api/5_200dk_peripheral/ascendcamera/src -DCMAKE_CXX_COMPILER=aarch64-linux-gnu-g++ -DCMAKE_SKIP_RPATH=TRUE` 

    - 我们所用的 “CMakeLists.txt” ：

        - ```makefile
            # Copyright (c) Huawei Technologies Co., Ltd. 2019. All rights reserved.
            
            # CMake lowest version requirement
            cmake_minimum_required(VERSION 3.5.1)
            
            # project information
            project(sample_ascendcamera)
            
            # Compile options
            add_compile_options(-std=c++11)
            
            set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  "../../../out")
            set(CMAKE_CXX_FLAGS_DEBUG "-fPIC -O0 -g -Wall")
            set(CMAKE_CXX_FLAGS_RELEASE "-fPIC -O2 -Wall")
            
            add_definitions(-DENABLE_DVPP_INTERFACE)
            set(INC_PATH $ENV{DDK_PATH})
            
            if (NOT DEFINED ENV{DDK_PATH})
                set(INC_PATH "/usr/local/Ascend")
                message(STATUS "set default INC_PATH: ${INC_PATH}")
            else ()
                message(STATUS "env INC_PATH: ${INC_PATH}")
            endif()
            
            set(LIB_PATH $ENV{NPU_HOST_LIB})
            
            if (NOT DEFINED ENV{NPU_HOST_LIB})
                set(LIB_PATH "/usr/local/Ascend/acllib/lib64/stub/")
                message(STATUS "set default LIB_PATH: ${LIB_PATH}")
            else ()
                message(STATUS "env LIB_PATH: ${LIB_PATH}")
            endif()
            
            # Header path
            include_directories(
                ../inc/
                $ENV{HOME}/ascend_ddk/arm/include/third_party/
                ${INC_PATH}/acllib/include/
                $ENV{HOME}/ascend_ddk/arm/include/
                $ENV{HOME}/ascend_ddk/arm/include/ascenddk/
                $ENV{HOME}/Ascend/
                $ENV{HOME}/Ascend/ascenddk/
            )
            
            if(target STREQUAL "Simulator_Function")
                add_compile_options(-DFUNC_SIM)
            endif()
            
            # add host lib path
            link_directories(
                ${LIB_PATH}
                #$ENV{HOME}/ascend_ddk/host/lib/
                $ENV{HOME}/ascend_ddk/arm/lib/
                $ENV{HOME}/Ascend/driver/
                $ENV{HOME}/Ascend/
                ${INC_PATH}/atc/lib64/
            )
            
            
            add_executable(main
                    ascend_camera_parameter.cpp
                    camera.cpp
                            dvpp_jpege.cpp
                            dvpp_process.cpp
                            dvpp_resize.cpp
                    main_process.cpp
                    output_info_process.cpp
                    parameter_utils.cpp
                    utils.cpp
                    main.cpp)
            
            if(target STREQUAL "Simulator_Function")
                target_link_libraries(main funcsim)
            else()
                target_link_libraries(main ascendcl acl_dvpp stdc++  c_sec slog media_mini pthread protobuf presenteragent)
            endif()
            
            install(TARGETS main DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
            
            ```

        - 你可可以尝试用这个文件替换原文件，结果我没测试，不过问题应该不大吧

    - 编译完成后，使用`make`命令生成可执行文件“mian”,main文件在“ascendcamera/out”目录下

- 运行摄像头：

    - 合设环境，修改环境变量：

        - ```
            export LD_LIBRARY_PATH=
            
            source ~/.bashrc
            
            cd $HOME/samples_master（改成你自己那个文件夹名）/cplusplus/level1_single_api/5_200dk_peripheral/ascendcamera/out
            ```

    - 新建“output”文件夹：`mkdir output`

    - 进入到out目录执行拍照操作：

        - `./main -i -c 0 -o ./output/test001.jpg --overwrite` 
        - `./main -v -c 1 -t 60 --fps 20 -w 704 -h 576 -s ip:xxxx/presentername`

    - 参数说明：

        - -v：代表获取摄像头的视频，用来在Presenter Server端展示。
        - -c：表示摄像头所在的channel，此参数有0”和1两个选项，0对应Camera0，1对应Camera1，如果不填写，默认为0。
        - -t：表示获取60s的视频文件，如果不指定此参数，则获取视频文件直至程序退出。
        - -fps：表示存储视频的帧率，取值范围为1~20，如果不设置此参数，则默认存储的视频帧率为10fps。
        - -w：表示存储视频的宽。
        - -h：表示存储视频的高。
        - -s：后面的ip值为启动Presenter Server时文件scripts/param.conf中presenter_server_ip的IP地址，**xxxx**为Ascendcamera应用对应的Presenter Server服务器的端口号。
        - *presentername*：为在Presenter Server端展示的“View Name“，用户自定义，需要保持唯一，只能为大小写字母、数字、“_”的组合，位数3~20。

- 然后将得到的照片转移出来即可。用`scp`。





## 开个小灶

### 基于GoogLeNet的图像识别



























# Q&A

- 安装python3.7.5
    - https://pythontechworld.com/article/detail/EcQIz4GS7srO
- 管理多版本的 Python 
    - 查看python的环境：`whereis python`
    - 使用 `sudo update-alternatives --install /usr/bin/python python /usr/bin/python3.7 150` 管理多版本 python
- sudo update-alternatives --config python3
    - 进行版本切换
- 切换后可以直接使用 `python` 调出对应版本的 python
- 解决 pip 版本源和 python 版本不对应的问题：
    - 使用`wget https://bootstrap.pypa.io/get-pip.py` 
    - 然后运行：`python get-pip.py` 即可。



- 关于开发板上时间的问题：
    - 使用`tzselect` 设置时区
    - 然后手动强制更新时间到当前时间，然后使用当前正在使用的源，最大的问题应该就是源的问题。
    - 随后我会把正常的源贴过来。
    - 之后下载ntp工具，使用ntp自动校准即可：“`ntpdate -u  ntp5.aliyun.com`”，这里使用的是阿里云的ntp服务器。
        - 校准完成后显示的是 UTC 时间，会比我们正常的时间慢 8 个小时。
- 关于认证失败的问题，换源然后update一下去下载“`sudo apt install ca-certificatrs`”，一定要检查是不是最新版的！
- 其他的就正常使用就可以了。



- ping: socket: Address family not supported by protocol
    - https://github.com/iputils/iputils/issues/293
    - 加上一个选项“`-4`”就可以了。



- apt 显示没有 key

    - `The following signatures couldn't be verified because the public key is not available: NO_PUBKEY 3B4FE6ACC0B21F32`

    - 原因：更换三方源没有对应的Key

    - 解决办法：
        - 直接执行如下命令，比如我没有 `3B4FE6ACC0B21F32`，就需要执行
        - `sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 3B4FE6ACC0B21F32`



- 关于关机一次就不能联网的问题：

    - 连接：https://bbs.huaweicloud.com/forum/thread-14817-1-1.html

    - 每次ubuntu重启之后，都不能联网了，需要重新配置，后面发现是 /proc/sys/net/ipv4/ip_forward文件里的内容在ubuntu重启后就变回原来的0了。重新配置以下就好了，一定要细心，按照步骤来。

    - > 一、在uihost上配置
        >
        > root用户修改： 
        >
        > echo "1" > /proc/sys/net/ipv4/ip_forward #允许报文转换
        >
        > sudo iptables -t nat -A POSTROUTING -o enp2s0 -s 192.168.1.0/24 -j MASQUERADE
        >
        > sudo iptables -A FORWARD -i enp0s20f0u8 -o enp2s0 -m state --state RELATED,ESTABLISHED -j ACCEPT
        >
        > sudo iptables -A FORWARD -i enp0s20f0u8 -o enp2s0 -j ACCEPT
        >
        > enp0s20f0u8： uihost上usb虚拟的网卡，表示数据报的入口
        >
        > enp2s0： 连接到外网的网卡（wan)
        >
        > 第一条命令：配置NAT转换， -s表示只对开发者板上的IP报文做转换
        >
        > 第二条命令：配置转发
        >
        > 二、 在开发者板上配置缺省路由：
        >
        >  sudo ip route change default via 192.168.1.251 dev usb0
        >
        > 在开发者板上添加DNS：
        >
        > sudo vi /etc/resolvconf/resolv.conf.d/base
        >
        > 添加如下行：
        >
        > nameserver 114.114.114.114
        >
        > **仅作参考**





- 开发板使用的镜像源：

    - ```bash
        deb https://repo.huaweicloud.com/ubuntu-ports/ bionic main restricted universe multiverse
        deb-src https://repo.huaweicloud.com/ubuntu-ports/ bionic main restricted universe multiverse
        
        deb https://repo.huaweicloud.com/ubuntu-ports/ bionic-security main restricted universe multiverse
        deb-src https://repo.huaweicloud.com/ubuntu-ports/ bionic-security main restricted universe multiverse
        
        deb https://repo.huaweicloud.com/ubuntu-ports/ bionic-updates main restricted universe multiverse
        deb-src https://repo.huaweicloud.com/ubuntu-ports/ bionic-updates main restricted universe multiverse
        
        deb https://repo.huaweicloud.com/ubuntu-ports/ bionic-backports main restricted universe multiverse
        deb-src https://repo.huaweicloud.com/ubuntu-ports/ bionic-backports main restricted universe multiverse
        
        ## Not recommended
        # deb https://repo.huaweicloud.com/ubuntu-ports/ bionic-proposed main restricted universe multiverse
        # deb-src https://repo.huaweicloud.com/ubuntu-ports/ bionic-proposed main restricted universe multiverse
        
        
        #deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic main restricted universe multiverse
        #deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic main restricted universe multiverse
        #deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
        #deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
        #deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
        #deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
        #deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
        #deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
        #deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse
        #deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse
        
        # 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释
        deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ bionic main restricted universe multiverse
        deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ bionic main restricted universe multiverse
        deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ bionic-updates main restricted universe multiverse
        deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ bionic-updates main restricted universe multiverse
        deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ bionic-backports main restricted universe multiverse
        deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ bionic-backports main restricted universe multiverse
        deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ bionic-security main restricted universe multiverse
        deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ bionic-security main restricted universe multiverse
        
        # 预发布软件源，不建议启用
        # deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ bionic-proposed main restricted universe multiverse
        # deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ bionic-proposed main restricted universe multiverse
        deb http://old-releases.ubuntu.com/ubuntu/ groovy main restricted
        deb http://old-releases.ubuntu.com/ubuntu/ groovy multiverse universe
        deb http://old-releases.ubuntu.com/ubuntu/ groovy-updates main restricted
        deb http://old-releases.ubuntu.com/ubuntu/ groovy-updates multiverse universe
        deb http://old-releases.ubuntu.com/ubuntu/ groovy-backports main restricted
        deb http://old-releases.ubuntu.com/ubuntu/ groovy-backports multiverse universe
        deb http://old-releases.ubuntu.com/ubuntu/ groovy-security main restricted
        deb http://old-releases.ubuntu.com/ubuntu/ groovy-security multiverse universe
        ```

    - 









# **TEMP && 内容备份**

> 修改 “INSTALL_DIR”
>
> ```bash
> export INSTALL_DIR=$HOME/samples_master/cplusplus/level1_single_api/5_200dk_peripheral/ascendcamera/build/intermediates/host/installed_dir
> ```
>
> 查看“LD_LIBRARY_PATH”
>
> ```bash
> HwHiAiUser@davinci-mini:~/samples_master/cplusplus/level1_single_api/5_200dk_peripheral/ascendcamera/build/intermediates/host$ echo $LD_LIBRARY_PATH
> /usr/lib64/aicpu_kernels/0/aicpu_kernels_device:/home/HwHiAiUser/Ascend/acllib/lib64:/usr/local/python3.7.5/lib:/home/HwHiAiUser/Ascend/acllib/lib64:/home/HwHiAiUser/ascend_ddk/arm/lib::/usr/lib64/aicpu_kernels/0/aicpu_kernels_device/sand_box
> ```
>
> atc
>
> ```shell
> atc --model=./googlenet.prototxt --weight=./googlenet.caffemodel --framework=0 --output=googlenet_yuv --soc_version=Ascend310 --insert_op_conf=./insert_op.cfg --input_shape="data:1,3,224,224" --input_format=NCHW
> 
> atc --model=yolov3.prototxt --weight=yolov3.caffemodel --framework=0 --output=yolov3_yuv --soc_version=Ascend310 --insert_op_conf=aipp_nv12.cfg
> 
> atc --model=./mobilenetv2.air --framework=1 --output=garbage_yuv --soc_version=Ascend310 --insert_op_conf=./insert_op_yuv.cfg --input_shape="data:1,3,224,224" --input_format=NCHW
> ```
>
> 



