/**********************************************************************
	Program:	Assignment 6
	Author:	Patrick Dempsey
	Date:		10/19/16
	Time spent:	longest time spent so far 3 hours
	Purpose:   	the purpose of this assignment is to reverse a linked list using the pointer to the head node.
	Using the head node address allows me to reorder the list without creating another list.
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node, *Node_Ptr;
typedef int Item;

struct node 
{ 
		Item data; 
		Node_Ptr next; 
}; 
//declare your function here. 
void reverse (struct node **);


int main(int argc, char* argv[])
{
	Node_Ptr head = NULL;
	int i;
	Node_Ptr temp; //set up a test list with values 9->8->7->...->0 
	for (i = 0; i < 10; i++)
	{
		temp = (Node_Ptr)malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("out of memory\n");
			exit(1);
		}
		temp->data = i;
		temp->next = head; 
		head = temp;
	}
	
	//call your function to reverse the list (should work for any list given the head node). 
	 
	reverse (&head);

	//print the reversed list. 
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	 
	}
//reverse (head);
	return 0;
}

void reverse (struct node **head)
{	
struct node *temp, *prev, *next;
 
    temp = prev = next = *head;
    temp = temp->next->next;
    prev = prev->next;
    next->next = NULL;
    prev->next = next;
 
    while (temp != NULL)
    {
        next = prev;
        prev = temp;
        temp = temp->next;
        prev->next = next;
    }
	
	*head = prev;
	
	
}	
