#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "timer.h"
#include "anjian.h"
#include "draw.h"
#include "struct.h"
#include "duqu.h"
/************************************************
 ALIENTEK精英STM32开发板实验13
 TFTLCD显示实验  
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/
void delay(int time)
{
int i=0;
while(time--)
{
i=12000;
while(i--);
}

}
extern int anjian_number;
extern int duqu_number[3];
extern char duqu_name[3];
int add;
int out;
int apple_number=3;
int pen_number=1;
int pro3_number=0;
int pro4_number=0;
int pro5_number=0;
int pro6_number=0;
int pro7_number=0;
int pro8_number=0;
int pro3_price=0;
int pro4_price=0;
int pro5_price=0;
int pro6_price=0;
int pro7_price=0;
int pro8_price=0;
char pro3_name[3];
char pro4_name[3];
char pro5_name[3];
char pro6_name[3];
char pro7_name[3];
char pro8_name[3];
int pro_number=2;//商品的数目
 int main(void)
{	 
 	//u8 x=0;
	u8 lcd_id[12];	 //存放LCD ID字符串
	int number=0;
	int j=0;
	int flag=0;
	delay_init();	 	 //延时函数初始化	  
	anjian_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为115200
	//TIM3_Int_Init(3099,7199);//10Khz的计数频率，计数到5000为500ms  
 	LED_Init();			     //LED端口初始化
	LCD_Init();
	POINT_COLOR=BLACK;
	sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//将LCD ID打印到lcd_id数组。 
  	while(1) 
	{		 
		zhuye:
		apple_number=pro[1].save;
		pen_number=pro[2].save;
		pro3_number=pro[3].save;
		pro4_number=pro[4].save;
		pro5_number=pro[5].save;
		pro6_number=pro[6].save;
		pro7_number=pro[7].save;
		pro8_number=pro[8].save;
		pro3_price=pro[3].price;
		pro4_price=pro[4].price;
		pro5_price=pro[5].price;
		pro6_price=pro[6].price;
		pro7_price=pro[7].price;
		pro8_price=pro[8].price;
		draw_zhuye();
		pro_define(pro_number);
		draw_pro(pro_number);//主页
		anjian_number=key();
		
		//--------------------------------------------------------------------
		if(anjian_number==14)//add，进入添加页面
	{
		LCD_Clear(BACK_COLOR);
		delay(100);
		duqu_init();
		delay(100);
		while(1)
		{
		anjian_number=key();
		draw_add();
		duqu();
		draw_input_bianhao();
			if(anjian_number==14)//退出
			{
				duqu_init();
				flag=0;
				LCD_Clear(BACK_COLOR);
				goto zhuye;
			}
			if(anjian_number==13)//确定，输入添加的个数
			{
				number=duqu_number[0]*100+duqu_number[1]*10+duqu_number[2];
				for(j=1;j<pro_number+1;j++)//j=添加货物的编号
				{
					if(number==pro[j].num)
					{
						break;
					}
				}
				delay(100);
				duqu_init();
				delay(100);
				printf("%d",j);
				printf("   ");
				printf("%d",number);
				while(1)//添加货物的个数
					{
						anjian_number=key();
						duqu();
						draw_input_number();
						if(anjian_number==14)//退出
						{
							duqu_init();
							flag=0;
							LCD_Clear(BACK_COLOR);
							goto zhuye;
						}
						if(anjian_number==13)//确定
						{
							add=duqu_number[0]*100+duqu_number[1]*10+duqu_number[2];
							pro[j].save+=add;
							duqu_init();
							LCD_Clear(BACK_COLOR);
							//flag=0;
							delay(20);
							goto zhuye;
						}
					}
			}
	//-----------------------------------------------------------------------//添加新商品
			if(anjian_number==15)//进入添加新商品界面
	{
			LCD_Clear(BACK_COLOR);
			delay(100);
			duqu_init();
			delay(100);
			duqu_init();
			draw_add_new_pro();	
			while(1)
			{
				anjian_number=key();
				duqu_zimu();
				draw_input_name();
				
				if(anjian_number==14)//退出
				{
				duqu_init();
				flag=0;
				LCD_Clear(BACK_COLOR);
				goto zhuye;
				}
	
				if(anjian_number==13)
				{
					define_name();
					duqu_init();
					while(1)
						{
						draw_add_new_pro();
						anjian_number=key();
						duqu();
						draw_input_price();
							
						if(anjian_number==14)//退出
						{
							duqu_init();
							LCD_Clear(BACK_COLOR);
							goto zhuye;
						}
						
						if(anjian_number==13)//确定，
							{
									number=duqu_number[0]*100+duqu_number[1]*10+duqu_number[2];
									pro[pro_number+1].price=number;
									pro_number++;
									LCD_Clear(BACK_COLOR);
									duqu_init();
									goto zhuye;
							}						
						}
				}		
			}
	}	
	//-----------------------------------------------------------------------------
		}
	}
		//----------------------------------------------------------------
			
		if(anjian_number==15)//out，进入出货页面
	{
		LCD_Clear(BACK_COLOR);
		delay(100);
		duqu_init();
		delay(100);
		while(1)
		{
		anjian_number=key();
		draw_out();
		duqu();
		draw_input_bianhao();
			if(anjian_number==14)//退出
			{
				duqu_init();
				flag=0;
				LCD_Clear(BACK_COLOR);
				goto zhuye;
			}
			if(anjian_number==13)//确定，输入出货的个数
			{
				number=duqu_number[0]*100+duqu_number[1]*10+duqu_number[2];
				for(j=1;j<pro_number+1;j++)//j=添加出货的编号
				{
					if(number==pro[j].num)
					{
						break;
					}
				}
				delay(100);
				duqu_init();
				delay(100);
				printf("%d",j);
				printf("   ");
				printf("%d",number);
				while(1)//出货货物的个数
					{
						anjian_number=key();
						duqu();
						draw_input_number();
						if(anjian_number==14)//退出
						{
							duqu_init();
							flag=0;
							LCD_Clear(BACK_COLOR);
							goto zhuye;
						}
						/*if(duqu_number[2]!=0&&flag==0)//只执行一次
						{
							add=duqu_number[0]*100+duqu_number[1]*10+duqu_number[2];
							pro[j].save+=add;
							flag=1;
						}
						delay(20);*/
						if(anjian_number==13)//确定
						{
							out=duqu_number[0]*100+duqu_number[1]*10+duqu_number[2];
							pro[j].save-=out;
							duqu_init();
							LCD_Clear(BACK_COLOR);
							//flag=0;
							delay(20);
							goto zhuye;
						}
					}
			}
		}
	}
	//-----------------------------------------------------------
	
	//-----------------------------------------------------------搜索
	if(anjian_number==13)//点击搜索
	{
		LCD_Clear(BACK_COLOR);
		delay(100);
		duqu_init();
		delay(100);
		while(1)
			{
			draw_search();
			anjian_number=key();
			duqu();
			draw_input_bianhao();
			if(anjian_number==14)//退出
			{
				duqu_init();
				flag=0;
				LCD_Clear(BACK_COLOR);
				goto zhuye;
			}
				if(anjian_number==13)//确定,得到编号
				{
				number=duqu_number[0]*100+duqu_number[1]*10+duqu_number[2];
				for(j=1;j<pro_number+1;j++)//j=搜索货物的的编号
				{
					if(number==pro[j].num)
					{
						break;
					}
				}
				delay(100);
				duqu_init();
				delay(100);
						while(1)
						{
						anjian_number=key();
						draw_search_result(j);
						if(anjian_number==14)//退出
						{
							duqu_init();
							flag=0;
							LCD_Clear(BACK_COLOR);
							goto zhuye;
						}
						}
			}
	
	
	
	
	
	
			}
	
	
	
	
	
	
	
	
	
	
	
	
	
		}
	
	//--------------------------------------------------------------
	}
}
	 
 

 
