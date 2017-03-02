/***********************************************************
	Author: Patrick Dempsey
	Date: 12/3/2016
	Purpose: to crate a data structure to store the bitflags binary line
***********************************************************/
#include<stdio.h>
#include<stdlib.h>
#include"bit_flags.h"
#include "bit_flags.c"

int main(int argc, char* argv[])
{
	int i = 0; 
	int count = 0;

	BIT_FLAGS hBit_flags = NULL;
	//	hBit_flags = bit_flags_init_default();
	hBit_flags = bit_flags_init_number_of_bits(32);

		printf("hello ");

bit_flags_set_flag(hBit_flags, 1);

		printf("The size inital is 32 is %d\n", bit_flags_get_size(hBit_flags));
		printf("The capacity init is 32 is %d\n\n", bit_flags_get_capacity(hBit_flags));
	
	bit_flags_set_flag(hBit_flags, 110);
		printf("The size after hbit is 32 is %d\n", bit_flags_get_size(hBit_flags));
		printf("The capacity after hbit is 32 is %d\n", bit_flags_get_capacity(hBit_flags));
		printf("here.main");
	for (i = 0; i < 32; i++) 
	{
		printf("i = %d %d\n", bit_flags_check_flag(hBit_flags, i),i);
	}
	
	for (i = 0; i < 32; i++)
	{
		count++;
		printf("%d", bit_flags_check_flag(hBit_flags, i));
		
		if (count == 4)
		{
			printf(" ");
			count = 0;
		}
	}

	return 0;
}
