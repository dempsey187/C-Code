#include "my_string.h"
#include <stdlib.h>

struct string{
	int size;
	int capacity;
	char* data;
};


typedef struct string My_string;

//void MY_STRING mystring_init_default(void);
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

void my_string_destroy(MY_STRING* phMy_string)
{
	My_string** string = (My_string**) phMy_string;
	//free((*phMy_string)->data);
	free((*string)->data);
	free((*string));
	string = NULL;
	return;
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

	if (pstring->size>= pstring->capacity) {
		temp = malloc(sizeof(char)*2*pstring->capacity);
		if (temp == NULL)
		{
			return failure;
		}
		for (i = 0; i < pstring->size; i++) {
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
















