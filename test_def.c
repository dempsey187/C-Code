//Patrick Dempsey

#include <string.h>
#include <stdio.h>
#include "unit_test.h"

Status test_init_default_returns_nonNULL(char* buffer, int length) 
{
	MY_STRING hString = NULL;
	hString = my_string_init_default();
	Status status;	

	if(hString == NULL)
	{
    	strncpy(buffer, "test_pdempsey_init_default_returns_nonNULL\n"
        "my_string_init_default returns NULL", length);
    	status = failure;
  	}
	
	else
	{
	strncpy(buffer, "test_init_default_returns_nonNULL\n", length);
	status = success;

	}

	my_string_destroy(&hString);
	return status;	
}

Status test_pdempsey_handle_destroy_to_NULL(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_default();
	
	my_string_destroy(&hString);

	if ((&hString) != NULL)
	{
	strncpy(buffer, "test_pdempsey_handle_destroy_to_NULL\n"
        "handle is not NULL after string_destroy", length);
	status = failure;
	}
	
	else
	{
	strncpy(buffer, "test_pdempsey_handle_set_to_NULL_after_string_destroy\n", length);
	status = success;
	}
	
	//my_string_destroy(&hString);
	return status;
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_default();
	
	if(my_string_get_size(hString) != 0)
	{
	status = failure;
	printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
	strncpy(buffer, "test_pdempsey_get_size_on_init_default_returns_0\n"
      "Did not receive 0 from get_size after init_default\n", length);
	}
	
	else
	{
	status = success;
	strncpy(buffer, "test_get_size_on_init_default_returns_0\n", length);
	}
	
	my_string_destroy(&hString);
	return status;
}

Status test_pdempsey_get_capacity_on_init_default_5(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_c_string("test");

	if(my_string_get_capacity(hString) != 5)
	{
	status = failure;
	
	strncpy(buffer, "test_pdempsey_get_capacity_on_init_default_5\n"
	"7 was not returned\n", length);
	}

  	else
	{
	status = success;
	strncpy(buffer, "test_pdempsey_get_capacity_on_init_default_returns_5\n", length);
	}
	
	my_string_destroy(&hString);
	return status;
}

Status test_pdempsey_init_c_string_returns_valid_string(char* buffer, int length)//5
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_c_string("test this string");

	if(hString == NULL)
	{
	strncpy(buffer, "test_pdempsey_init_c_string_returns_valid_string\n"
	"my_string_init_c_string returns NULL", length);
	status = failure;
	}
	
	else
	{
	strncpy(buffer, "test_init_c_string_returns_valid_string\n", length);
	status = success;
	}

	my_string_destroy(&hString);
	return status;
}

Status test_pdempsey_get_size_on_init_c_string_returns_size(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_c_string("123456789");
	
	if(my_string_get_size(hString) != 9)
	{
	status = failure;
	strncpy(buffer, "Expected a size of 9 but got %d\n", my_string_get_size(hString));
	strncpy(buffer, "test_pdempsey_get_size_on_init_c_string_returns_size"
	"size incorrect\n", length);
	}

	else
	{
    	status = success;
    	strncpy(buffer, "test_pdempsey_get_size_on_init_c_string_returns_size was successfull\n",
      	length);
  	}

	my_string_destroy(&hString);
  	return status;
}

Status test_pdempsey_get_capacity_on_init_c_string_returns_string_value_greater_than_string(char* buffer,
    int length) 
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_c_string("test");

	if(my_string_get_capacity(hString) != 5)
	{
	status = failure;
	
	strncpy(buffer, "test_pdempsey_get_capacity_on_init_c_string_returns_string_greater"
	"my_string_get_capacity test failed\n", length);
	}

	else
	{
	status = success;
	strncpy(buffer,"test_pdempsey_get_capacity_on_init_c_string_returns_string_length_greater\n",length);
	}

	my_string_destroy(&hString);
	return status;
}

Status test_pdempsey_string_compare_right_v_left(char* buffer, int length)//8
{	
	Status status;
	MY_STRING hStringl = NULL;
	MY_STRING hStringr = NULL;

	hStringl = my_string_init_c_string("test");
	hStringr = my_string_init_c_string("testing");

	if(my_string_compare(hStringl, hStringr) <= 0)
	{
	status = failure;
	
	strncpy(buffer, "test_pdempsey_string_compare_left_v_right\n"
	"my_string_compare returned value greater than or equal to 0\n", length);
	}

	else
	{
	status = success;
	strncpy(buffer, "test_pdempsey_string_compare_on_a_and_an_less_than_0\n", length);
	}

	my_string_destroy(&hStringr);
	my_string_destroy(&hStringl);

	return status;
}

