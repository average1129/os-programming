/**
 * @file string_finder.h
 * @author Bharath G (Bharath.g@ltts.com)
 * @brief Functions related to String finder
 * @version 0.1
 * @date 2021-05-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __STRING_FINDER_H__
#define __STRING_FINDER_H__

#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

#define DEBUG_ENABLE    (0)     /**< Enable or Disable Debug prints */
#define MAX_STR_LEN     (256)   /**< Maximum String length */
#define START_DELIMITER ('$')   /**< Start Delimiter Charcater */
#define END_DELIMITER   (';')   /**< End Delimiter Charcater */

#if DEBUG_ENABLE
    #define DEBUG_PRINT printf
#else
    #define DEBUG_PRINT
#endif  /* DEBUG_ENABLE */

/**
 * @brief Error values for String finder operations
 * 
 */
typedef enum ret_code
{
    DELIMITER_NOT_FOUND = -1,   /**< Error code for delimiter not found */
    SUCCESS,                    /**< Value for Sucess */
    NULL_PTR,                   /**< Error code for Null pointer */
    START_DELIMITER_NOT_FOUND,  /**< Error code for Start delimiter not found */
    END_DELIMITER_NOT_FOUND     /**< Error code for End delimiter not found */
}ret_code_t;


/**
 * @brief Function to extract string between start and end delimeters
 * 
 * @param[in] in_string Pointer to input string
 * @param[out] out_string Pointer to output string
 * @param[in] start_delimiter Start delimiter character
 * @param[in] end_delimiter End delimiter character
 * @return ret_code_t returns \p SUCCESS if start and end delimeters are found, \p ret_code_t other wise
 * @note The function assumes that enough memory is available in outstring to store the extracted string
 */
ret_code_t extract_string(const char *in_string, char *out_string, const char start_delimiter, const char end_delimiter);

#endif /* __STRING_FINDER_H__ */