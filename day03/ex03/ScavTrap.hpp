/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 07:59:05 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/05 13:11:50 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef SCAV_TRAP_H
# define SCAV_TRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

    public:
        // Constructor
        ScavTrap( void );                               // Cannonical
        ScavTrap( ScavTrap const & src );               // Cannonical
        // Other Constructor
        ScavTrap( std::string name );

        // Destroy Constructor
        virtual ~ScavTrap( void );                              // Cannonical

        // Overload
        ScavTrap & operator=( ScavTrap const & rhs );   // Cannonical

		void	        challengeNewcomer( std::string const & target);

    private:
};
#endif