/***********************************************************
	Author: Patrick Dempsey
	Date: 9/20/16
	Effort: <2 hours>
	Purpose: <to use pointers to flip the string>
***********************************************************/

#include <stdio.h>
#include <string.h>

char* reverse(char* word);

int main(int argc, char* argv[])
{
	char word[] = "Happy Birthday!";

	printf("%s\n", word);
	reverse(word);
	printf("%s\n", word);
	printf("%s\n", reverse(word));
	printf("%s\n", word);
	return 0;
}

char* reverse(char* word)
{	
	int i=0;
	int z=0;
	int skip = 1;
	int len=0;
	char revword=0;  

		for (len = 0; word[len] != '\0'; len++)
		{	
		}
		
		int halfLen=len/2;
			
		for(z=0; z<halfLen; z++)
			{	
				revword = word[z];
       	 		word[z] = word[len-1 - z];
       			word[len-1 - z] = revword;
   			   			
			}
		 		return word ;
}



			
	
		 
		
	

