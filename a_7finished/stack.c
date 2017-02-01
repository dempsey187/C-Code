/**********************************************************************
	Program:	A7
	Author:	Patrick Dempsey
	Date:		10/29/16
	Time spent:	4 hours
	Purpose:   	the purpose of this program is to compare a multiple strings using a linked list
***********************************************************************/


#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void push(char par)
{	
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=par;
	temp->next=head;
	head=temp;
}

int pop(struct Node **head)
{
	struct Node* temp = *head;    
	int empty = 0;
	if (*head == NULL)
    { empty = 1;
	}
	if (temp != NULL) 
	{
       *head = temp->next;    
       temp->next = NULL;     
    }
    return empty;
}

int count()
{		int z=0;

	struct Node* temp = head;

	while(temp!=NULL)
	{
	temp->data;
	temp=temp->next;
	z++;
	}
	return z;
}

void print()
{
	struct Node* temp = head;
	printf("List is:");

	while(temp!=NULL)
	{
	printf("%c  ",temp->data);
	temp=temp->next;
	}
	printf("\n");
}


void clear_buffer ()
{
	char c;
	scanf("%c", &c);
	
	while( c != '\n')
	{
	scanf("%c", &c);
	}
}

void clear_stack ()
{
   struct Node* temp = head;
   
   while(head != NULL)
   {
	temp=head;
	head=head->next;
	free(temp);			
	}
   
}

