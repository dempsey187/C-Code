#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

//test 

	Status test_init_default_returns_nonNULL(char* buffer, int length);
//1
	Status test_pdempsey_handle_destroy_to_NULL(char* buffer, int length);
//2
	Status test_get_size_on_init_default_returns_0(char* buffer, int length);
//3
	Status test_pdempsey_get_capacity_on_init_default_5(char* buffer, int length);
//4
	Status test_pdempsey_init_c_string_returns_valid_string(char* buffer, int length);
//5
	Status test_pdempsey_get_size_on_init_c_string_returns_size(char* buffer, int length);
//6
	Status test_pdempsey_get_capacity_on_init_c_string_returns_string_value_greater_than_string(char* buffer, int length);
//7
	Status test_pdempsey_string_compare_right_v_left(char* buffer, int length);
//8
	Status test_pdempsey_string_compare_left_v_right(char* buffer, int length);
//9
	Status test_pdempsey_string_extraction_returns_success(char* buffer, int length);
//10
	Status test_pdempsey_string_extraction_reads_correct_string(char* buffer, int length);
//11
	Status test_pdempsey_string_insertion_returns_success_when_written(char* buffer, int length);
//12
	Status test_pdempsey_push_back_returns_success_when_char_is_pushed(char* buffer, int length);
//13
	Status test_pdempsey_push_back_returns_success_pushing_char_on_full_string(char* buffer, int length);
//14
	Status test_pdempsey_push_back_doubles_string_capacity_when_resized(char* buffer, int length);
//15
	Status test_pdempsey_push_back_adds_one_to_size(char* buffer, int length);
//16
	Status test_pdempsey_pop_back_returns_success_when_string_is_not_empty(char* buffer, int length);
//17
	Status test_pdempsey_pop_back_decrements_size_by_one(char* buffer, int length);
//18

	Status test_pdempsey_pop_back_returns_failure_when_empty(char* buffer, int length);
//19
	Status test_pdempsey_string_at_returns_correct_char(char* buffer, int length);
//20
	Status test_pdempsey_c_str_does_not_change_size(char* buffer, int length);
//21
	Status test_pdempsey_c_str_returns_correct_string(char* buffer, int length);
//22
	Status test_pdempsey_string_concat_edit_string(char* buffer, int length);
//23
	Status test_pdempsey_string_true_when_empty(char* buffer, int length);
//24
	Status test_pdempsey_string_returns_false_when_empty(char* buffer, int length);
//25

#endif  // UNIT_TEST_H

