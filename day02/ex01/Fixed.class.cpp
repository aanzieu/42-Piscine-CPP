/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 08:28:44 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/04 14:59:14 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

//CONSTRUCTOR
//------------------------
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

// Constructor integrer
Fixed::Fixed(int const num) {

    std::cout << "Int constructor called" << std::endl;
	this->setRawBits(num << this->_BitNum);
    return;
}

// Constructor float
Fixed::Fixed(float const num) {

    std::cout << "Float constructor called" << std::endl;
    // multiplie by 256 and around sup
	this->setRawBits(roundf(num * (1 << this->_BitNum)));
    return;
}

// DESTRuCTOR
//-------------------------
// Destroy Constructor
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

// OVERLOARD OPERATOR
//---------------------------
// Operator overload
Fixed &     Fixed::operator=(Fixed const & rhs)
{
    std::cout << "Assignment operator called" << std::endl;

    if (this != & rhs)
        this->_value = rhs.getRawBits();
    return (*this);
}

// MEMBER
// -----------------
// GetRawBits
int         Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

// SetRawBits
void        Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
    return;
}

//Int ot fload
float	Fixed::toFloat(void) const {
   	return ((float)this->getRawBits() / (1 << this->_BitNum));
}

int		Fixed::toInt(void) const {

   return (this->getRawBits() >> this->_BitNum);
}


// Operator << ostream No necessary to if 
std::ostream &  operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return (o);
}

// Const Fixed _BitNum
int const Fixed::_BitNum = 8;