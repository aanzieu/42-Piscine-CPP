/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:29:07 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 11:56:29 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const &type) : _hp(hp), _type(type)
{
    return;
}

Enemy::Enemy(Enemy const &src)
{
    *this = src;
    return;
}

Enemy::~Enemy(void)
{
    // std::cout << "DEAD" << std::endl;
    return;
}

Enemy &Enemy::operator=(Enemy const &rhs)
{
    this->_hp = rhs._hp;
    this->_type = rhs._type;
    return (*this);
}

std::string Enemy::getType() const
{
    return (this->_type);
}

int Enemy::getHP() const
{
    return (this->_hp);
}

void Enemy::takeDamage(int amount)
{
    int i = 0;

    if (amount < 0)
        return;
    else if (amount > this->_hp)
        i = this->_hp;
    else
        i = amount;
    this->_hp = this->_hp - i;
    if (this->_hp < 0)
        this->_hp = 0;
    return;
}

void Enemy::setHP(int i)
{
    this->_hp = i;
    return;
}