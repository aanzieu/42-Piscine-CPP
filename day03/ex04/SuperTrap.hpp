/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:06:06 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/05 16:40:13 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_H
# define SUPERTRAP_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class	SuperTrap : virtual public FragTrap, virtual public NinjaTrap
{

	public:

		SuperTrap( void );
		SuperTrap( std::string name );
		SuperTrap( SuperTrap const & obj );
		virtual ~SuperTrap( void );
		SuperTrap &operator=( SuperTrap const & r );

}; 

#endif