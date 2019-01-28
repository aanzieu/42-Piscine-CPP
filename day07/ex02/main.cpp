/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 12:39:10 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/11 16:50:53 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <iterator>
int				main(void)
{
	srand(time(NULL));

	unsigned int n = rand() % 20;
	Array<int> test(n);

	// std::cout << "Array["  << "] Content: " << Array<int>(*test)[n] << std::endl;
	try
	{
		unsigned int i = 0;
		while (i < n)
		{
			(test)[i] = rand() % 15;
			i++;
		}
		i = 0;
		while (i <= n)
		{
			std::cout << "Test[" << i << "] = " << (test)[i] << std::endl;
			i++;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Array<int> test2(2);
	test2 = test;
	try
	{
		unsigned int i = 0;
		while (i <= n)
		{
			std::cout << "Test2[" << i << "] = " << (test2)[i] << std::endl;
			i++;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Array<int>	*tataa;

	tataa = &test2;
	try
	{
		unsigned int i = 0;
		while (i <= n)
		{
			std::cout << "Tataa[" << i << "] = " << (*tataa)[i] << std::endl;
			i++;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	Array<float>	test_float(n);

	try
		{unsigned int i = 0;
		// while (i < n)
		// {
		// 	(test_float)[i] = 4810.156531;
		// 	i++;
		// }
		i = 0;
		while (i <= n)
		{
			std::cout << "test_float[" << i << "] = " << (test_float)[i] << std::endl;
			i++;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}