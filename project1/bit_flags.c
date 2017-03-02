/***********************************************************
	Author: Patrick Dempsey
	Date: 12/3/2016
	Effort: i lost track of time
	Purpose: to crate a data structure to store the bitflags binary line
***********************************************************/
#include<stdio.h>
#include <stdlib.h>
#include "bit_flags.h"

struct bit_flags
{	
	int size;
	int capacity;
	int* data;
};

typedef struct bit_flags BIT_flags;
//no init_defualt function
BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits)
{
	BIT_flags* pbit_flags = (BIT_flags*)malloc(sizeof(BIT_flags));
	int posi = number_of_bits / 32 + 1;
	int i;
	
	if (pbit_flags != NULL) //checking pre condition
	{
		pbit_flags->size = number_of_bits;
		pbit_flags->capacity = number_of_bits;
		pbit_flags->data = (unsigned int*)malloc(sizeof(unsigned int)*posi);
	
		if (pbit_flags->data == NULL)
		{
			//object is half created
			free(pbit_flags);
			pbit_flags = NULL;
		}
	
		else 
		{
			for (i = 0; i <posi; i++)
			{
			pbit_flags->data[i] = 0;
			}
			return(BIT_FLAGS) pbit_flags;
		}
	}
	else 
	{
	return NULL;//not a positive input
	}
	
}
Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	BIT_flags* pbit_flags = (BIT_flags*) hBit_flags;
	int* temp;
	int index, z;
	int posi = flag_position;
	
	while (posi > 31)
		{
			posi = posi - 32;
			index++;
		}
if (flag_position > 0 )
{

	if (hBit_flags != NULL)
	{
		if (flag_position >= pbit_flags->size)
		{	
		temp = malloc(sizeof(unsigned int)*(index+1));
	
			if (temp == NULL)
			{
			return FAILURE;
			}
	
			for (z = 0; z < (pbit_flags->size) / 32 +1; z++)
			{
			temp[z] = pbit_flags->data[z];
			}	
			
			for(z; z <= index; z++)
			{
			temp[z] = 0;
			}
		
		free(pbit_flags->data);
		pbit_flags->data=temp; 
		pbit_flags->capacity = flag_position;
		pbit_flags->size = flag_position;
		}
	}
	//YES -put at the available index (size)
	pbit_flags->data[index] |= (1 << posi);


//	int BIT = *((int *) hBit_flags);
//	 BIT |=  ( 1 << flag_position);
//	*((int *) hBit_flags) = BIT;

return SUCCESS;
}
else 
return FAILURE;

}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position)
{	
	BIT_flags* pbit_flags = (BIT_flags*) hBit_flags;
	int* temp;
	int index, z;
	int posi = flag_position;
	
	while (posi > 31)
		{
			posi = posi - 32; //posi is the remanider and is found here
			index++;//finds index by using 32 
		}
if (flag_position >0)
{
	if (hBit_flags != NULL)
	{
		if (flag_position >= pbit_flags->size)
		{	
		temp = malloc(sizeof(unsigned int)*(index+1));
	
			if (temp == NULL)
			{
			return FAILURE;
			}
	
			for (z = 0; z < (pbit_flags->size) +1; z++)
			{
			temp[z] = pbit_flags->data[z];
			}	
			
			for(z; z <= index; z++)
			{
			temp[z] = 0;
			}
		
		free(pbit_flags->data);
		pbit_flags->data=temp; 
		pbit_flags->capacity = flag_position;
		pbit_flags->size = flag_position;
		}
		else 
		return FAILURE;
	}
	//YES -put at the available index (size)
	pbit_flags->data[index] &= (1 << posi);

//
//	int BIT = *((int *) hBit_flags);
//	BIT &= ~(1 << flag_position);
//	*((int *) hBit_flags) = BIT;
}
else 
return FAILURE;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	
	//this function resiszes the same way that the set flag does
//	int i;
//	int bits;
//	
// int BIT = *((int *) hBit_flags);
//
//	for (i = 0; i <= 31; i++)
//	{
//	bits = (BIT >> flag_position) & 1;
//	}
//		return bits;
	BIT_flags* pbit_flags = (BIT_flags*)hBit_flags;
	int index = 0;
	int posi = flag_position;
	
	while (posi > 31)
		{
			posi = posi - 32; //posi is the remanider and is found here
			index++;//finds index by using 32 
		}
	int bit_posi = (flag_position - index * 32);

	if (flag_position >= 0 && hBit_flags != NULL)
	{
	
		if (flag_position>pbit_flags->size)
		{
			return -1;
		}
	
		if ((pbit_flags->data[index] >> bit_posi) & 1)
		{
			return 1;
		}
	
		else 
		{
			return 0;
		}
	}
}

int bit_flags_get_size(BIT_FLAGS hBit_flags)
{		
	BIT_flags* pbit_flags;
	pbit_flags = (BIT_flags*) hBit_flags;
	return pbit_flags->size;
}


int bit_flags_get_capacity(BIT_FLAGS hBit_flags)
{
	BIT_flags* pBit_flags;
	pBit_flags = (BIT_flags*) hBit_flags;
	
	return pBit_flags->capacity;
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags)
{
	BIT_flags* pBit_flags;
	pBit_flags = (BIT_flags*) phBit_flags;

	free(pBit_flags->data);
	free(pBit_flags);
	*phBit_flags = NULL;
}

