/***********************************************************
Author: Patrick Dempsey
Date: 09/22/16
Effort: i didnt know where to start on this one 
Purpose: to create a program that is similar to day 4
// but print the numbers out as an array
***********************************************************/

#include<stdio.h>

void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int  flag_holder[], int flag_position);
void display_32_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);

int main(int argc, char* argv[])
{
	unsigned int flag_holder[5] = { 0 };
	//Set the first integer to zero and all others to zero by default.

	set_flag(flag_holder, 3);
	set_flag(flag_holder, 16);
	set_flag(flag_holder, 31);
	set_flag(flag_holder, 87);

	display_flags(flag_holder, 5);
	printf("\n\n");

	unset_flag(flag_holder, 31);
	unset_flag(flag_holder, 3);
	set_flag(flag_holder, 99);
	set_flag(flag_holder, 100);

	display_flags(flag_holder, 5);
	return 0;
}

void set_flag(unsigned int flag_holder[], int flag_position)
	{
		int i=0;	
		
		while (flag_position>31)
		{
			flag_position = flag_position - 32;
					i++;
		}

		flag_holder[i] |= (1 << flag_position);

		return;
	}

void unset_flag(unsigned int flag_holder[], int flag_position)
	{
		*flag_holder &= ~(1 << flag_position);
		return;
	}

int check_flag(unsigned int  flag_holder[], int flag_position)
	{	
		int i, bit=1;
			
			int bit_flag = flag_holder[0];
			
			bit = (bit_flag>> flag_position) & 1;
			
			return bit;
	}

void display_32_flags_as_array(unsigned int flag_holder)
	{
		int i=0;
		
		unsigned int new_flag [] = {flag_holder};
			
		for (i = 0; i <= 31; i++)
		{	
			if (i % 4 == 0) 
				{
				printf(" ");
				}
			printf("%d", check_flag(new_flag ,i )); 
			
		}
		
	printf("\n");
	return;
	
	}

void display_flags(unsigned int flag_holder[], int size)
	{
		int i = 0; 
		
		for(i; i<size; i++)
			{
				unsigned int flag_holder_bit = flag_holder[i];
				display_32_flags_as_array(flag_holder_bit); // takes the elements in flag_holder and makes them intergers
			}
					
		return;
	}
