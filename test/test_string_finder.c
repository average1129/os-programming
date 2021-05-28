/**
 * @file test_string_finder.c
 * @author Bharath.G ()
 * @brief 
 * @version 0.1
 * @date 2021-05-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "string_finder.h"
#include "unity.h"
/**
 * @brief Set the Up object
 * Required by the unity test framework
 */
void setUp() {}

/**
 * @brief Release the objects that are setup for tests
 * Required by the unity test framework
 */
void tearDown() {}

/**
 * @brief Test null inputs for strings
 * 
 */
void test_null_inputs(void)
{
    char* ouput_string = " ";
    char* test_string = " ";

    TEST_ASSERT_EQUAL(NULL_PTR, extract_string(NULL, ouput_string, START_DELIMITER, END_DELIMITER));
    TEST_ASSERT_EQUAL(NULL_PTR, extract_string(test_string, NULL, START_DELIMITER, END_DELIMITER));
    TEST_ASSERT_EQUAL(NULL_PTR, extract_string(NULL, NULL, START_DELIMITER, END_DELIMITER));
}

/**
 * @brief Test strings without delimiters
 * 
 */
void test_strings_without_delimiters(void)
{
  char test_string1[MAX_STR_LEN] = "String with only $ as delimiter";
  char test_string2[MAX_STR_LEN] = "String with only ; as delimiter";
  char test_string3[MAX_STR_LEN] = "String with no delimiters";
  char ouput_string1[MAX_STR_LEN];
  char ouput_string2[MAX_STR_LEN];
  char ouput_string3[MAX_STR_LEN];

  TEST_ASSERT_EQUAL(END_DELIMITER_NOT_FOUND, extract_string(test_string1, ouput_string1, START_DELIMITER, END_DELIMITER));
  TEST_ASSERT_EQUAL(START_DELIMITER_NOT_FOUND, extract_string(test_string2, ouput_string2, START_DELIMITER, END_DELIMITER));
  TEST_ASSERT_EQUAL(START_DELIMITER_NOT_FOUND, extract_string(test_string3, ouput_string3, START_DELIMITER, END_DELIMITER));    
}

/**
 * @brief Test strings with delimiters
 * 
 */
void test_strings_with_delimiters(void)
{
  char test_string1[MAX_STR_LEN] = "Grabage$Welcome to LTTS;ignore";
  char test_string2[MAX_STR_LEN] = "Hello$This is $$an example #2 string;And filled with words";
  char test_string3[MAX_STR_LEN] = "Program to read from file and $use the read data; as string";
  char ouput_string1[MAX_STR_LEN];
  char ouput_string2[MAX_STR_LEN];
  char ouput_string3[MAX_STR_LEN];

  TEST_ASSERT_EQUAL(SUCCESS, extract_string(test_string1, ouput_string1, START_DELIMITER, END_DELIMITER));
  TEST_ASSERT_EQUAL_STRING("$Welcome to LTTS;", ouput_string1);

  TEST_ASSERT_EQUAL(SUCCESS, extract_string(test_string2, ouput_string2, START_DELIMITER, END_DELIMITER));
  TEST_ASSERT_EQUAL_STRING("$an example #2 string;", ouput_string2);

  TEST_ASSERT_EQUAL(SUCCESS, extract_string(test_string3, ouput_string3, START_DELIMITER, END_DELIMITER));
  TEST_ASSERT_EQUAL_STRING("$use the read data;", ouput_string3);
}


int test_main(void)
{
  /* Initiate the Unity Test Framework */
  UNITY_BEGIN();

  /* Run Test functions */
  RUN_TEST(test_null_inputs);
  RUN_TEST(test_strings_without_delimiters);
  RUN_TEST(test_strings_with_delimiters);
  /* Close the Unity Test Framework */
  return UNITY_END();
}
