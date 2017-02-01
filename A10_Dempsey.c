/***********************************************************
Author: Patrick Dempsey
Date: 11/24/2016
Effort: 1 hour 
Purpose: This program will ask the user how large of an array
they want to create. Then it sill create an array of that size made 
from random intergers.  It will then print that array and 
sort print a sorted version of the array from least to greatestss.
***********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void sort(int low, int high);
void merge(int low, int mid, int high);
void print(int array[], int input);
int array [200000] = {};  
int temp [200000] = {};  

int main(int argc, char* argv[]) 
{ 
	int i = 1;
	int r;
	int input = 0; //size of array requested by user
	printf("Please enter the size of the array you wish to create and sort.\n");
	scanf("%d", &input);
	printf("\n");
	srand(time(NULL)); //seeding random number generator with time
	
	for (i; i <= input; i++)//generate random list of intergers
	{	
		r = rand() % 99; //the greatest number generated will be 99
		array[i] = r;
	}   
   
	printf("List prior to sorting.\n");
	print(array, input);
	
	sort(0, input); //calls sort 

	printf("List after sorting.\n");
	print(array, input);
   
  return 0;
}
//this function breaks the array into 3 parts and compares them and swapps them if needed.
//then it takes the sorted array temp and sets it to the original.
void merge(int low, int mid, int high) 
{
   int list1 = low;
   int list2 = mid + 1;
   int i= low; //creating two lists that will be sorted and merged

   for(i; list1 <= mid && list2 <= high; i++) 
   {
      if(array[list1] <= array[list2])
         temp[i] = array[list1++];
      else
         temp[i] = array[list2++];
   }
   
   while(list1 <= mid)    
      temp[i++] = array[list1++]; 

   while(list2 <= high)   
      temp[i++] = array[list2++];

   for(i = low; i <= high; i++)
      array[i] = temp[i];
}

void sort(int low, int high) //recives 0 for beginning(low) of array and input being size of array(high)
{
   int mid;
   
   if(low < high)
   {
      mid = (low + high) / 2;
      sort(low, mid); //recursivley calls sort to find middle
      sort(mid+1, high);
      merge(low, mid, high); //calls merge sending 3 ints
   } 
   
   else
   { 
    return;
   }   
}

void print(int array[], int input) 
{	
	int i = 1;

	for (i; i <= input; i++)	//print the array
	{
	printf("%d\n", array[i]);
	}
	
	printf("\n");
}

