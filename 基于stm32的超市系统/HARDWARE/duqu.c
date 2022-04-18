#include "duqu.h"
#include "timer.h"
#include "anjian.h"
#include "beep.h"
extern int anjian_number;
int duqu_number[3];
char duqu_name[3];
int i=0;
void duqu(void)
{
	if(anjian_number!=0&&anjian_number<10)
	{
		duqu_number[i]=anjian_number;
		i+=1;
		i=i%3;
		jiaoyisheng();
	}
	if(anjian_number>=10)
	{
		jiaoyisheng();
	}
}
void duqu_zimu(void)
{
	if(anjian_number==1)
	{
		duqu_name[i]='a';
		i+=1;
		i=i%3;
	}
	if(anjian_number==2)
	{
		duqu_name[i]='b';
		i+=1;
		i=i%3;
	}
	if(anjian_number==3)
	{
		duqu_name[i]='c';
		i+=1;
		i=i%3;
	}
	if(anjian_number==4)
	{
		duqu_name[i]='d';
		i+=1;
		i=i%3;
	}
	if(anjian_number==5)
	{
		duqu_name[i]='e';
		i+=1;
		i=i%3;
	}
	if(anjian_number==6)
	{
		duqu_name[i]='f';
		i+=1;
		i=i%3;
	}
	if(anjian_number==7)
	{
		duqu_name[i]='g';
		i+=1;
		i=i%3;
	}
	if(anjian_number==8)
	{
		duqu_name[i]='h';
		i+=1;
		i=i%3;
	}
	if(anjian_number==9)
	{
		duqu_name[i]='i';
		i+=1;
		i=i%3;
	}
	if(anjian_number==10)
	{
		duqu_name[i]='j';
		i+=1;
		i=i%3;
	}
	if(anjian_number==11)
	{
		duqu_name[i]='k';
		i+=1;
		i=i%3;
	}
	if(anjian_number==12)
	{
		duqu_name[i]='l';
		i+=1;
		i=i%3;
	}
}
void duqu_init(void)
{
	i=0;
	duqu_number[0]=0;
	duqu_number[1]=0;
	duqu_number[2]=0;
	duqu_name[0]='0';
	duqu_name[1]='0';
	duqu_name[2]='0';
}

