/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 08:28:44 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/04 17:41:01 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

// Init Construtor
Fixed::Fixed(void) : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
    return;
}

// Copy Constructor
Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return;
}

// Destroy Constructor
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

// Operator overload
Fixed &     Fixed::operator=(Fixed const & rhs)
{
    std::cout << "Assignment operator called" << std::endl;

    if (this != & rhs)
        this->_value = rhs.getRawBits();
    return (*this);
}

// member functions
// -----------------
// RawBits
int         Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}


void        Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
    return;
}

// Const Fixed _BitNum
int const Fixed::_BitNum = 8;