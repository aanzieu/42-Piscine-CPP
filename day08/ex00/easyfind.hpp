/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 12:27:24 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/12 14:06:51 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <vector>
#include <list>

template <typename T>
void		easyfind(T & list, int  value)
{
	typename T::iterator it;
	it = find(list.begin(), list.end(), value);
	if (it == list.end())
		throw std::exception();
}

#endif