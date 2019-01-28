/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:17:14 by nbouchin          #+#    #+#             */
/*   Updated: 2018/10/07 08:47:29 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Enemy.class.hpp"

Enemy::Enemy( void )
{
	return;
}

Enemy::Enemy( struct position position, short healthPoint, char form, short speed ) : AEntity(position, healthPoint, form, speed)
{

}

Enemy::Enemy( Enemy const & src )
{
	*this = src;
	return;
}

Enemy::~Enemy( void )
{
	return;
}

Enemy *Enemy::clone() const
{
	return new Enemy(*this);
}

AEntity	*Enemy::attack( ) const
{
	struct	position position;

	position = getPosition();
	position.y += 2;
	AEntity *missile = new Missile(position, 1, '|', 1);
	return missile;
}

Enemy &	Enemy::operator=( Enemy const & rhs )
{
	(void)rhs;
	return *this;
}
