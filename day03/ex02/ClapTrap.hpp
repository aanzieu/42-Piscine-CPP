/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 12:13:08 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/05 13:39:56 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef CLAP_TRAP_H
# define CLAP_TRAP_H

class ClapTrap {

    public:
        // Constructor
        ClapTrap( void );                               // Cannonical
        ClapTrap( ClapTrap const & src );               // Cannonical
        // Other Constructor
        ClapTrap( std::string name );

        // Destroy Constructor
        virtual ~ClapTrap( void );                              // Cannonical

        // Overload
        ClapTrap & operator=( ClapTrap const & rhs );   // Cannonical

        // Attacks
        void            rangedAttack( std::string const & target );
        void            meleeAttack( std::string const & target );

        

        // Damage Repair
        void            takeDamage( unsigned int amount );
        void            beRepaired( unsigned int amount );

        // Get Value_
        int		        get_Hit_points(void);
		int		        get_Max_hit_points(void);
		int		        get_Energy_points(void);
		int		        get_Max_energy_points(void);
		int		        get_Level(void);
		int		        get_Melee_attack_damage(void);
		int		        get_Ranged_attack_damage(void);
		int		        get_Armor_damage_reduction(void);
        // Set Value
        void            set_Hit_points(int i);
		void            set_Max_hit_points(int i);
		void            set_Energy_points(int i);
		void            set_Max_energy_points(int i);
		void            set_Level(int i);
		void            set_Melee_attack_damage(int i);
		void            set_Ranged_attack_damage(int i);
		void            set_Armor_damage_reduction(int i);

        // Show Status
        void            displayStats(void) const;
        // Set All Value
		void	        set_Stats(std::string name, 
                        int lvl, int hp, int max_hp, int ep, 
                        int max_ep, int melle_atk, int range_atk, 
                        int armor) ;

    protected :
        std::string     _Name;                          

    private:
        // element of frag
        int             _Hit_points;                    
        int             _Max_hit_points;                
        int             _Energy_points;                 
        int             _Max_energy_points;             
        int             _Level;                         
        int             _Melee_attack_damage;           
        int             _Ranged_attack_damage;          
        int             _Armor_damage_reduction;        
};

#endif