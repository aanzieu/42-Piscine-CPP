/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:29:10 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 21:36:42 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_H
#define PLASMARIFLE_H

#include <iostream>
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
  public:
    PlasmaRifle(void);
    PlasmaRifle(PlasmaRifle const & src);
    virtual ~PlasmaRifle(void);
    PlasmaRifle &operator=(PlasmaRifle const & rhs);

    void    attack(void) const;
};

#endif