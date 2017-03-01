
#include <stdlib.h>
#include "my_string.h"
#include <stdio.h>
#include <ctype.h>

struct string
{
	int size;
	int capacity;
	char* data;
};


typedef struct string My_string;


//void my_string_destroy(MY_STRING*phMy_string);

MY_STRING my_string_init_default(void)
{
	My_string* string;
	string = (My_string*) malloc(sizeof(My_string));
	if(string == NULL)
	{
		free(string);
		exit(0);
	}
	string->capacity = 7;
	string->size = 0;
	string->data = (char*) malloc(sizeof(char)*string->capacity);
	if(string->data == NULL)
	{
		free(string->data);
		exit(0);
	}
	return (MY_STRING) string;
}

void my_string_destroy(Item* phMy_string)
{
  My_string* pMy_string = (My_string*) *phMy_string;
  free(pMy_string -> data);
  free(pMy_string);
  *phMy_string = NULL;
}


MY_STRING my_string_init_c_string(const char* c_string)
{
	
		My_string* string = NULL;
	
	string = (My_string*) malloc(sizeof(My_string));
	if(string == NULL)
	{
		free(string);
		exit(0);
	}
	
	int i=0;
	while(c_string[i] != '\0')
		i++;

	string->capacity = i+1;
	string->size = i;
	string->data = (char*) malloc(sizeof(char)*string->capacity);
	
	if(string->data == NULL)
	{
		free(string->data);
		exit(0);
	}
	i=0;
	
	while(i<string->size)
	{			
		string->data[i] = c_string[i];
		i++;
	}
	return (MY_STRING) string;
}


int my_string_get_capacity(MY_STRING hMy_string)
{
	My_string* temp = (My_string*) hMy_string;
	return temp->capacity;
}

int my_string_get_size(MY_STRING hMy_string)
{
	My_string* temp = (My_string*) hMy_string;
	return temp->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
	int comp = 0;	
	int rSize = 0;
	int lSize = 0;
	int i = 0;
	
	My_string* left = (My_string*) hLeft_string;
	My_string* right = (My_string*) hRight_string;

	rSize = my_string_get_size(hRight_string);
	lSize = my_string_get_size(hLeft_string);

	while(i < left->size && i < right->size)
	{
		if(left->data[i] > right->data[i])
			return 1;
		if(left->data[i] < right->data[i])
			return -1;
		if(left->data[i] == right->data[i])
			i++;
	}
		
	if (rSize == lSize)			
	{
		comp = 0;
	}
	
	else if (rSize < lSize)
	{
		comp = -1;
	}
	
	else
	{
		comp = 1;
	}		
		
	return comp;
}



Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
	My_string * StringIn = (My_string*) hMy_string;
	int count=0;
	char c;

	while(fscanf(fp, "%c", &c)!=-1)// loop stop at EOF
	{
	    	if(c==' ' || c=='\n' )
		{
			if(count!=0)
			{
	          	  ungetc(c, fp);
			  break;
	       		}
		}
		
		else
		{
			StringIn->data[count] = c;
			count++;
       			int i = 0;
			if (count>= StringIn->capacity) 
			{
				char* temp = malloc(sizeof(int)*2*StringIn->capacity);
				if (temp == NULL)
				{
					return failure;
				}
				
				for (i = 0; i < StringIn->size; i++) 
				{
					temp[i] = StringIn->data[i];
				}	
				
				free(StringIn->data);
				StringIn->data=temp; 
				StringIn->capacity *= 2;
			}

		}	
    	}
	
	StringIn->size = count;

	if(count==0)
		return failure;
	else
		return success;
		
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
	int i = 0;
	
	My_string * StringIn = (My_string*) hMy_string;

	if (hMy_string == NULL)

		return failure;
	
	for (i=0; i < StringIn -> size; i++)
		 
		{
	
		fputc ( StringIn->data[i], fp );
	
		}
		
		return success;
}

Status my_string_push_back(MY_STRING hMy_string, char item)
{
	My_string* pstring = (My_string*) hMy_string;
	char* temp;
	int i;

	if (pstring->size>= pstring->capacity)
	{
		temp = malloc(sizeof(char)*2*pstring->capacity);
		if (temp == NULL)
		{
			return failure;
		}
		for (i = 0; i < pstring->size; i++) 
		{
			temp[i] = pstring->data[i];
		}	
		free(pstring->data);
		pstring->data=temp; 
		pstring->capacity *= 2;
	}

	pstring->data[pstring->size] = item;
	pstring->size++;

	return success;
}

