/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 08:28:40 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/04 17:28:46 by aanzieu          ###   ########.fr       */
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

    // overload
    Fixed &   operator=( Fixed const & rhs );      // Cannonical

    //Comparaison operators
    bool      operator<( Fixed const & rhs );
    bool      operator>( Fixed const & rhs );
    bool      operator==( Fixed const & rhs );
    bool      operator>=( Fixed const & rhs );
    bool      operator<=( Fixed const & rhs );
    bool      operator!=( Fixed const & rhs );

    // Operator Overload
		Fixed 		operator+(Fixed const &r);
		Fixed 		operator-(Fixed const &r);
		Fixed 		operator*(Fixed const &r);
		Fixed 		operator/(Fixed const &r);

		Fixed 		&operator++(void);
		Fixed		  operator++(int);
		Fixed 		&operator--(void);
		Fixed		  operator--(int);
    // STATIC non membre
    static Fixed        &min(Fixed  & lhs, Fixed  & rhs);
    static Fixed        &max(Fixed  & lhs, Fixed  &  rhs);
    static Fixed  const &min(Fixed const  &  lhs, Fixed  const & rhs);
    static Fixed  const &max(Fixed const  &  lhs, Fixed  const & rhs);

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

