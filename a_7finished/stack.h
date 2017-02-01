/**********************************************************************
	Program:	A7
	Author:	Patrick Dempsey
	Date:		10/29/16
	Time spent:	4 hours
	Purpose:   	the purpose of this program is to compare a multiple strings using a linked list
***********************************************************************/

#include <stdlib.h>
#include <stdio.h>

struct Node
{
  int data;
  struct Node* next;
}

Node;

struct Node* head;

void clear_stack();
void clear_buffer();
void print();
void push(char par);
int pop(struct Node **head);
int count();


