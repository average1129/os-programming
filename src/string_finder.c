#include "string_finder.h"

ret_code_t extract_string(const char *in_string, char *out_string, const char start_delimiter, const char end_delimiter)
{
    if (NULL == in_string || NULL == out_string)
        return NULL_PTR;

    ret_code_t ret_value = SUCCESS;
    uint8_t start_delimiter_position = 0;
    uint8_t end_delimiter_position = 0;
    uint8_t out_index = 0;
    uint8_t string_length = strnlen(in_string, MAX_STR_LEN);

    DEBUG_PRINT("in_string = %s\nout_string = %s\nstart_delimiter= %c\t end_delimeter = %c\n",
                in_string, out_string, start_delimiter, end_delimiter);

    for (uint8_t index = 0; index < string_length; index++)
    {
        if (start_delimiter == in_string[index])
            start_delimiter_position = index;
    }
    if (start_delimiter != in_string[start_delimiter_position])
    {
        /* return START_DELIMITER_NOT_FOUND; */
        ret_value = START_DELIMITER_NOT_FOUND;
    }
    else
    {
        for (uint8_t index = start_delimiter_position; index < string_length; index++)
        {
            if (end_delimiter == in_string[index])
            {
                end_delimiter_position = index;
                break;
            }
        }

        if (end_delimiter != in_string[end_delimiter_position])
        {
            /*  return END_DELIMITER_NOT_FOUND; */
            ret_value = END_DELIMITER_NOT_FOUND;
        }
        else
        {
            for (uint8_t index = start_delimiter_position; index <= end_delimiter_position; index++)
            {
                out_string[out_index++] = in_string[index];
            }
        }
    }
    out_string[out_index] = '\0';

    DEBUG_PRINT("'$ pos = %d'\n, '; pos =%d'\nCorrect string = %s\n", start_delimiter_position, end_delimiter_position, out_string);

    return ret_value;
}