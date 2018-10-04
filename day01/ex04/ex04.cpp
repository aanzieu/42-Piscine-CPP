/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 11:41:02 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 11:46:07 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main() 
{
	std::string		hi = "HI THIS IS BRAIN";
	std::string*    ptr = &hi;
	std::string&    ref = hi;

	std::cout << "This is display with pointer:" << std::endl << *ptr << std::endl;
	std::cout << std::endl << "This is display with reference:" << std::endl << ref << std::endl;

	return (0);
}