/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 12:57:08 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 15:12:00 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Human.hpp"
#include "Brain.hpp"
// Contructor
Human::Human(void){ return; }
Human::~Human(void){ return; }

std::string Human::identify() const
{
	return this->_attr_Brain.identify();
}
// Reference constante
//------------------
const Brain& Human::getBrain(void)
{
	return this->_attr_Brain;
}
    