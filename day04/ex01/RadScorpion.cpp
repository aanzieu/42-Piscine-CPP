/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:29:13 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 11:59:26 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void) : Enemy(80, "RadScorpion")
{
    std::cout << "* click click click *" << std::endl;
    return;
}

RadScorpion::RadScorpion(RadScorpion const &src) : Enemy(src)
{
    *this = src;
    std::cout << "* click click click *" << std::endl;
    return;
}

RadScorpion::~RadScorpion(void)
{
    std::cout << "* SPROTCH *" << std::endl;
    return;
}

// RadScorpion &RadScorpion::operator=(RadScorpion const &r)
// {
//     // Enemy::operator=(r);
//     return (*this);
// }
