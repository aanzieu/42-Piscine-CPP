/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 08:27:37 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/04 18:15:47 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

int main(void)
{
    Fixed a;

    Fixed c(5);


    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );


    std::cout << "C value : " << std::endl;
    std::cout << c + a << std::endl;
    std::cout << (--c).toInt() << std::endl;
    // std::cout << c-- << std::endl;
    std::cout << c << std::endl;
    std::cout << c / a << std::endl;
    std::cout << c / c << std::endl;


    std::cout << "A value : " << std::endl;
    std::cout << a << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;


    std::cout << "B value : " << std::endl;
    std::cout << b << std::endl;
    std::cout << "A = " << a << std::endl;
    std::cout << "B = " << b << std::endl;
    std::cout << "C = " << c << std::endl;
    std::cout << Fixed::max( c, b ) << std::endl;
    std::cout << Fixed::min( a, c ) << std::endl;
    std::cout << Fixed::min( b, c ) << std::endl;

    return 0;
}