Status test_pdempsey_string_compare_left_v_right(char* buffer, int length)
{
	MY_STRING hStringr = NULL;
	MY_STRING hStringl = NULL;

	Status status;
	
	hStringl = my_string_init_c_string("testing");
	hStringr = my_string_init_c_string("test");

	if(my_string_compare(hStringl, hStringr) >= 0)
	{
	
   	strncpy(buffer, "test_pdempsey_string_compare_on_an_and_a_greater_than_0\n"
	"string_compare returned value less than or equal to 0\n", length);
	status = failure;
  	}

	else 
	{
	strncpy(buffer, "test_pdempsey_string_compare_on_an_and_a_greater_than_0\n", length);
	status = success;
	}

	my_string_destroy(&hStringr);
	my_string_destroy(&hStringl);

	return status;
}

Status test_pdempsey_string_extraction_returns_success(char* buffer, int length)//10
{
	MY_STRING hString = NULL;
	Status status;
	FILE* fp;
/*
	fp = fopen("test_file.txt", "w");
	
	if (fp == NULL)
	{
	status = failure;
	
	strncpy(buffer, "test_pdempsey_string_extraction_returns_success_on_succressful_read\n"
	"cannot open file: string_extraction could not be tested\n", length);
	}

	fputs("test this string.\n", fp);

	fclose(fp);*/
	fp = fopen("test_file.txt", "r");
	
	if (fp == NULL)
	{
	
	strncpy(buffer, "test_pdempsey_string_extraction_returns_success_on_succressful_read\n"
	"cannot open file: string_extraction could not be tested\n", length);
	status = failure;
	}

	hString = my_string_init_c_string("test this string");
	
	if (!my_string_extraction(hString, fp))
	{
	strncpy(buffer, "test_pdempsey_string_extraction_returns_success_on_succressful_read\n"
	"string_extraction returned failure\n", length);
	status = failure;
	}
	
	else
	{
	strncpy(buffer, "test_pdempsey_string_extraction_returns_success_on_succressful_read\n", 		length);
	status = success;
	}
	
	fclose(fp);
	my_string_destroy(&hString);

	return status;
}

Status test_pdempsey_string_extraction_reads_correct_string(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	FILE* fp;
	fp = fopen("test_file.txt", "w");
	
	if (fp == NULL)
	{
	
	strncpy(buffer, "test_pdempsey_string_extraction_reads_correct_string\n"
	"cannot open test file string_extraction could not be tested\n", length);
	status = failure;
	}

	fputs("test this string\n", fp);
	fclose(fp);
	fp = fopen("test_file.txt", "r");

	if (fp == NULL)
	{
	strncpy(buffer, "test_pdempsey_string_extraction_reads_correct_string\n"
	"cannot open file: string_extraction could not be tested\n", length);
	status = failure;
 	}
	
	hString = my_string_init_default();
	my_string_extraction(hString, fp);

	if (strcmp("test", my_string_c_str(hString)) != 0)
	{
	strncpy(buffer, "test_pdempsey_string_extraction_reads_correct_string\n"
	"string_extraction failed\n", length);
	status = failure;
	}
	
	else
	{
	strncpy(buffer, "success test_pdempsey_string_extraction_reads_correct_string\n", length);
	status = success;
	}

	fclose(fp);
	my_string_destroy(&hString);
	
	return status;
}

Status test_pdempsey_string_insertion_returns_success_when_written(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	FILE* fp;
	fp = fopen("test_file.txt", "test");
	fputs(' ', fp);
	fclose(fp);
	fp = fopen("test_file.txt", "string");

	if (fp == NULL)
	{
	
	strncpy(buffer, "test_pdempsey_string_insertion_returns_success_when_written\n"
	"cannot open file: string_extraction could not be tested\n", length);
	status = failure;
	}

	hString = my_string_init_c_string("test this string");

	if (!my_string_insertion(hString, fp))
	{
	status = failure;
	strncpy(buffer, "test_pdempsey_string_insertion_returns_success_on_successful_write\n"
	"string_extraction returned failure\n", length);
	}

	else
	{
	status = success;
	strncpy(buffer, "test_pdempsey_string_insertion_returns_success_when_written\n", length);
	}

	fclose(fp);
	my_string_destroy(&hString);

	return status;
}

