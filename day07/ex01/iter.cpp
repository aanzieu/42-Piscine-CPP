/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 09:40:00 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/11 15:17:48 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>


template <typename T >
void	print(T &data)
{
	std::cout << data << std::endl;
}

template <typename T>
void	iter(T *addr, size_t length, void (*func)(T &))
{
	size_t i = -1;
	while (++i < length)
		(*func)(addr[i]);
}

int main( void )
{
	int tab[] = { 0, 1, 2, 3, 4 };
	int 	        int_test[] = { 1, 12, 123, 1234, 12345, 123456, 1234567, 12345678 };
	double 	        double_test[] = { 1.01, 1.21, 12345.67, 123456.78, 1234567.89, 12345678.90456789415654 };
	std::string	    string_test[] = { "TOTO", "tata", "TITI", "Flot", "Pourt" };
	char	        array_test[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G' };

    // INT TEST
	std::cout << std::endl << " araay of int implicite - explicite :" << std::endl;
	iter( tab, 5, print );
	iter<int>(int_test, sizeof(int_test)/sizeof(*int_test), &print<int>);
    // DOUBLE
	std::cout << std::setprecision(10);
	std::cout << std::endl << "array of double:" << std::endl;
	iter<double>(double_test, sizeof(double_test)/sizeof(*double_test), &print<double>);
    // STRNG TEST //
    std::cout << "array of strings:" << std::endl;
	iter<std::string>(string_test, string_test->length(), &print<std::string>);
    // ARRAY CHAR TEST
	std::cout << std::endl << "array of char:" << std::endl;
	iter<char>(array_test, strlen(array_test), &print<char>);

	return (0);
}