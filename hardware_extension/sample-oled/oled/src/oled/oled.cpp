#include <memory>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include "i2c.h"
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

#include <linux/ip.h>
#include <linux/fs.h>

#include "oled.h"
#include "i2c.h"
#include "oled_data.h"



oled::oled(void)
{
}

oled::~oled(void)
{

}


/**********************************************
// IIC Write Command
**********************************************/
void oled::Write_IIC_Command(uint8_t IIC_Command)
{
	i2c_ctrl.atlas_i2c_smbus_write_byte_data(OLED_REG_CMD,IIC_Command);
}

/**********************************************
// IIC Write Data
**********************************************/
void oled::Write_IIC_Data(uint8_t IIC_Data)
{
    i2c_ctrl.atlas_i2c_smbus_write_byte_data( OLED_REG_DAT, IIC_Data);
}

/**********************************************
// IIC Write byte
**********************************************/
void oled::OLED_WR_Byte(unsigned dat, unsigned cmd)
{
	if (cmd){
		Write_IIC_Data(dat);
	}
	else
	{
		Write_IIC_Command(dat);
	}
}

//初始化
void oled::OLED_Init(void)
{

    unsigned char  m,n;

    if(i2c_ctrl.atlas_setI2CSlave(OLED_ADDRESS) < 0)
    {
        printf("SET SLAVE failed...\r\n");
    }
	usleep(200*1000);


    for(m=0;m<128;m++)
        for(n=0;n<4;n++)
            OLED_GRAM[m][n]=0;

    OLED_WR_Byte(0xAE,OLED_CMD);//关闭显示

    OLED_WR_Byte(0x40,OLED_CMD);//---set low column address
    OLED_WR_Byte(0xB0,OLED_CMD);//---set high column address

    OLED_WR_Byte(0xC8,OLED_CMD);//-not offset

    OLED_WR_Byte(0x81,OLED_CMD);//设置对比�?
    OLED_WR_Byte(0xff,OLED_CMD);

    OLED_WR_Byte(0xa1,OLED_CMD);//段重定向设置

    OLED_WR_Byte(0xa6,OLED_CMD);//

    OLED_WR_Byte(0xa8,OLED_CMD);//设置驱动路数
    OLED_WR_Byte(0x1f,OLED_CMD);

    OLED_WR_Byte(0xd3,OLED_CMD);
    OLED_WR_Byte(0x00,OLED_CMD);

    OLED_WR_Byte(0xd5,OLED_CMD);
    OLED_WR_Byte(0xf0,OLED_CMD);

    OLED_WR_Byte(0xd9,OLED_CMD);
    OLED_WR_Byte(0x22,OLED_CMD);

    OLED_WR_Byte(0xda,OLED_CMD);
    OLED_WR_Byte(0x02,OLED_CMD);

    OLED_WR_Byte(0xdb,OLED_CMD);
    OLED_WR_Byte(0x49,OLED_CMD);

    OLED_WR_Byte(0x8d,OLED_CMD);
    OLED_WR_Byte(0x14,OLED_CMD);

    OLED_WR_Byte(0xaf,OLED_CMD);
}



void oled::OLED_Fill(unsigned char fill_Data)//全屏填充
{
    unsigned char m, n;
    for(m = 0; m < 4; m++){
        OLED_WR_Byte(0xb0 + m, OLED_CMD);	//page0-page1
        OLED_WR_Byte(0x00, OLED_CMD);		//low column start address
        OLED_WR_Byte(0x10, OLED_CMD);		//high column start address
        for(n=0;n<128;n++){
            OLED_WR_Byte(fill_Data, OLED_DATA);
        }
    }
}

void oled::OLED_CLS(void)
{
    OLED_Fill(0x00);
}

void oled::OLED_ON(void)//OLED唤醒
{
    OLED_WR_Byte(0X8D, OLED_CMD);  //设置电荷�?
    OLED_WR_Byte(0X14, OLED_CMD);  //开启电荷泵
    OLED_WR_Byte(0XAF, OLED_CMD);  //OLED唤醒
}

