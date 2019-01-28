/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityPool.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:59:23 by nbouchin          #+#    #+#             */
/*   Updated: 2018/10/07 18:26:58 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/EntityPool.class.hpp"


EntityPool::EntityPool( void ) : _unitNumber(0), _maxUnitNumber(4096)
{
	this->_units = new AEntity*[this->_maxUnitNumber];
	for ( int i = 0; i <= this->_maxUnitNumber; i++)
		this->_units[i] = 0;
	return;
}

EntityPool::EntityPool( EntityPool const & src )
{
	this->_units = new AEntity*[src._maxUnitNumber];
	for (int i = 0; i < src.getCount(); i++)
		this->push(src.getUnit(i)->clone());
	return;
}

EntityPool::~EntityPool( void )
{
	for (int i = 0; i <= this->_unitNumber; i++)
		delete this->_units[i];
	delete [] this->_units;
	return;
}

int				EntityPool::getCount() const
{
	return this->_unitNumber;
}

AEntity*	EntityPool::getUnit(int i) const
{
	if (i > this->_maxUnitNumber || i >= this->_unitNumber + 1)
		return NULL;
	return this->_units[i + 1];
}

int				EntityPool::push(AEntity* ship)
{
//	AEntity	**swap;

	if (!ship)
		return this->_unitNumber;
//	if (this->_unitNumber >= this->_maxUnitNumber)
//	{
//		exit (0);
//		swap = new AEntity*[this->_maxUnitNumber + 256];
//		memcpy(swap, this->_units, sizeof(AEntity) * (this->_maxUnitNumber + 256));
//		delete [] this->_units;
//		this->_units = swap;
//		this->_maxUnitNumber += 256;
//	}
	for (int i = 0; i != this->_maxUnitNumber; i++)
	{
		if (this->_units[i] == ship)
			return this->_unitNumber;
	}
	this->_units[this->_unitNumber + 1] = ship;
	this->_unitNumber += 1;
	return this->_unitNumber;
}

EntityPool &	EntityPool::operator=( EntityPool const & rhs )
{
	for (int i = 0; i <= this->_unitNumber; i++)
		delete this->_units[i];
	delete [] this->_units;

	this->_units = new AEntity*[rhs._maxUnitNumber];
	for (int i = 0; i < rhs.getCount(); i++)
		this->push(rhs.getUnit(i)->clone());
	return *this;
}
