/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:29:15 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 11:10:22 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_H
#define SUPERMUTANT_H

#include <iostream>
#include "Enemy.hpp"

class SuperMutant : public Enemy
{

  public:
    SuperMutant(void);
    SuperMutant(SuperMutant const & src);
    virtual ~SuperMutant(void);
    SuperMutant &operator=(SuperMutant const &rhs);

    virtual void takeDamage(int damage);
};

#endif