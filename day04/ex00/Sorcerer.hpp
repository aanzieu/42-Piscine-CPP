/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:45:46 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/05 18:55:58 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef SORCERER_H
#define SORCERER_H

#include "Victim.hpp"

class Sorcerer
{

  public:
    Sorcerer(void);
    Sorcerer(std::string name, std::string title);
    Sorcerer(Sorcerer &src);
    virtual ~Sorcerer(void);

    Sorcerer &operator=(Sorcerer const &rhs);


    // other
    void polymorph(Victim const &) const;


    std::string getName() const;
    std::string getTitle() const;

  private:
    std::string _name;
    std::string _title;

    static const std::string red;
    static const std::string green;
    static const std::string yellow;
    static const std::string cyan;
    static const std::string magenta;
    static const std::string reset;
};

std::ostream &operator<<(std::ostream &o, Sorcerer const &r);

#endif