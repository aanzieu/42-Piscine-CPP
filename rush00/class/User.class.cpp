/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:17:14 by nbouchin          #+#    #+#             */
/*   Updated: 2018/10/07 09:16:54 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/User.class.hpp"

User::User( void )
{
	return;
}

User::User( struct position position, short healthPoint, char form, short speed ) : AEntity(position, healthPoint, form, speed)
{

}

User::User( User const & src )
{
	*this = src;
	return;
}

User::~User( void )
{
	return;
}

User *User::clone() const
{
	return new User(*this);
}

AEntity		*User::attack() const
{
	struct	position position;

	position = getPosition();
	position.y -= 2;
	AEntity *missile = new Missile(position, 1, '|', 1);
	return missile;
}

User &	User::operator=( User const & rhs )
{
	(void)rhs;
	return *this;
}
