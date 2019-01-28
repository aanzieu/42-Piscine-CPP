/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:45:42 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 12:16:23 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
	return;
}

Peon::Peon(Peon const & src) : Victim(src)
{
	*this = src;
	std::cout << "Zog zog." << std::endl;
	return;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
	return;
}

Peon &Peon::operator=(Peon const &rhs) 
{
	this->_name = rhs._name;
	return (*this);
}

std::string		Peon::getName(void) const
{
	return (this->_name);
}


// Operator
std::ostream	&operator<<(std::ostream &o, Peon const &r)
{
	o << "I'm " << r.getName() << " and I like otters!" << std::endl;
	return (o);
}

void	Peon::getPolymorphed(void) const
{
	std::cout << this->_name << " has beexn turned into a pink pony !" << std::endl;
	return;
}
