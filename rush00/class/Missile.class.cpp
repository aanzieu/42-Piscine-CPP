/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:16:53 by nbouchin          #+#    #+#             */
/*   Updated: 2018/10/07 07:15:28 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Missile.class.hpp"

Missile::Missile( void )
{
	return;
}

Missile::Missile( struct position position, short healthPoint, char form, short speed ) : AEntity(position, healthPoint, form, speed)
{

}

Missile::Missile( Missile const & src )
{
	*this = src;
	return;
}

Missile::~Missile( void )
{
	return;
}

Missile *Missile::clone() const
{
	return new Missile(*this);
}

AEntity	*Missile::attack() const
{
	return 0;
}

Missile &	Missile::operator=( Missile const & rhs )
{
	(void)rhs;
	return *this;
}
