/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:46:14 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 10:16:18 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef VICTIM_H
#define VICTIM_H

class Victim
{

  public:
    Victim(void);
    Victim(std::string name);
    Victim(Victim const &src);

    virtual ~Victim(void);

    Victim &operator=(Victim const &rhs);

    // other
    virtual void getPolymorphed(void) const;

    std::string getName(void) const;

  protected:
    std::string _name;
};

std::ostream &operator<<(std::ostream &o, Victim const &rhs);

#endif