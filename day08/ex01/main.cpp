/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:37:40 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/12 17:14:10 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main()
{
    srand(time(NULL));
    Span test(5);
    unsigned int x = 0;
    int y = 0;

    try
    {
        while (x < 5)
        {
            y = rand() % 100;
            test.addNumber(y);
            // test.addNumber(25);
            // test.addNumber(89);
            // test.addNumber(78);
            std::cout << "[" << y << "] " << std::endl;
            // if (x % 13 == 0)
            // std::cout << std::endl;
            x++;
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "SHORT : " << test.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "LONG : " << test.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}