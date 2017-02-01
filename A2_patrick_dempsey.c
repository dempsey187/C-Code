/***********************************************************
	Author: Patrick Dempsey
	Date: 9/13/2016
	Effort: 1 hour
	Purpose: use the bit operator << to print out the largest
	number possible at the given number of bits
***********************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	
int	x=1;
int y =0;
int	num=0;
int i;
int shift=1;

	for(i=0; i<63; i++)
	{

		while (y<2)
		{
		printf("%u:  ", num);
	
		printf("%u\n", x);
	
		x=x<<1;

		num+=1;
		
			if (x<1)
			{ y+=1;
			}
		}
	}
	return 0;
}
