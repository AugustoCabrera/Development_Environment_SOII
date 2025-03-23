#pragma once

/**
 * @brief A function provided by a shared library.
 * 
 * This function is provided by a dynamic library. It takes a string as input,
 * prints a message to the standard output stream indicating the length of the string,
 * and returns the length of the string.
 * 
 * @param msg The input message, a null-terminated string.
 * @return The length of the input message string.
 * 
 * Example:
 * @code
 * char message[] = "Hello, world!";
 * int length = shared_lib_function(message); // Output: Hi! I'm a dynamic lib that receives 'Hello, world!', and return '13'
 * @endcode
 * 
*/
int shared_lib_function(char* msg);

