/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 15:34:44 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 16:49:33 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& weap) : _name(name), _weapon(weap)
{
	return;
}
// Reference need to be set so
// HumanA::HumanA(void) {
//     return; 
// }
HumanA::~HumanA(void){ return; }

void	HumanA::attack() const
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}