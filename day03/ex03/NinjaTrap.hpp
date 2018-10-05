/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 07:59:05 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/05 15:06:11 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef NINJA_TRAP_H
# define NINJA_TRAP_H

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class NinjaTrap : public ClapTrap
{

    public:
        // Constructor
        NinjaTrap( void );                               // Cannonical
        NinjaTrap( NinjaTrap const & src );               // Cannonical
        // Other Constructor
        NinjaTrap( std::string name );

        // Destroy Constructor
        virtual ~NinjaTrap( void );                              // Cannonical

        // Overload
        NinjaTrap & operator=( NinjaTrap const & rhs );   // Cannonical
        
        // Show Over
		void	ninjaShoeBox( NinjaTrap const & rhs );
        void	ninjaShoeBox( ClapTrap const  & rhs );
		void	ninjaShoeBox( FragTrap const & rhs );
		void	ninjaShoeBox( ScavTrap const & rhs );

    private:
};
#endif