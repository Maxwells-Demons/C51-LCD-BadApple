#ifndef __SD_H__
#define __SD_H__
extern unsigned long  SD_ADDR;
extern unsigned int count;
extern unsigned char xdata DATA[512];

unsigned char SdInit(void);
unsigned char SdReadBlock(unsigned char *Block, unsigned long address,int len);
unsigned char SdWriteBlock(unsigned char *Block, unsigned long address,int len);


#endif