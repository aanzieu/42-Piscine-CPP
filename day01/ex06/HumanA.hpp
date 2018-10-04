/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 15:34:39 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 16:49:52 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Weapon.hpp"


#ifndef HUMAN_A_H
# define HUMAN_A_H

class HumanA {

    public:
    HumanA(std::string name, Weapon& weap);
    // HumanA(void); Need initinalise Weap


    ~HumanA(void);


    void    attack() const;

    private:
    std::string     _name;
    Weapon&         _weapon;
};

#endif