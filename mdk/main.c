#include <REGX52.H>
#include "SD.h"
#include "lcd.h"






void main(void)
{
    char bb;
    bb=0;
    LCD_Init();
    LCD_Clear();
    SdInit();
    DATA[0]=255;;
    DATA[1]=1;
    DATA[2]=2;
    DATA[3]=3;
    DATA[511]=0xf0;
    //SdWriteBlock(DATA,2,512);


//	Dis_Picture(gImage_inba);
//	Dis_Pictureb(gImage_inba+512);
//	while(1);

    
    for(count=0;count<2192;count++)
    {
             
		SdReadBlock(DATA,SD_ADDR,512);
        SD_ADDR+=512;
        Dis_Picture(DATA);

        SdReadBlock(DATA,SD_ADDR,512);
		SD_ADDR+=512;
		Dis_Pictureb(DATA);
        delayms(12);
        bb++;
    }
    SD_ADDR=0;
    
	while(1);
}