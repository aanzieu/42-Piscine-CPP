/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 07:59:05 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/05 10:45:52 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef FRAG_TRAP_H
# define FRAG_TRAP_H

class FragTrap {

    public:
        // Constructor
        FragTrap( void );                               // Cannonical
        FragTrap( FragTrap const & src );               // Cannonical
        // Other Constructor
        FragTrap( std::string name );

        // Destroy Constructor
        ~FragTrap( void );                              // Cannonical

        // Overload
        FragTrap & operator=( FragTrap const & rhs );   // Cannonical

        // Attacks
        void            rangedAttack( std::string const & target );
        void            meleeAttack( std::string const & target );
        // Special Attack
        void	        vaulthunter_dot_exe( std:: string const & target );
		void	        funzerker( std:: string const & target );
		void	        mechromagician( std:: string const & target );
		void	        shhhh_Trap( std:: string const & target );
		void	        rubber_Ducky( std:: string const & target );
		void	        one_Shot_Wonder( std:: string const & target);
        // Show Status
        void            displayStats(void) const;

        void            takeDamage( unsigned int amount );
        void            beRepaired( unsigned int amount );

        std::string     annouce_funzerker(void) const;
        std::string	    annouce_mechromagician( void ) const;
		std::string	    annouce_shhhh_Trap( void  ) const;
		std::string	    annouce_rubber_Ducky( void  ) const;
		std::string	    annouce_one_Shot_Wonder( void ) const;

    private:
        // element of frag
        int             _Hit_points;                    //(100)
        int             _Max_hit_points;                // (100)
        int             _Energy_points;                 //(100)
        int             _Max_energy_points;             //(100)
        int             _Level;                         //(1)
        std::string     _Name;                          // (Parameter of constructor)
        int             _Melee_attack_damage;           // (30)
        int             _Ranged_attack_damage;          // (20)
        int             _Armor_damage_reduction;        //(5)


         static std::string      _annouce_funzerker[];
         static std::string      _annouce_mechromagician[];
         static std::string      _annouce_shhhh_Trap[];
         static std::string      _annouce_rubber_Ducky[];
         static std::string      _annouce_one_Shot_Wonder[];


};
#endif