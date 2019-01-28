/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 11:48:22 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 15:32:09 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {

    this->_addr << this;
    return; 
}

Brain::~Brain(void) { return; }


// Function
// ----------------
std::string	Brain::identify() const {
    // return a string from stringstream
	return this->_addr.str();
}
