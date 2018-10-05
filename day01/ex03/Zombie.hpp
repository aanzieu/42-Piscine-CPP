/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 07:57:44 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 10:58:21 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ZOMBIE_H
# define ZOMBIE_H

class Zombie {

    public:

		Zombie(void);
    	Zombie(std::string name, std::string type); 

		~Zombie(void);

		std::string 	nameOfZombie_;
		std::string		typeOfZombie_;

		void announce_Zombie_() const;
    



    private:


};

#endif