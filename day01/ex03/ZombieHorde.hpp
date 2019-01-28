/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 10:07:05 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 11:04:52 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef ZOMBIE_HORDE_H
# define ZOMBIE_HORDE_H
#include "Zombie.hpp"

class ZombieHorde {

    public:

        // Variable Set
        Zombie          *horde;

        //Constructor;
        ZombieHorde(void);
        ZombieHorde(int n);

        ~ZombieHorde(void);


        // Function
        int             getAmountOfZombies(void);
        void 			announce_All_Zombies() const;


//***********************************//
    private:

        //Variable
        int     amount;
        static std::string      _namePool[];

        //Function
        static std::string		_randomName();

};

#endif