/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:29:04 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 10:41:33 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_H
#define AWEAPON_H

#include <iostream>

class AWeapon
{

  public:
    AWeapon(void);
    AWeapon(std::string const & name, int apcost, int damage);
    AWeapon(AWeapon const & obj);

    virtual ~AWeapon(void);
    
    AWeapon &operator=(AWeapon const & rhs);

    virtual void attack() const = 0;

    std::string getName() const;
    int         getDamage() const;
    int         getAPCost() const;

  private:
    std::string _name;
    int         _dmg;
    int         _ap;
};

#endif