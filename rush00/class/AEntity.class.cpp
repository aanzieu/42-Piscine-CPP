/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 12:43:16 by nbouchin          #+#    #+#             */
/*   Updated: 2018/10/07 20:15:41 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/GamePlayer.hpp"

AEntity::AEntity(void)
{
}

AEntity::AEntity(struct position position, short healthPoint, char form, short speed) : _healthPoint(healthPoint), _position(position), _form(form), _speed(speed)
{
	return;
}

AEntity::AEntity(AEntity const &src)
{
	*this = src;
	return;
}

AEntity::~AEntity(void)
{
	//TODO;
	return;
}

bool AEntity::checkColision(position self, position target, char type) const
{

	if (type == 'M')
	{
		if ((self.x == target.x) && (self.y == target.y))
			return 1;
		else if ((self.x == target.x + 1) && (self.y == target.y))
			return 1;
		else if ((self.x == target.x + 2) && (self.y == target.y))
			return 1;
		else if ((self.x == target.x - 1) && (self.y == target.y))
			return 1;
		else if ((self.x == target.x - 2) && (self.y == target.y))
			return 1;
	}
	else if (type == 'P')
	{
		if ((self.x == target.x) && (self.y == target.y))
			return 1;
		else if ((self.x == target.x + 1) && (self.y == target.y))
			return 1;
		else if ((self.x == target.x + 2) && (self.y == target.y))
			return 1;
		else if ((self.x == target.x - 1) && (self.y == target.y))
			return 1;
		else if ((self.x == target.x - 2) && (self.y == target.y))
			return 1;
	}
	return 0;
}

bool AEntity::moveMissile(char dir, int sec, int maxx, int maxy)
{
	(void)sec;
	(void)maxx;
	(void)maxy;
	if (dir == 'U')
	{
		this->_position.y -= 1;
		if (this->_position.y < 0)
			this->_healthPoint = 0;
		return (1);
	}
	if (dir == 'D')
	{
		this->_position.y += 1;
		if (this->_position.y > (maxy + 1))
			this->_healthPoint = 0;
		return (1);
	}
	return (0);
}

bool AEntity::moveRandom(char dir, int sec, int maxx, int maxy)
{
	(void)dir;
	(void)sec;
	(void)maxx;

	if (this->_position.y < (maxy + 1))
		this->_position.y += 1;
	else
	{
		this->_healthPoint = 0;
		mvprintw(this->_position.y, this->_position.x, " ");
		mvprintw(this->_position.y, this->_position.x - 1, " ");
		mvprintw(this->_position.y, this->_position.x - 2, " ");
		mvprintw(this->_position.y, this->_position.x + 1, " ");
		mvprintw(this->_position.y, this->_position.x + 2, " ");
		return (1);
	}
	return (0);
}

short AEntity::getHP()
{
	return this->_healthPoint;
}

void AEntity::setHP(int healthPoint)
{
	this->_healthPoint = healthPoint;
}

void AEntity::getHit(int damages)
{
	this->setHP(damages);
}

char AEntity::getForm() const
{
	return this->_form;
}

struct position AEntity::getPosition() const
{
	return this->_position;
}

void AEntity::setPosition(int y, int x)
{
	this->_position.y = y;
	this->_position.x = x;
}

short AEntity::getSpeed(void) const
{
	return this->_speed;
}

void AEntity::setSpeed(short speed)
{
	this->_speed = speed;
}

AEntity &AEntity::operator=(AEntity const &rhs)
{
	//TODO;
	(void)rhs;
	return *this;
}
