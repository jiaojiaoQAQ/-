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
 ALIENTEK��ӢSTM32������ʵ��13
 TFTLCD��ʾʵ��  
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
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
int pro_number=2;//��Ʒ����Ŀ
 int main(void)
{	 
 	//u8 x=0;
	u8 lcd_id[12];	 //���LCD ID�ַ���
	int number=0;
	int j=0;
	int flag=0;
	delay_init();	 	 //��ʱ������ʼ��	  
	anjian_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
	//TIM3_Int_Init(3099,7199);//10Khz�ļ���Ƶ�ʣ�������5000Ϊ500ms  
 	LED_Init();			     //LED�˿ڳ�ʼ��
	LCD_Init();
	POINT_COLOR=BLACK;
	sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//��LCD ID��ӡ��lcd_id���顣 
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
		draw_pro(pro_number);//��ҳ
		anjian_number=key();
		
		//--------------------------------------------------------------------
		if(anjian_number==14)//add���������ҳ��
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
			if(anjian_number==14)//�˳�
			{
				duqu_init();
				flag=0;
				LCD_Clear(BACK_COLOR);
				goto zhuye;
			}
			if(anjian_number==13)//ȷ����������ӵĸ���
			{
				number=duqu_number[0]*100+duqu_number[1]*10+duqu_number[2];
				for(j=1;j<pro_number+1;j++)//j=��ӻ���ı��
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
				while(1)//��ӻ���ĸ���
					{
						anjian_number=key();
						duqu();
						draw_input_number();
						if(anjian_number==14)//�˳�
						{
							duqu_init();
							flag=0;
							LCD_Clear(BACK_COLOR);
							goto zhuye;
						}
						if(anjian_number==13)//ȷ��
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
	//-----------------------------------------------------------------------//�������Ʒ
			if(anjian_number==15)//�����������Ʒ����
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
				
				if(anjian_number==14)//�˳�
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
							
						if(anjian_number==14)//�˳�
						{
							duqu_init();
							LCD_Clear(BACK_COLOR);
							goto zhuye;
						}
						
						if(anjian_number==13)//ȷ����
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
			
		if(anjian_number==15)//out���������ҳ��
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
			if(anjian_number==14)//�˳�
			{
				duqu_init();
				flag=0;
				LCD_Clear(BACK_COLOR);
				goto zhuye;
			}
			if(anjian_number==13)//ȷ������������ĸ���
			{
				number=duqu_number[0]*100+duqu_number[1]*10+duqu_number[2];
				for(j=1;j<pro_number+1;j++)//j=��ӳ����ı��
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
				while(1)//��������ĸ���
					{
						anjian_number=key();
						duqu();
						draw_input_number();
						if(anjian_number==14)//�˳�
						{
							duqu_init();
							flag=0;
							LCD_Clear(BACK_COLOR);
							goto zhuye;
						}
						/*if(duqu_number[2]!=0&&flag==0)//ִֻ��һ��
						{
							add=duqu_number[0]*100+duqu_number[1]*10+duqu_number[2];
							pro[j].save+=add;
							flag=1;
						}
						delay(20);*/
						if(anjian_number==13)//ȷ��
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
	
	//-----------------------------------------------------------����
	if(anjian_number==13)//�������
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
			if(anjian_number==14)//�˳�
			{
				duqu_init();
				flag=0;
				LCD_Clear(BACK_COLOR);
				goto zhuye;
			}
				if(anjian_number==13)//ȷ��,�õ����
				{
				number=duqu_number[0]*100+duqu_number[1]*10+duqu_number[2];
				for(j=1;j<pro_number+1;j++)//j=��������ĵı��
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
						if(anjian_number==14)//�˳�
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
	 
 

 
