/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 11:48:33 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 15:32:03 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#ifndef BRAIN_H
# define BRAIN_H

class Brain {

    public:


        Brain(void);
        ~Brain(void);


    std::string			identify() const ;

    private:

    std::stringstream	_addr;
  

};

#endif