/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:29:07 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 21:23:55 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>

class Enemy
{

  public:
    Enemy(void);
    Enemy(int hp, std::string const &type);
    Enemy(Enemy const &src);
    virtual ~Enemy(void);

    Enemy &operator=(Enemy const &rhs);

    std::string getType(void) const;
    int         getHP(void) const;
    void        setHP(int i);

    virtual void takeDamage(int);

  private:
    int             _hp;
    std::string     _type;
};

#endif