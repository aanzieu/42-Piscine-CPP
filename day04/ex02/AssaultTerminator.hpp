/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 21:14:03 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 21:17:57 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_H
#define ASSAULTTERMINATOR_H

#include <iostream>
#include "AssaultTerminator.hpp"
#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
  public:
    AssaultTerminator(void);
    AssaultTerminator(AssaultTerminator const &obj);
    virtual ~AssaultTerminator(void);
    AssaultTerminator &operator=(AssaultTerminator const &rhs);

    ISpaceMarine *clone() const;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;
};

#endif