/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 21:45:07 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 21:45:19 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef HUMAN_H
# define HUMAN_H

class Human {
    private:
        void meleeAttack(std::string const & target);
        void rangedAttack(std::string const & target);
        void intimidatingShout(std::string const & target);
    public:
        void action(std::string const & action_name, std::string const & target);
};

#endif