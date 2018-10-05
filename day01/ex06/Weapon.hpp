/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 15:34:36 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/04 08:23:54 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>

#ifndef WEAPON_H
# define WEAPON_H

class Weapon {

    public:

    Weapon(void);
    Weapon(std::string input);

     ~Weapon(void);


    std::string const &  getType();
    void				 setType(std::string input);


    private:
        std::string             _typeOfWeapon;

};
#endif