/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:29:12 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 10:42:42 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_H
#define POWERFIST_H

#include <iostream>
#include "AWeapon.hpp"

class PowerFist : public AWeapon
{

  public:
    PowerFist(void);
    PowerFist(PowerFist const &src);
    virtual ~PowerFist(void);

    PowerFist &operator=(PowerFist const &rhs);

    void attack(void) const;
};

#endif