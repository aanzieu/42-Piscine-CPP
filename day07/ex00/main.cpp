/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 09:33:38 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/11 15:10:04 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Template Swap
template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;

    a = b;
    b = tmp;
}

template <typename T>
T const &min(T const &a, T const &b)
{
    return ((a < b) ? a : b);
}

template <typename T>
T const &max(T const &a, T const &b)
{
    return ((a >= b) ? a : b);
}

int main(void)
{
    int a = 2;
    int b = 3;

    std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << "c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    float f = 2.00001;
    float g = 2.00002;
    std::cout << "f = " << f << ", g = " << g << std::endl;
    ::swap(f, g);
    std::cout << "f = " << f << ", g = " << g << std::endl;
    std::cout << "min( g, f ) = " << ::min(f, g) << std::endl;
    std::cout << "max( g, f ) = " << ::max(g, f) << std::endl;
    return (0);
}