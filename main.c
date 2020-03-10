#include "stm32f4xx.h"                  // Device header
int main(){
	unsigned char SEG[10]={0x88,0xEB,0xA4,0xA1,0xC3,0x91,0x90,0xAB,0x80,0x81};
	RCC->AHB1ENR=0x09;
	GPIOA->MODER=1<<2;
	GPIOD->MODER=1<<0|1<<2|1<<4|1<<6|1<<8|1<<10|1<<12|1<<14|1<<16;
	while(1){	
		GPIOA->ODR=1<<1;
/*		GPIOD->ODR|=0x88;
		for(int i=0;i<=6000000;i++){}
		GPIOD->ODR|=0xEB;*/
		for(int j=0;j<=10;j++)
			for(int i=0;i<=800000;i++){{
				GPIOD->ODR=SEG[j];
			}
		}
	}
}