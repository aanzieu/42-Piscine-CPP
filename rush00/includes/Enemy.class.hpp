/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:17:11 by nbouchin          #+#    #+#             */
/*   Updated: 2018/10/07 09:15:46 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_H
#define ENEMY_CLASS_H

#include "AEntity.class.hpp"
#include "Missile.class.hpp"

class Enemy : public AEntity
{
	public:
		Enemy( void );
		Enemy( Enemy const & src );
		Enemy(struct position position, short healthPoint, char form, short speed);
		~Enemy( void );

		virtual Enemy		*clone() const;
		virtual AEntity		*attack( ) const;
		Enemy &			operator=( Enemy const & rhs );
};

#endif /* ASSAULTSHIP_CLASS_H */
