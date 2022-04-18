#include "anjian.h"
#include "duqu.h"
void anjian_init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);	
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0| GPIO_Pin_1| GPIO_Pin_2| GPIO_Pin_3;				
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;		
 GPIO_Init(GPIOF, &GPIO_InitStructure);							
 GPIO_ResetBits(GPIOF,GPIO_Pin_0| GPIO_Pin_1| GPIO_Pin_2| GPIO_Pin_3);
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4| GPIO_Pin_5| GPIO_Pin_6| GPIO_Pin_7;	    		
	GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_Out_PP; 		 
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;	
 GPIO_Init(GPIOF, &GPIO_InitStructure);	
 GPIO_SetBits(GPIOF,GPIO_Pin_4| GPIO_Pin_5| GPIO_Pin_6| GPIO_Pin_7);
}
unsigned char key(void)
{
	 unsigned char keynumber=0;
	 GPIO_SetBits(GPIOF,GPIO_Pin_4);
	GPIO_ResetBits(GPIOF,GPIO_Pin_5| GPIO_Pin_6| GPIO_Pin_7);
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0)==1)
	{while(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0)==1){keynumber=1;}}
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1)==1)
  {while(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1)==1){keynumber=2;}}
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2)==1)
{while(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2)==1){keynumber=3;}}
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3)==1)
	{while(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3)==1){keynumber=4;}}
	
	GPIO_SetBits(GPIOF,GPIO_Pin_5);
	GPIO_ResetBits(GPIOF,GPIO_Pin_4| GPIO_Pin_6| GPIO_Pin_7);
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0)==1)
{while(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0)==1){keynumber=5;}}
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1)==1)
{while(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1)==1){keynumber=6;}}
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2)==1)
{while(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2)==1){keynumber=7;}}
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3)==1)
	{while(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3)==1){keynumber=8;}}
	
	GPIO_SetBits(GPIOF,GPIO_Pin_6);
	GPIO_ResetBits(GPIOF,GPIO_Pin_5| GPIO_Pin_4| GPIO_Pin_7);
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0)==1)
{while(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0)==1){keynumber=9;}}
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1)==1)
{while(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1)==1){keynumber=10;}}
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2)==1)
{while(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2)==1){keynumber=11;}}
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3)==1)
	{while(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3)==1){keynumber=12;}}
	
	GPIO_SetBits(GPIOF,GPIO_Pin_7);
	GPIO_ResetBits(GPIOF,GPIO_Pin_5| GPIO_Pin_6| GPIO_Pin_4);
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0)==1)
{while(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0)==1){keynumber=13;}}
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1)==1)
{while(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1)==1){keynumber=14;}}
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2)==1)
{while(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2)==1){keynumber=15;}}
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3)==1)
	{while(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3)==1){keynumber=16;}}
	
	return keynumber;
}
	
