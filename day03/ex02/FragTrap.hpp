/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 07:59:05 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/05 12:54:24 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef FRAG_TRAP_H
# define FRAG_TRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

    public:
        // Constructor
        FragTrap( void );                               // Cannonical
        FragTrap( FragTrap const & src );               // Cannonical
        // Other Constructor
        FragTrap( std::string name );

        // Destroy Constructor
        virtual ~FragTrap( void );                              // Cannonical

        // Overload
        FragTrap & operator=( FragTrap const & rhs );   // Cannonical

        // Special Attack
        void	        vaulthunter_dot_exe( std:: string const & target );
        void	        funzerker( std:: string const & target );
        void	        mechromagician( std:: string const & target );
        void	        shhhh_Trap( std:: string const & target );
        void	        rubber_Ducky( std:: string const & target );
        void	        one_Shot_Wonder( std:: string const & target);

        std::string     annouce_funzerker( void ) const;
        std::string	    annouce_mechromagician( void ) const;
		std::string	    annouce_shhhh_Trap( void  ) const;
		std::string	    annouce_rubber_Ducky( void  ) const;
		std::string	    annouce_one_Shot_Wonder( void ) const;

    private:
        // element of frag
        static std::string      _annouce_funzerker[];
        static std::string      _annouce_mechromagician[];
        static std::string      _annouce_shhhh_Trap[];
        static std::string      _annouce_rubber_Ducky[];
        static std::string      _annouce_one_Shot_Wonder[];


};
#endif