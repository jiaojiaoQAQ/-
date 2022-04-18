#ifndef __STRUCT_H
#define __STRUCT_H
#include "sys.h"

typedef struct pro
{
	int num;
	unsigned char *name;
	unsigned char *unit;
	int price;
	int save;
}product;

extern product pro[9];


#endif
