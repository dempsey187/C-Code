#include <stdio.h>

//Basic funstion i made to practice with stacks
//Patrick Dempsey

void main ()
{
	int data [5], top;
	int ch=0;
	int temp=0;
	while(ch!=4)
	{
		printf("\n ==================================");
		printf("\n 1. Push");
		printf("\n 2. Pop");
		printf("\n 3. Peek");
		printf("\n 4. Exit");
		printf("Enter your choice...");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1 : if (top==4) 
				printf ("\n\n Stack is full");
				
				else
				{
					printf("\n\n Enter data;");
					scanf("%d", &temp);
					data[++top]= temp;
				}
			break;
				
			case 2 : if (top==-1)
				printf("stack is empty");
				
				else
				{
				printf("Pop Element : %d", data [top]);
				top--;	
				}
			break;
			
			case 3 : if (top==-1)
				printf("stack is empty");
				
				else
				{
				printf("Peek Element : %d", data [top]);
				
				}
			break;
					
			defualt : printf("\n Not a good choice");
			
			break;
		}
	}
}