void oled::OLED_OFF(void)//让OLED休眠
{
    OLED_WR_Byte(0X8D, OLED_CMD);  //设置电荷�?
    OLED_WR_Byte(0X10, OLED_CMD);  //关闭电荷�?
    OLED_WR_Byte(0XAE, OLED_CMD);  //OLED休眠
}


/**************************************/
/**************************************/
// draw point
//x,y  screen display pos   x 0-127   y 0-31
//color  :color 0：not show  1：show
/**************************************/
void oled::OLED_SetDot(unsigned char x,unsigned char y,unsigned char color)
{
    unsigned char  pos ,bx,temp=0;

    if(x>127||y>31)return;//超出范围

    pos=y/8;

    bx=y%8;

    temp=1<<(bx);

    if(color==1)
        OLED_GRAM[x][pos]|=temp;
    else
        OLED_GRAM[x][pos]&=~temp;
}

/**************************************/
//Display all panel data
/**************************************/
void oled::OLED_Screen_display(void)
{
    unsigned char  m=0,n=0;

    for (m=0;m<4;m++){
        OLED_WR_Byte(0xb0+m, OLED_CMD);
        OLED_WR_Byte(0x00, OLED_CMD);
        OLED_WR_Byte(0x10, OLED_CMD);
        for(n=0;n<128;n++)
        {
            OLED_WR_Byte(OLED_GRAM[n][m], OLED_DATA);
        }

    }
}



/**************************************/
/**************************************/
//only clear ram data
/**************************************/
void oled::OLED_CLS_RAM(void)//清屏
{
    unsigned char  m,n;
    for(m=0;m<128;m++)
        for(n=0;n<4;n++)
            OLED_GRAM[m][n]=0;
}

//--------------------------------------------------------------
//void oled::OLED_ShowStr(unsigned char row,unsigned char col, unsigned char *str, unsigned char TextSize)
// Parameters     : row  (0~32/font_height )  col (0~128/font_width)  str (show string)
// TextSize -- 字符大小(1:6*8 ; 2:8*16)
// Description    :oled_data.h中的ASCII字符,有6*8和8*16
//--------------------------------------------------------------
void oled::OLED_ShowStr(unsigned char row,unsigned char col, char *str, unsigned char TextSize)
{
    unsigned char c = 0, i = 0;

    switch(TextSize)
    {
        case 1:  // 6 * 8
        {
            while(*str != '\0'){
                c = *str - 32;

                if(row>=32/8) break;
                if(col>=128/6) break;

                for(i = 0; i < 6; i++)
                    OLED_GRAM[6*col + i][row] |= (F6x8[c][i]);
                col++;
                str++;
            }
        }
        break;

        case 2:  //8 * 16
        {

            while(*str != '\0'){
                c = *str - 32;

                if(row>=32/16) break;
                if(col>=128/8) break;

                for(i=0;i<8;i++){
                    OLED_GRAM[8*col+i][2*row]|=(F8X16[c*16+i]);
                }
                for(i=0;i<8;i++){
                    OLED_GRAM[8*col+i][2*row+1]|=(F8X16[c*16+i+8]);
                }
                col++;
                *str++;
            }
        }
        break;

        default:
            break;
    }
}

void oled::OLED_RowClear(unsigned char row, unsigned char TextSize)
{

    unsigned char  m,n;

    switch(TextSize)
    {
        case 1:  // 6*8
        {
            if(row>=32/8) break;

            for(m=0;m<128;m++)
                OLED_GRAM[m][row]=0;

        }
        break;

        case 2: //8*16
        {

             if(row>=32/16) break;

             for(m=0;m<128;m++)
             {
                 OLED_GRAM[m][2*row]=0;
                 OLED_GRAM[m][2*row+1]=0;
             }
        }
        break;

        default:
            break;
    }
}
