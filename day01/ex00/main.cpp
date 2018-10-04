/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 17:07:34 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 18:53:54 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Pony.hpp"

void ponyOnTheStack()
{
    Pony alpha("Alpha", 8, "GOLD", "stack");
    alpha.CreepCrap();
    return ;
}

void ponyOnTheHeap()
{
    Pony *beta= new Pony("Beta", 10, "pink", "heap");
    beta->CreepCrap();
    delete beta;
    return;
}

int main(void)
{
    std::cout << "           x" << std::endl;
    std::cout << ".-. _______|" << std::endl;
    std::cout << "|=|/     /  ]  " << std::endl;
    std::cout << "| |_____|_''_|" << std::endl;
    std::cout << "|_|_[X]_|____|" << std::endl;
    ponyOnTheStack();
    std::cout << "************" << std::endl;
    ponyOnTheHeap();
    return 0;
}
