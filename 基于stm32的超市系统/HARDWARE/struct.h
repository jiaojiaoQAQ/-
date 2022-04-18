#ifndef __STRUCT_H
#define __STRUCT_H
#include "sys.h"

typedef struct pro
{
	int num;
	char *name;
	char *unit;
	int price;
	int save;
}product;

extern product pro[9];


#endif
