/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 22:18:20 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/04 08:07:38 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"


bool    is_space(std::string & str){

    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
            if (*it != ' ')
                return false;
    };
    return true;
}
int    error_parse(){
    std::cout << "Choose Attack and Target" << std::endl <<
        "valid attack are : meleeAttack, rangedAttack, intimidatingShoot" << std::endl;
    return (0);
}

int	main(int ac, char **av)
{
	Human 		    human;
	std::string     attack, target;

	if (ac != 3) {
		return error_parse();
    }
	attack = (av[1]);
	target = (av[2]);
	if (attack.compare("meleeAttack") == 0 || attack.compare("rangedAttack") == 0 || attack.compare("intimidatingShoot") == 0)
	{
		if (target.empty() || is_space(target)) {
			target = "in the wind";
        }
		std::cout << "FIGHT !" << std::endl;
		std::cout << "Attack type is " << attack << std::endl;
		human.action(attack, target);
	}
	else
	    return error_parse();
}