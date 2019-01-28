/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 21:48:52 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 23:10:41 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad(void) : ISquad(), _unit(0), _s_marine(NULL)
{
    return;
}

Squad::Squad(Squad const &src) : ISquad()
{
    //this->_unit = ._unit;

    *this = src;
    return;
}

Squad::~Squad(void)
{
    killSquad();
    return;
}

// Operator
Squad &Squad::operator=(Squad const &rhs)
{
    killSquad();

    while (this->_unit != rhs._unit)
        // use Push to get unit and clone unit to DEEP !importante
        this->push(rhs.getUnit(this->_unit)->clone());
    return (*this);
}

int Squad::getCount() const
{
    return (this->_unit);
}

//Marine Function
//--------------
// Kill Squad
void Squad::killSquad(void)
{

    t_marine *copy;

    while (this->_s_marine)
    {
        copy = this->_s_marine->next;
        delete this->_s_marine->marine;
        delete this->_s_marine;
        this->_s_marine = copy;
    }
    this->_unit = 0;
    return;
}

int Squad::push(ISpaceMarine *src)
{
    t_marine *copy;

    if (this->_s_marine == NULL)
    {
        this->_s_marine = new t_marine;
        this->_s_marine->marine = src;
        this->_s_marine->next = NULL;
        this->_unit += 1;
        return (this->_unit);
    }
    copy = this->_s_marine;
    while (copy->next)
        copy = copy->next;
    copy->next = new t_marine;
    copy->next->marine = src;
    copy->next->next = NULL;
    this->_unit = this->_unit + 1;
    return (this->_unit);
}

ISpaceMarine *Squad::getUnit(int i) const
{
    t_marine *tmp;

    tmp = this->_s_marine;
    while (i != 0 && tmp != NULL)
    {
        tmp = tmp->next;
        i--;
    }
    return (tmp->marine);
}