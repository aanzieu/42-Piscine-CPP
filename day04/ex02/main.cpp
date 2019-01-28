/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 21:16:03 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 22:40:28 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main()
{
    ISpaceMarine *bob = new TacticalMarine;
    // ISpaceMarine *jim = new AssaultTerminator;


    ISquad *vlc = new Squad;
    vlc->push(bob);


    ISquad *toto(vlc);

    // std::cout << toto->getCount() << std::endl;
    // vlc->push(jim);


    for (int i = 0; i < toto->getCount(); ++i)
    {
        ISpaceMarine *cur = toto->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }
    // delete vlc;
    // delete toto;
    return 0;
}