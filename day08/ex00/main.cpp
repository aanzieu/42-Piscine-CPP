/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 18:01:24 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/12 14:09:28 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <map>
#include <list>
int main(int ac, char **av)
{
	srand(time(0));
	if (ac != 2)
	{
		std::cout << "Please enter one value between 0 and 9 to be searched in the list." << std::endl;
		return (0);
	}
	std::list<int> list;
	list.push_back(rand() % 10);
	list.push_back(rand() % 10);
	list.push_back(rand() % 10);
	list.push_back(rand() % 10);
	list.push_back(rand() % 10);
	list.push_back(rand() % 10);
	list.push_back(rand() % 10);
	// for push the array
	std::list<int>::const_iterator			it = list.begin();
	std::list<int>::const_iterator			ite = list.end();
	
	std::cout << "[";
	while (it != ite)
	{
		std::cout << *it;
		it++;
		if(it != ite)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
	try
	{
		easyfind(list, atoi(av[1]));
		std::cout << "Find" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error : Value not found" << std::endl;
	}

	return 0;
}
