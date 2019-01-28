/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.Tools.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 08:25:44 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/02 14:13:42 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_TOOLS_H
# define CLASS_TOOLS_H
#include <iostream>
#include "Class.Contacts.hpp"

class Tools {

    public:
        Tools(void); 
        ~Tools(void);

        static std::string& ltrim(std::string& str, std::string chars);
        static std::string& rtrim(std::string& str, std::string chars);
        static std::string& trim(std::string& str);
};

#endif