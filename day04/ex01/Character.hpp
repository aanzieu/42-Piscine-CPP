/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:29:07 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 11:25:20 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{

  public:
    Character(void);
    Character(std::string const &name);
    Character(Character const &src);
    virtual ~Character(void);
    Character &operator=(Character const &rhs);

    void recoverAP(void);
    void equip(AWeapon *);
    void attack(Enemy *);

    std::string getName(void) const;
    int getAP(void) const;
    AWeapon *getWeapon(void) const;

    static const std::string red;
    static const std::string green;
    static const std::string yellow;
    static const std::string cyan;
    static const std::string magenta;
    static const std::string reset;

  private:
    std::string _name;
    AWeapon *_weapon;
    int _ap;
};

std::ostream &operator<<(std::ostream &o, Character const &r);

#endif