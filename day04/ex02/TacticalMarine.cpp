/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 21:18:23 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 23:11:02 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine(void)
{
    std::cout << "Tactical Marine ready for battle" << std::endl;
    return;
}

TacticalMarine::TacticalMarine(TacticalMarine const &obj)
{
    *this = obj;
    std::cout << "Tactical Marine ready for battle" << std::endl;
    return;
}

TacticalMarine::~TacticalMarine(void)
{
    std::cout << "Aaargh ..." << std::endl;
    return;
}

TacticalMarine &TacticalMarine::operator=(TacticalMarine const &r)
{
    (void)r;
    return (*this);
}

ISpaceMarine *TacticalMarine::clone() const
{
    ISpaceMarine *ret = new TacticalMarine(*this);
    return (ret);
}

void TacticalMarine::battleCry() const
{
    std::cout << "For the holy PLOT !" << std::endl;
    return;
}

void TacticalMarine::rangedAttack() const
{
    std::cout << "* attacks with bolter *" << std::endl;
    return;
}

void TacticalMarine::meleeAttack() const
{
    std::cout << "* attacks with chainsword *" << std::endl;
    return;
}