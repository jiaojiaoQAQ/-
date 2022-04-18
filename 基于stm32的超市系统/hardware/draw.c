#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "timer.h"
#include "anjian.h"
#include "struct.h"
#include "duqu.h"
extern int number;
extern int pro_number;
extern int anjian_number;
extern int pen_number;
extern int duqu_number[3];
extern char duqu_name[3];
extern int apple_number;
extern int pro3_number;
extern int pro4_number;
extern int pro5_number;
extern int pro6_number;
extern int pro7_number;
extern int pro8_number;
extern int pro3_price;
extern int pro4_price;
extern int pro5_price;
extern int pro6_price;
extern int pro7_price;
extern int pro8_price;
extern char pro3_name[3];
extern char pro4_name[3];
extern char pro5_name[3];
extern char pro6_name[3];
extern char pro7_name[3];
extern char pro8_name[3];
extern int pro_number;
product pro[9];
void draw_zhuye(void)
{
    POINT_COLOR=BLACK;	  
		LCD_ShowString(160,25,200,40,24,"SHOPPING MALL");
		LCD_DrawRectangle(5,5,600,795); 
		//画格子
		LCD_DrawLine(5,60,600,60);
		LCD_DrawLine(5,115,600,115);
		LCD_DrawLine(5,170,600,170);
		LCD_DrawLine(5,225,600,225);
		LCD_DrawLine(5,280,600,280);
		LCD_DrawLine(5,335,600,335);
		LCD_DrawLine(5,390,600,390);
		LCD_DrawLine(5,445,600,445);
		LCD_DrawLine(5,500,600,500);
		LCD_DrawLine(5,555,600,555);
		LCD_DrawLine(5,600,600,600);//横线
		LCD_DrawLine(100,60,100,600);
		LCD_DrawLine(200,60,200,600);
		LCD_DrawLine(300,60,300,600);
	  LCD_DrawLine(390,60,390,600);//竖线
	
	
		//目录
		LCD_ShowString(6,75,90,50,24," NUM");
		LCD_ShowString(101,75,90,50,24," NAME");
		LCD_ShowString(201,75,90,50,24," UNIT");
		LCD_ShowString(301,75,90,50,24," PRICE");
		LCD_ShowString(391,75,90,50,24," SAVE");
	
	  //按钮
		LCD_DrawRectangle(15,610,215,670);
		LCD_DrawRectangle(250,610,450,670);
		LCD_DrawRectangle(15,710,215,770);
		LCD_DrawRectangle(250,710,450,770);
		//按钮的字
		LCD_ShowString(20,630,150,40,24,"  A.SEARCH");
		LCD_ShowString(255,630,150,40,24,"  B.ADD");
		LCD_ShowString(20,730,150,40,24,"  C.OUT");
		LCD_ShowString(255,730,150,40,24,"  D.RECORD");
}
void draw_pro(int pai)//从第0排开始
{
		int i=0;
		for(i=0;i<2;i++)
	{
		LCD_ShowNum(8,120+i*55,pro[i+1].num,3,24);
		LCD_ShowString(105,120+i*55,90,50,24,pro[i+1].name);
		LCD_ShowString(205,120+i*55,90,50,24,pro[i+1].unit);
		LCD_ShowNum(305,120+i*55,pro[i+1].price,3,24);
		LCD_ShowNum(395,120+i*55,pro[i+1].save,3,24);	
	}
	for(i=2;i<pai;i++)
	{
		LCD_ShowNum(8,120+i*55,pro[i+1].num,3,24);
		LCD_ShowString3(105,120+i*55,90,50,24,pro[i+1].name);
		LCD_ShowString(205,120+i*55,90,50,24,pro[i+1].unit);
		LCD_ShowNum(305,120+i*55,pro[i+1].price,3,24);
		LCD_ShowNum(395,120+i*55,pro[i+1].save,3,24);	
	}
}
void pro_define(int p)//商品定义
{
	if(p>=1)
	{
		pro[1].num=111;
		pro[1].name="apple";
		pro[1].unit="kg";
		pro[1].price=5;
		pro[1].save=apple_number;
	}
	if(p>=2)
	{
		pro[2].num=112;
		pro[2].name="pen";
		pro[2].unit="kg";
		pro[2].price=2;
		pro[2].save=pen_number;
	}
	if(p>=3)
	{
		pro[3].num=113;
		pro[3].name=pro3_name;
		pro[3].unit="kg";
		pro[3].price=pro3_price;
		pro[3].save=pro3_number;
	}
	if(p>=4)
	{
		pro[4].num=114;
		pro[4].name=pro4_name;
		pro[4].unit="kg";
		pro[4].price=pro4_price;
		pro[4].save=pro4_number;
	}
	if(p>=5)
	{
		pro[5].num=115;
		pro[5].name=pro5_name;
		pro[5].unit="kg";
		pro[5].price=pro5_price;
		pro[5].save=pro5_number;
	}
	if(p>=6)
	{
		pro[6].num=116;
		pro[6].name=pro6_name;
		pro[6].unit="kg";
		pro[6].price=pro6_price;
		pro[6].save=pro6_number;
	}
	if(p>=7)
	{
		pro[7].num=117;
		pro[7].name=pro7_name;
		pro[7].unit="kg";
		pro[7].price=pro7_price;
		pro[7].save=pro7_number;
	}
	if(p>=8)
	{
		pro[8].num=118;
		pro[8].name=pro8_name;
		pro[8].unit="kg";
		pro[8].price=pro8_price;
		pro[8].save=pro8_number;
	}
}
void draw_add(void)
{
		POINT_COLOR=BLACK;
		LCD_DrawRectangle(240,40,400,90);//编号框
		LCD_DrawRectangle(65,280,165,330);//确定框
		LCD_DrawRectangle(240,280,340,330);//返回框
		LCD_DrawRectangle(20,40,190,90);//输入编号框
		LCD_DrawRectangle(20,140,190,190);//输入数量框
		LCD_DrawRectangle(240,140,400,190);//数量框
		LCD_DrawRectangle(100,350,300,400);//新商品框
		LCD_ShowString(30,50,100,40,24,"  PRO NUM");//输入编号
		LCD_ShowString(30,150,90,40,24,"ADD NUM");//输入数量
		LCD_ShowString(70,300,50,40,24,"A.OK");//确定
		LCD_ShowString(250,300,70,40,24,"B.BACK");//返回
		LCD_ShowString(103,360,180,40,24," C.ADD NEW PRO");//添加新商品
}

