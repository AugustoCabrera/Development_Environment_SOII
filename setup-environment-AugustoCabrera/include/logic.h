#pragma once

/**
 * @brief Adds two numbers.
 * 
 * This function takes two integers as input and returns their sum.
 * 
 * @param first_number The first number.
 * @param second_number The second number.
 * @return The sum of first_number and second_number.
 * 
*/
int add(int first_number, int second_number);

/**
 * @brief Subtracts two numbers.
 * 
 * This function takes two integers as input and returns the result of subtracting the second number from the first.
 * 
 * @param first_number The minuend.
 * @param second_number The subtrahend.
 * @return The result of subtracting second_number from first_number.
 * 
*/
int subtract(int first_number, int second_number);

/**
 * @brief Multiplies two numbers.
 * 
 * This function takes two integers as input and returns their product.
 * 
 * @param first_number The first number.
 * @param second_number The second number.
 * @return The product of first_number and second_number.
 * 
*/
int multiply(int first_number, int second_number);

/**
 * @brief Divides two numbers.
 * 
 * This function takes two integers as input and returns the result of dividing the first number by the second.
 * If the second number is zero, it returns -1.0.
 * 
 * @param first_number The dividend.
 * @param second_number The divisor.
 * @return The result of dividing first_number by second_number. If second_number is zero, returns -1.0.
 * 
*/
double divide(int first_number, int second_number);
