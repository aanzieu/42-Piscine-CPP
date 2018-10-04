/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 17:07:54 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 18:56:52 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_H
# define PONY_H

#include <iostream>

class	Pony {

	public: 

		std::string 	Name;
		int   		    Age;
		std::string     Hair;
		std::string     Onstack;

		Pony(std::string Name, int Age, std::string Color_Hair, std::string OnStack);
		~Pony(void);

        void    CreepCrap(void);
		
};

#endif