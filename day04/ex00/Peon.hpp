/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:45:44 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 13:04:32 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef PEON_H
# define PEON_H

#include "Victim.hpp"

class Peon : public Victim
{
  public:
    Peon( void );
    Peon( std::string name );
    Peon( Peon const & src );

    virtual ~Peon( void ); 

    Peon &operator=( Peon const & rhs );

    // other
    void          getPolymorphed(void) const;

    std::string     getName( void ) const;
};

std::ostream &operator<<(std::ostream &o, Peon const &r);

#endif