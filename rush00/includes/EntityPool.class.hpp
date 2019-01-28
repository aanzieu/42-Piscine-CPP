/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityPool.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:00:27 by nbouchin          #+#    #+#             */
/*   Updated: 2018/10/07 16:04:12 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITYPOOL_CLASS_H
#define ENTITYPOOL_CLASS_H

#include "IEntityPool.class.hpp"
#include <iostream>

class EntityPool : public IEntityPool
{
	private:
		AEntity			**_units;
		int				_unitNumber;	
		int				_maxUnitNumber;

	public:
		EntityPool( void );
		EntityPool( EntityPool const & src );
		~EntityPool( void );

		virtual int		getCount() const;
		virtual AEntity*	getUnit(int) const;
		virtual int		push(AEntity*);

		EntityPool &	operator=( EntityPool const & rhs );
};

#endif /* ENTITYPOOL_CLASS_H */