void draw_out(void)
{
		POINT_COLOR=BLACK;
		LCD_DrawRectangle(240,40,400,90);//编号框
		LCD_DrawRectangle(65,280,165,330);//确定框
		LCD_DrawRectangle(240,280,340,330);//返回框
		LCD_DrawRectangle(20,40,190,90);//输出编号框
		LCD_DrawRectangle(20,140,190,190);//输出数量框
		LCD_DrawRectangle(240,140,400,190);//数量框
		LCD_ShowString(30,50,100,40,24,"  PRO NUM");//输出编号
		LCD_ShowString(30,150,90,40,24,"OUT NUM");//输出数量
		LCD_ShowString(70,300,50,40,24,"A.OK");//确定
		LCD_ShowString(250,300,70,40,24,"B.BACK");//返回
}
void draw_input_bianhao(void)
{
	if(duqu_number[0]>=0&&duqu_number[0]<10&&duqu_number[1]>=0&&duqu_number[1]<10&&duqu_number[2]>=0&&duqu_number[2]<10)
	{
		LCD_ShowNum(245,45,duqu_number[0],2,24);
		LCD_ShowNum(275,45,duqu_number[1],2,24);
		LCD_ShowNum(305,45,duqu_number[2],2,24);
	}
}
void draw_input_number(void)
{
	if(duqu_number[0]>=0&&duqu_number[0]<10&&duqu_number[1]>=0&&duqu_number[1]<10&&duqu_number[2]>=0&&duqu_number[2]<10)
	{
		LCD_ShowNum(245,145,duqu_number[0],2,24);
		LCD_ShowNum(275,145,duqu_number[1],2,24);
		LCD_ShowNum(305,145,duqu_number[2],2,24);
	}
}
void draw_search(void)
{
		POINT_COLOR=BLACK;
		LCD_DrawRectangle(240,40,400,90);//编号框
		LCD_DrawRectangle(65,280,180,330);//搜索框
		LCD_DrawRectangle(240,280,340,330);//返回框
		LCD_DrawRectangle(20,40,190,90);//输入编号框
		LCD_ShowString(30,50,100,40,24,"  PRO NUM");//输入编号
		LCD_ShowString(70,300,110,40,24,"A.SEARCH");//确定
		LCD_ShowString(250,300,70,40,24,"B.BACK");//返回
}
void draw_search_result(int s)
{
		LCD_DrawRectangle(5,100,600,270);//结果大框框
		LCD_DrawLine(5,185,600,185);
		LCD_DrawLine(100,100,100,270);
		LCD_DrawLine(200,100,200,270);
		LCD_DrawLine(300,100,300,270);
		LCD_DrawLine(390,100,390,270);//框框
		//目录
		LCD_ShowString(6,115,90,50,24," NUM");
		LCD_ShowString(101,115,90,50,24," NAME");
		LCD_ShowString(201,115,90,50,24," UNIT");
		LCD_ShowString(301,115,90,50,24," PRICE");
		LCD_ShowString(391,115,90,50,24," SAVE");
		//数据
		LCD_ShowNum(8,200,pro[s].num,3,24);
		LCD_ShowString(105,200,90,50,24,pro[s].name);
		LCD_ShowString(205,200,90,50,24,pro[s].unit);
		LCD_ShowNum(305,200,pro[s].price,3,24);
		LCD_ShowNum(395,200,pro[s].save,3,24);
}

