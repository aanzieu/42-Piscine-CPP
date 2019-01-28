/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 12:57:19 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 15:31:48 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

#ifndef HUMAIN_H
# define HUMAIN_H


class Human {

    public:

    Human(void);
    ~Human(void);



    const Brain& getBrain();
    std::string identify() const;
    
    private:
    const Brain     _attr_Brain;


};

#endif