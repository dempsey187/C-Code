/**********************************************************************
	Program:	A8 Palindrome
	Author:	Patrick Dempsey
	Date:		11/24/2016
	Time spent:	2hours
	Purpose:   	program takes in a string and checks to see if it is a palindrome
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_string.h"
#include <string.h>
 
int is_palindrome(char my_string[]);
//Status my_string_get_line(MY_STRING hMy_string, File* fp);
char reverse(char my_string);
void upper(char my_string[]);
char alpha(char my_string);

void main()
{
	char input;
//	My_string* pstring = (My_string*)hMy_string;
	int i = 0;
	char pstring [2000] = {};
	//Status my_string_get_line(MY_STRING hMy_string, File* fp);

//for (i; i<4; i++)
			{
				scanf("%c", &input); 
				pstring[i] = input;
				
				while (input != '\n')
				{	i++;
					scanf("%c", &input);
					pstring[i] = input;	
				}
			}
			//print();
			
	upper(pstring);
	
//	if (is_palindrome(pstring)  == 1)
//	printf("Yes.");
//	else
//	printf("No.");
}

void upper(char my_string [])
{	char up_string[2000] = {};
	int i = 0;
	int x = 0;
	for (i = 0, x = strlen(my_string); i < x; i++)
 	{
	up_string[i] =	toupper(my_string[x]);
	}
	is_palindrome (up_string);
}

int is_palindrome(char my_string [])
{	
	int pal;
	int i = 0;
	int l = 0;
 	int r = strlen(my_string) - 1 ;
	// int r = my_string_get_size(my_string) - 1;
//	upper(my_string);
	
	
	while (r > l)
    {
        if (my_string[l++] != my_string[r--])
        {
            printf("%s is Not Palindrome\n", my_string);
            return 0;
        }
    }
	printf("%s yes", my_string);
	return 1;
}



