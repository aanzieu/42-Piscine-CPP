/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 07:59:05 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/05 11:50:51 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef SCAV_TRAP_H
# define SCAV_TRAP_H

class ScavTrap {

    public:
        // Constructor
        ScavTrap( void );                               // Cannonical
        ScavTrap( ScavTrap const & src );               // Cannonical
        // Other Constructor
        ScavTrap( std::string name );

        // Destroy Constructor
        ~ScavTrap( void );                              // Cannonical

        // Overload
        ScavTrap & operator=( ScavTrap const & rhs );   // Cannonical

        // Attacks
        void            rangedAttack( std::string const & target );
        void            meleeAttack( std::string const & target );

		void	        challengeNewcomer( std::string const & target);

        // Show Status
        void            displayStats(void) const;

        void            takeDamage( unsigned int amount );
        void            beRepaired( unsigned int amount );


    private:
        // element of frag
        int             _Hit_points;                    //(100)
        int             _Max_hit_points;                // (100)
        int             _Energy_points;                 //(50)
        int             _Max_energy_points;             //(100)
        int             _Level;                         //(1)
        std::string     _Name;                          // (Parameter of constructor)
        int             _Melee_attack_damage;           // (20)
        int             _Ranged_attack_damage;          // (15)
        int             _Armor_damage_reduction;        //(3)

};
#endif