Status test_pdempsey_push_back_returns_success_when_char_is_pushed(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_default();
	
	if (!my_string_push_back(hString, 'T'))
	{
	status = failure;
	strncpy(buffer, "test_pdempsey_push_back_returns_success_when_char_is_pushed\n"
	"push_back returned failure\n", length);
	}
	
	else
	{
	status = success;
	strncpy(buffer, "test_pdempsey_push_back_returns_success_when_char_is_pushed\n",
	length);
	}

	my_string_destroy(&hString);
	
	return status;
}

Status test_pdempsey_push_back_returns_success_pushing_char_on_full_string(char* buffer, int length) 
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_c_string("test this string");

	if (!my_string_push_back(hString, '.'))
	{
	status = failure;
	strncpy(buffer, "test_pdempsey_push_back_returns_success_pushing_char_on_empty_default_string\n"
      "push_back returned failure\n", length);
	}

	else
	{
	status = success;
	strncpy(buffer, "test_pdempsey_push_back_returns_success_pushing_char_on_empty_default_string\n",
      length);
	}

  my_string_destroy(&hString);
  return status;

}

Status test_pdempsey_push_back_doubles_string_capacity_when_resized(char* buffer, int length)
{//15
	MY_STRING hString = NULL;
	Status status;
	int cap;
	
	hString = my_string_init_c_string("Double the capcity when the string is to large");
	
	cap = my_string_get_capacity(hString);
	my_string_push_back(hString, '.');

	if (my_string_get_capacity(hString) != cap * 2)
	{
	
	strncpy(buffer, "test_pdempsey_push_back_doubles_string_capacity_when_resized\n"
	"push_back did not double string capacity\n", length);
	status = failure;
	}

	else
	{
	strncpy(buffer, "test_pdempsey_push_back_doubles_string_capacity_when_resized\n", length);
	status = success;
	}

  	my_string_destroy(&hString);
}

Status test_pdempsey_push_back_adds_one_to_size(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	int init_size;
	
	hString = my_string_init_c_string("push back on string");
	init_size = my_string_get_size(hString);
	my_string_push_back(hString, '.');
	
	if (my_string_get_size(hString) != init_size + 1)
	{
	
	strncpy(buffer, "test_pdempsey_push_back_increments_size_by_one\n"
      "push_back did not double string capacity\n", length);
	status = failure;
	}

	else
	{
	
	strncpy(buffer, "test_pdempsey_push_back_increments_size_by_one\n", length);
	status = success;
	}

	my_string_destroy(&hString);
	return status;
}

Status test_pdempsey_pop_back_returns_success_when_string_is_not_empty(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_c_string("test this string");
	
	if (!my_string_pop_back(hString))
	{
	strncpy(buffer, "test_pdempsey_pop_back_returns_success_when_string_is_not_empty\n"
	"pop_back returned failure\n", length);
	status = failure;
	}
	
	else
	{
	strncpy(buffer, "test_pdempsey_pop_back_returns_success_when_string_is_not_empty\n",
	length);
	status = success;
	}

	my_string_destroy(&hString);
	return status;
}

Status test_pdempsey_pop_back_returns_failure_when_empty(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_default();
  
	if (my_string_pop_back(hString) == NULL)
	{
	strncpy(buffer, "test_pdempsey_pop_back_returns_failure_when_string_is_empty\n"
	"pop_back returned success test passed\n", length);
	status = success;
	}
	
	else
	{
	status = failure;
	strncpy(buffer, "test_pdempsey_pop_back_returns_failure_on_empty_string test failed\n", length);
	}

	my_string_destroy(&hString);
	return status;
}

Status test_pdempsey_pop_back_decrements_size_by_one(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	int init_size;

	hString = my_string_init_c_string("Test this string");
	init_size = my_string_get_size(hString);
	my_string_pop_back(hString);
	
	if (my_string_get_size(hString) != init_size - 1)
	{

	strncpy(buffer, "test_pdempsey_pop_back_decrements_size_by_one\n"
	"pop_back did not decrement size by one\n", length);
	status = failure;
	}

	else
	{
	status = success;
	strncpy(buffer, "test_pdempsey_pop_back_decrements_size_by_one\n", length);
	}

	my_string_destroy(&hString);
	return status;
}

