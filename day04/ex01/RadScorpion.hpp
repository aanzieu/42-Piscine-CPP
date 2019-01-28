/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:29:13 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 21:27:18 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_H
#define RADSCORPION_H

#include <iostream>
#include "Enemy.hpp"

class RadScorpion : public Enemy
{

  public:
    RadScorpion(void);
    RadScorpion(RadScorpion const &src);
    virtual ~RadScorpion(void);
    // RadScorpion &operator=(RadScorpion const &rhs);
    using Enemy::operator=;
};

#endif
