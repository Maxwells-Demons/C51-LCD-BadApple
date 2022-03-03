
#include "lcd.h"


 /*12864判忙 */
bit Chek_Busy(void)
{
    //return 1;
	DataPort = 0xff;
    RW = 1;
    RS = 0;
    E = 1;
    E = 0;
    return (bit)(DataPort & 0x80);
}
/*------------------------------------------------
            选屏
i:0是左屏,1是右屏,2全屏
------------------------------------------------*/
void Choose_12864(unsigned char i)
{						 
   switch (i)			 
   {
       case 0: CS1 = 0;CS2 = 1;break;   
       case 1: CS1 = 1;CS2 = 0;break;
       case 2: CS1 = 0;CS2 = 0;break;
	   default: break;
   }
}
/*------------------------------------------------
        写命令
------------------------------------------------*/
void LCD_Cmd(unsigned char cmd)
{
    //while(Chek_Busy());
    RW = 0;	         
    RS = 0;
    DataPort = cmd;
    E = 1;
    E = 0;          
}
/*------------------------------------------------
        读LCD
------------------------------------------------*/
unsigned char LCD_Read()
{
    unsigned char read_data;
    while(Chek_Busy());
    RW = 1;//需进行一次空读
    RS = 1;
    E = 1;
    E = 0;

    RW = 1;
    RS = 1;
    E = 1;
    read_data = DataPort;
    E = 0;        
    return (read_data);    
}
/*------------------------------------------------
        写数据
------------------------------------------------*/
void  LCD_Data(unsigned char dat)
{
    //while(Chek_Busy());
    RW = 0;	         
    RS = 1;
    DataPort = dat;
    E = 1;
    E = 0; 
}
/*------------------------------------------------
             设置地址
PAGE:0-7;
Y_Address:0-63
------------------------------------------------*/
void Set_PageY(unsigned char PAGE,unsigned char Y_Address)
{
    LCD_Cmd(0xB8 + PAGE);
    LCD_Cmd(0x40 + Y_Address);
}
/*------------------------------------------------
                清屏
------------------------------------------------*/
void LCD_Clear(void)
{
    unsigned char page,row;
    Choose_12864(2);
    for (page = 0xb8; page < 0xc0; page ++)
    {
        LCD_Cmd(page);
    	LCD_Cmd(0x40);
    	for (row = 0; row < 64; row ++)
    	{
    	    LCD_Data(0x00);//对12864所有地址全部写零
    	}
    }
}
/*------------------------------------------------
               初始化
------------------------------------------------*/
void LCD_Init(void)
{
    CS2 = 0;
    CS1 = 0;
    LCD_Cmd(0x3F);//开显示
}
/*-------------------------------------------------
    显示一幅12864图片
-------------------------------------------------*/
void Dis_Picture(unsigned char *picture)
{
    unsigned char ii,kk;
	//LCD_Clear();
    for (kk = 0; kk < 4; kk ++)//LCD共分7=8页
    {
        Choose_12864(2);
        Set_PageY(kk,0);
        Choose_12864(0);        
        for (ii = 0; ii < 128; ii ++)
        {
            LCD_Data(*picture);
            picture ++;
            if (ii == 63)
            {
                Choose_12864(1);
            }
        }
    }
}
void Dis_Pictureb(unsigned char *picture)
{
    unsigned char ii,kk;
	//LCD_Clear();
    for (kk = 4; kk < 8; kk ++)//LCD共分7=8页
    {
        Choose_12864(2);
        Set_PageY(kk,0);
        Choose_12864(0);        
        for (ii = 0; ii < 128; ii ++)
        {
            LCD_Data(*picture);
            picture ++;
            if (ii == 63)
            {
                Choose_12864(1);
            }
        }
    }
}
void delayus(unsigned char t)
{
    while(--t);
}
void delayms(unsigned char t)
{
    while(t--)
    {
        delayus(245);
        delayus(245);
    }
}