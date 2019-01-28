/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:22:12 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/07 11:26:51 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Time.class.hpp"

Timer::Timer(void) {}

Timer::Timer(clock_t t) : _timer(t) {}

Timer::Timer(Timer &obj) { 
	*this = obj;
}

Timer::~Timer(void) {}

Timer &Timer::operator=(Timer const &r) {
	this->_timer = r._timer;
	return (*this);
}

int		Timer::checkTime(clock_t t) {
	return ((this->_timer - t) / (CLOCKS_PER_SEC / 1000));
}

int		Timer::getSec(clock_t t) {
	return ((t - this->_timer) / CLOCKS_PER_SEC);
}
