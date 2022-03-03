#ifndef __LCD_H__
#define __LCD_H__

#include "REGX52.h"

sbit E = P3^0;
sbit RW = P3^1;
sbit RS = P3^2;
sbit CS2 = P3^3;
sbit CS1 = P3^4;	//¶Ë¿Ú¶¨Òå
#define DataPort P2

bit Chek_Busy(void);
void Choose_12864(unsigned char i);
void LCD_Cmd(unsigned char cmd);
unsigned char LCD_Read();
void  LCD_Data(unsigned char dat);
void Set_PageY(unsigned char PAGE,unsigned char Y_Address);
void LCD_Clear(void);
void LCD_Init(void);
void Dis_Picture(unsigned char *picture);
void Dis_Pictureb(unsigned char *picture);
void delayus(unsigned char t);
void delayms(unsigned char t);


#endif