void draw_add_new_pro(void)
{
	//名字框，价格框，确定框，返回框
	LCD_DrawRectangle(240,40,400,90);//名字框
	LCD_DrawRectangle(20,40,190,90);//输入名字框
	LCD_DrawRectangle(240,140,400,190);//价格框
	LCD_DrawRectangle(20,140,190,190);//输入价格框
	LCD_DrawRectangle(65,280,165,330);//确定框
	LCD_DrawRectangle(240,280,340,330);//返回框
	LCD_ShowString(30,50,100,40,24,"    NAME");//名字
	LCD_ShowString(30,150,100,40,24,"    PRICE");//价格
	LCD_ShowString(70,300,50,40,24,"A.OK");//确定
	LCD_ShowString(250,300,70,40,24,"B.BACK");//返回
}
void draw_input_name(void)
{
		LCD_ShowChar(245,45,duqu_name[0],24,0);
		LCD_ShowChar(275,45,duqu_name[1],24,0);
		LCD_ShowChar(305,45,duqu_name[2],24,0);
}
void draw_input_price(void)
{
	if(duqu_number[0]>=0&&duqu_number[0]<10&&duqu_number[1]>=0&&duqu_number[1]<10&&duqu_number[2]>=0&&duqu_number[2]<10)
	{
		LCD_ShowNum(245,145,duqu_number[0],2,24);
		LCD_ShowNum(275,145,duqu_number[1],2,24);
		LCD_ShowNum(305,145,duqu_number[2],2,24);
	}
}
void define_name(void)
{
	if(pro_number==2)
		{
					pro3_name[0]=duqu_name[0];
					pro3_name[1]=duqu_name[1];
					pro3_name[2]=duqu_name[2];
		}
	if(pro_number==3)
		{
					pro4_name[0]=duqu_name[0];
					pro4_name[1]=duqu_name[1];
					pro4_name[2]=duqu_name[2];
		}
	if(pro_number==4)
		{
					pro5_name[0]=duqu_name[0];
					pro5_name[1]=duqu_name[1];
					pro5_name[2]=duqu_name[2];
		}
	if(pro_number==5)
		{
					pro6_name[0]=duqu_name[0];
					pro6_name[1]=duqu_name[1];
					pro6_name[2]=duqu_name[2];
		}
	if(pro_number==6)
		{
					pro7_name[0]=duqu_name[0];
					pro7_name[1]=duqu_name[1];
					pro7_name[2]=duqu_name[2];
		}
	if(pro_number==7)
		{
					pro8_name[0]=duqu_name[0];
					pro8_name[1]=duqu_name[1];
					pro8_name[2]=duqu_name[2];
		}		
}




