/*
 * calc.c
 *
 *  Created on: Jul 28, 2023
 *      Author: larar
 */


#include "calc.h"
#include "../UTILS/STD_TYPES.h"


uint8 searching (uint8 arr[],uint8 item,uint8 size)
{
	uint8 i;
	if(item=='*' || item=='/')
	{
		for(i=0;i<size;i++)
		{
			if (arr[i]=='*' || arr[i]=='/')
			{
				return i;
			}

		}
	}
	else if(item=='+' || item=='-')
	{
		for(i=0;i<size;i++)
		{
			if (arr[i]=='+' || arr[i]=='-')
			{
				return i;
			}
		}

	}
	return 0;
}



void Remove_Spaces (uint8 arr[],uint8 size)
{
	uint8 i;
	uint8 j=0;
	for (i=0;i<size;i++)
	{
		if(arr[i] !=' ')
		{
			arr[j]=arr[i];
			j++;
		}
	}
}

uint8 operate(uint8 operation,uint8 index,uint8 arr[])
{
	switch(operation)
	{
		case '*':
		arr[index-1]=(arr[index-1]-48)*(arr[index+1]-48);
		arr[index-1]=arr[index-1]+48;
		break;
		case '+':
		arr[index-1]=(arr[index-1]-48)+(arr[index+1]-48);
		arr[index-1]=arr[index-1]+48;
		break;
		case '-':
		arr[index-1]=(arr[index-1]-48)-(arr[index+1]-48);
		arr[index-1]=arr[index-1]+48;
		break;
		case '/':
		arr[index-1]=(arr[index-1]-48)/(arr[index+1]-48);
		arr[index-1]=arr[index-1]+48;
		break;

	}
	return arr[index-1];
}
