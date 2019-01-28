/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:29:11 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 11:40:14 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50)
{
    return;
}

PowerFist::PowerFist(PowerFist const &src) : AWeapon(src)
{
    *this = src;
    return;
}

PowerFist::~PowerFist(void)
{
    return;
}

PowerFist &PowerFist::operator=(PowerFist const &rhs)
{
    AWeapon::operator=(rhs);
    return (*this);
}

void PowerFist::attack(void) const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
    return;
}