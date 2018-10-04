/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 07:57:50 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 12:22:05 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

#ifndef ZOMBIE_EVENT_H
# define ZOMBIE_EVENT_H

class ZombieEvent {

    public:

        ZombieEvent(void);
        ~ZombieEvent(void);

        std::string     typeEvent;

        void setZombietype_(std::string type);

        // Add Class Zombie ti make somtehing
        Zombie* newZombie(std::string name);
        Zombie* randomChump();

    private:




};


#endif