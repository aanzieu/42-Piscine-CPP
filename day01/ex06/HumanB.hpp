/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 15:34:38 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 17:01:23 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Weapon.hpp"

#ifndef HUMAN_B_H
# define HUMAN_B_H

class HumanB {

    public:
    HumanB(void);
    HumanB(std::string name);

    ~HumanB(void);

    void    attack() const;
    void	setWeapon(Weapon& weap);

    private:
    std::string     _name;
    Weapon         *_weapon;
};

#endif