Status my_string_pop_back(MY_STRING hMy_string)
{
	My_string* pstring = (My_string*)hMy_string;
	if (pstring->size <= 0)
	{
		return failure;
	}
	pstring->size--;
	return success;
}

char* my_string_at(MY_STRING hMy_string, int index)
{
	
	My_string* pstring = (My_string*)hMy_string;
	if (index > my_string_get_size(hMy_string))
	{
		return NULL;
	}	
	
	else
	{
	
	return &pstring->data[index];
	
	}
}

char* my_string_c_str(MY_STRING hMy_string)
{
	My_string* pstring = (My_string*)hMy_string;
	char* temp;
	int i = 0;

	if (my_string_get_size(hMy_string)+1 >= pstring->capacity) 
	{
		temp = malloc(sizeof(char)*2*pstring->capacity);
		if (temp == NULL)
		{
			return failure;
		}
		for (i = 0; i < pstring->size; i++)
		{
			temp[i] = pstring->data[i];
		}	
		free(pstring->data);
		pstring -> data = temp; 
		pstring -> capacity *= 2;
	}


	pstring->data [pstring->size] = '\0';
	return pstring->data;

}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{	
	My_string* pA = (My_string*)hAppend;
	My_string* pR = (My_string*)hResult;
	int i = 0;	

	
	if(pA == NULL)
		return failure;

	for (i=0; i <= pA -> size && pR -> size; i++)
	{
		my_string_push_back(pR, pA->data[i]);		
	}

	return success;
}

Boolean my_string_empty(MY_STRING hMy_string)
{	
	My_string* pstring = (My_string*)hMy_string;

	if (pstring->size == 0)	
	{
	return TRUE;
	}
	
	else
	{	
	return FALSE;
	}
}





Status my_string_assignment(Item* pLeft, Item Right) 
{
  My_string* pMy_string_L = NULL;
  My_string* pMy_string_R = Right;
  int i;
  char* ptr_Data = NULL;
  
	if (*pLeft == NULL)
	{
  	pMy_string_L = (My_string*) malloc(sizeof(My_string));
	ptr_Data = (char*) malloc((pMy_string_R->capacity) * sizeof(char));
    
		if (pMy_string_L != NULL && ptr_Data != NULL) 
		{
    		pMy_string_L->size = pMy_string_R->size;
    		pMy_string_L->capacity = pMy_string_R->capacity;
      
			for (i = 0; i < pMy_string_R->size; ++i) 
	 		{
        		ptr_Data[i] = pMy_string_R->data[i];
      			}
    	
		pMy_string_L->data = ptr_Data;
      		*pLeft = pMy_string_L;
    		}
	
		else 
		{
        	free(pMy_string_L);
		free(ptr_Data);
        	pLeft = NULL;
        	return failure;
		}
	}
	
	else
	{
	pMy_string_L = *pLeft;
    
		if (pMy_string_L->capacity < pMy_string_R->size)
		{
	    	ptr_Data = (char*) malloc((pMy_string_R->capacity) * sizeof(char));
    
			if (ptr_Data == NULL)
			{
    			return failure;
	    		}
    
		free(&pMy_string_L->data);
    		pMy_string_L->data = ptr_Data;
    		pMy_string_L->capacity = pMy_string_R->capacity;
    		}
    
	pMy_string_L->size = pMy_string_R->size;
    
		for (i = 0; i < pMy_string_R->size; ++i) 
		{
    		pMy_string_L->data[i] = pMy_string_R->data[i];
    		}
    
	*pLeft = pMy_string_L;
  	return success;
	}
return failure;
}


Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess)
{
	My_string* pNew_key = (My_string*)new_key;
	My_string* pWord = (My_string*)word;
	guess = tolower (guess);
	int i;

	my_string_assignment((Item*)&new_key, (Item)current_word_family);

	for (i = 0; i < pWord->size; i++) 
	{
		if (tolower(pWord->data[i]) == guess) 
		{
			pNew_key->data[i] = guess;
		}
	}

	return success;
}























