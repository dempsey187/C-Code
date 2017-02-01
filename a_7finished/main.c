/**********************************************************************
	Program:	A7
	Author:	Patrick Dempsey
	Date:		10/29/16
	Time spent:	4 hours
	Purpose:   	the purpose of this program is to compare a multiple strings using a linked list
***********************************************************************/


#include <stdlib.h>
#include <stdio.h>
#include "stack.c"

void main()
{
	int num = 0; 
	int i = 0;
	int empty;
	int len = 0;
	int j = 0;
	int x = 0;
	char par;
	
	head = NULL;
	
	scanf("%d", &num);
		clear_buffer();
	
	if (num>0)
		
		{
			for (j; j<num; j++)
			{	
				scanf("%c", &par); 
			
				while (par != '\n')
				{
				
					if (par == '(' || par == '['|| par== '{')
					{
					push(par);
					}
					else 
					{
					empty =  pop(&head);
					}
					scanf("%c", &par);	
					
				}
			
				if (empty == 1)
				{ printf("No\n");
				}
				else if (count() == 0)
				{	
				printf("Yes\n");
				}	
			
				else
				{
					printf("No\n");
				}
			print();
			clear_stack();
			empty = 0;
			}
			
		}
}


