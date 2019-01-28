/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:45:45 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/05 19:02:04 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << Sorcerer::red << this->_name << Sorcerer::green << ", " << this->_title << Sorcerer::reset << ", is born !" << std::endl;
	return;
}

Sorcerer::Sorcerer(Sorcerer &obj)
{
	*this = obj;
	std::cout << Sorcerer::red << this->_name << Sorcerer::green << ", " << this->_title << Sorcerer::reset << ", is born !" << std::endl;
	return;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << Sorcerer::red << this->_name << Sorcerer::green << ", " << this->_title << Sorcerer::reset << ", is dead. Consequences will never be the same !" << std::endl;
	return;
}

Sorcerer &Sorcerer::operator=(Sorcerer const &r) 
{
	this->_name = r._name;
	this->_title = r._title;
	return (*this);
}

std::string		Sorcerer::getName() const
{
	return (this->_name);
}

std::string		Sorcerer::getTitle() const
{
	return (this->_title);
}



// Stream 
std::ostream	&operator<<(std::ostream & o, Sorcerer const &rhs)
{
	o << "I am " << "\033[1;32m" << rhs.getName() << ", " << rhs.getTitle() << "\033[0m" << ", and I like ponies !" << std::endl;
	return (o);
}


// Function
void	Sorcerer::polymorph(Victim const & src) const
{
	src.getPolymorphed();
	return;
}


// Coolor
const std::string Sorcerer::red = "\033[0;31m";
const std::string Sorcerer::green = "\033[1;32m";
const std::string Sorcerer::yellow = "\033[1;32m";
const std::string Sorcerer::cyan = "\033[0;36m";
const std::string Sorcerer::magenta = "\033[0;35m";
const std::string Sorcerer::reset = "\033[0m";