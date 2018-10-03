/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 21:45:36 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 22:18:10 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"


// PRIVATE
void Human::meleeAttack(std::string const & target){
    srand(time(0));
	int i = rand();

    switch( i % 4) {
        case 0 :
            std::cout << "Uperrcut Fist on " << target << std::endl;
            break;
        case 1 :
            std::cout << "Right Fist on " << target << std::endl;
            break;
        case 2 :
            std::cout << "Left Fist on " << target << std::endl;
            break;
        case 3 :
            std::cout << "Kick Face on " << target << std::endl;
            break;
        default :
            std::cout << "Miss " << target << std::endl;
            break;
    }
}

void Human::rangedAttack(std::string const & target) {
    srand(time(0));
	int i = rand();

     switch( i % 4) {
        case 0 :
            std::cout << "Shout with Combo at " << target << std::endl;
            break;
        case 1 :
            std::cout << "Shout three Bullet at " << target << std::endl;
            break;
        case 2 :
            std::cout << "Recharge for kill " << target << std::endl;
            break;
        case 3 :
            std::cout << "OUAH shoout WINN at " << target << std::endl;
            break;
        default :
            std::cout << "Totaly Miss at " << target << std::endl;
            break;
    }
}
void Human::intimidatingShout(std::string const & target) {

    srand(time(0));
	int i = rand();

    switch( i % 4) {
        case 0 :
            std::cout << "Eyes to Eyes at " << target << std::endl;
            break;
        case 1 :
            std::cout << "Dance troll at " << target << std::endl;
            break;
        case 2 :
            std::cout << "Best Regard's at " << target << std::endl;
            break;
        case 3 :
            std::cout << "Thinking expression at " << target << std::endl;
            break;
        default :
            std::cout << "No interrese " << target << std::endl;
            break;
    }
}

//Public


void Human::action(std::string const & action_name, std::string const & target){
    
    void ( Human::*action_[3] )( std::string const &) = {
        &Human::meleeAttack,
        &Human::rangedAttack,
        &Human::intimidatingShout,
    };

    std::string commands[3] = {
		"meleeAttack",
		"rangedAttack",
		"intimidatingShout"
	};

    int i = 0;
    while (i < 3)
	{
		if (commands[i] == action_name)
		{
			(this->*action_[i])(target);
			break;
		}
		i++;
	}
	return;
}