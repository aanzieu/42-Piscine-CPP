/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:45:47 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/05 19:05:09 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(std::string name) : _name(name)
{
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
	return;
}

Victim::Victim(Victim const  & obj)
{
	*this = obj;
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
	return;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << this->_name << " just died for no apparent reason !" << std::endl;
	return;
}

Victim &Victim::operator=(Victim const & rhs) 
{
	this->_name = rhs._name;
	return (*this);
}

std::string		Victim::getName(void) const
{
	return (this->_name);
}


// 
std::ostream	&operator<<(std::ostream &o, Victim const &rhs)
{
	o << "I'm " << rhs.getName() << " and I like otters!" << std::endl;
	return (o);
}

void	Victim::getPolymorphed(void) const
{
	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
	return;
}