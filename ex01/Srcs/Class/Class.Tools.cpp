/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.Tools.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 08:25:11 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/02 11:30:59 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/Class.Tools.hpp"
#include "../../Includes/Class.Contacts.hpp"

// Destroy Instance
Tools::Tools(void){
    return;
}

// Destroy Instance
Tools::~Tools(void){
    return;
}

std::string& Tools::ltrim(std::string& str, std::string chars)
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}
 
std::string& Tools::rtrim(std::string& str, std::string chars)
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}
 
std::string& Tools::trim(std::string& str)
{
    std::string chars = "\t\n\v\f\r ";
    return ltrim(rtrim(str, chars), chars);
}
