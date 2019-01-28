/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 08:28:40 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/04 14:59:10 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{

  public:
    // Canonical Construtor
    Fixed( void );                                    // Cannonical
    Fixed( Fixed const & src );                       // Cannonical
    // Other Constructor
    Fixed(int const num);
    Fixed(float const num);
    // Detroy Constructor
    ~Fixed( void );                                   // Cannonical

    Fixed       &operator=( Fixed const & rhs );      // Cannonical

    // Member Functions
    int         getRawBits( void ) const;
    void        setRawBits( int const raw );

    float       toFloat( void ) const;
    int         toInt( void ) const;

  private:

    int                 _value;
    static int const    _BitNum;

};


std::ostream &      operator<<( std::ostream & o, Fixed const & i);

#endif