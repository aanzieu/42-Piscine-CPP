/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 08:28:40 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/04 14:54:08 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{

  public:

    Fixed( void );                                    // Cannonical
    Fixed( Fixed const & src );                       // Cannonical
    ~Fixed( void );                                   // Cannonical

    Fixed       &operator=( Fixed const & rhs );      // Cannonical


    // Member
    int         getRawBits( void ) const;
    void        setRawBits( int const raw );

  private:

    int                 _value;
    static int const    _BitNum;

};


std::ostream &      operator<<( std::ostream & o, Fixed const & i);

#endif