Status test_pdempsey_string_at_returns_correct_char(char* buffer, int length)//20
{	
	Status status;
	MY_STRING hString = NULL;
	
	char* pChar = NULL;
	hString = my_string_init_c_string("test this string");
	pChar = my_string_at(hString, 3); //sends the function a string and index to check

	if (pChar == NULL)
	{
	strncpy(buffer, "test_pdempsey_string_at_returns_correct_char\n"
	"string_at returned NULL on valid index\n", length);
	status = failure;
	}

	else if (*pChar != 't')
	{
	
	strncpy(buffer, "test_pdempsey_string_at_returns_valid_character_pointer\n"
	"incorect char returned\n", length);
	status = failure;
	}

	else
	{
	status = success;
	strncpy(buffer, "test_pdempsey_string_at_returns_valid_character_pointer\n", length);
	}
	
	my_string_destroy(&hString);
	return status;
}

Status test_pdempsey_c_str_does_not_change_size(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	int string_size;
	
	hString = my_string_init_c_string("Test this string right now");
	string_size = my_string_get_size(hString);
	my_string_c_str(hString);
	
	if (my_string_get_size(hString) != string_size)
	{
	
	strncpy(buffer, "test_pdempsey_c_str_does_not_change_string_size\n"
	"c_str changed string size\n", length);
	status = failure;
	}

	else
	{
	status = success;
	strncpy(buffer, "test_pdempsey_c_str_does_not_change_size\n", length);
	}

	my_string_destroy(&hString);
	return status;
}

Status test_pdempsey_c_str_returns_correct_string(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_c_string("Test this string.");

	if (strcmp("Test this string.", my_string_c_str(hString)))
	{
	strncpy(buffer, "test_pdempsey_c_str_returns_correct_string\n"
	"c_str returned incorrect string\n", length);
	status = failure;
	}

	else
	{
	strncpy(buffer, "test__c_str_returns_correct_string\n", length);
	status = success;
	}

	my_string_destroy(&hString);
	return status;
}

Status test_pdempsey_string_concat_edit_string(char* buffer, int length)
{
	MY_STRING hStringr = NULL;
	MY_STRING hStringl = NULL;
	Status status;
	int init_size;
	
	hStringr= my_string_init_c_string("Test this ");
	hStringl = my_string_init_c_string("string.");

	init_size = my_string_get_size(hStringr);
	my_string_concat(hStringr, hStringl);

	if (my_string_get_size(hStringr) != init_size)
	{
	
	strncpy(buffer, "test function does not change size.\n", length);
	status = failure;
	}
	
	else
	{
	strncpy(buffer, "test_pdempsey_c_str_does_not_change_string_size\n", length);
	status = success;
	}

	my_string_destroy(&hStringr);
	my_string_destroy(&hStringl);
	return status;

}

Status test_pdempsey_string_true_when_empty(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_default();
	
	Boolean empty;
	empty = my_string_empty(hString);	

	if (empty == FALSE)
	{
	status = failure;
	strncpy(buffer, "test_pdempsey_string_empty_returns_true_when_empty\n"
	"string_empty returned false on empty string\n", length);
	}

  	else if (empty == TRUE)
	{
	status = success;
	strncpy(buffer, "test_pdempsey_string_empty_returns_true_when_empty\n", length);
	}
	
	else 
	{
	strncpy(buffer, "test failed unknown error", length);
	}

	my_string_destroy(&hString);
	return status;
}

Status test_pdempsey_string_returns_false_when_empty(char* buffer, int length)//25
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_c_string("test this string");
	
	Boolean empty;	

	empty = my_string_empty(hString);

	if (empty == TRUE)  //if return value is true
	{
	strncpy(buffer, "test_pdempsey_string_empty_returns_false_when_empty\n"
	"string_empty returned a false positive.\n", length);
	status = failure;
	}

	else if (empty == FALSE)
	{
	
	strncpy(buffer, "test_pdempsey_string_empty_returns_false_when_empty\n", length);
	status = success;
	}

	else 
	{
	strncpy(buffer, "test failed error unknown", length);
	}
	
	my_string_destroy(&hString);
	return status;
}

