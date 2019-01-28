/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 08:20:06 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/10 17:19:33 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert(char *input) : input(input)
{
    return;
}
Convert::Convert(Convert const &src)
{
    *this = src;
    return;
}
Convert::~Convert(void)
{
    return;
}

// Operator
Convert &Convert::operator=(Convert const &r)
{
    this->input = r.input;
    return (*this);
}

// Operator
// Convert Catch Error And Cast
Convert::operator char(void) const
{
    int ret = 0;
    try
    {
        ret = std::strtod(this->input, NULL);
    }
    catch (const std::exception &e)
    {
        throw(ConvertErrorException());
    }
    return (static_cast<char>(ret));
}

Convert::operator int(void) const
{
    int ret = 0;
    try
    {
        ret = std::strtod(this->input, NULL);
    }
    catch (const std::exception &e)
    {
        throw(ConvertErrorException());
    }
    return (ret);
}

Convert::operator float(void) const
{
    double ret = 0.0;
    try
    {
        ret = std::strtod(this->input, NULL);
    }
    catch (const std::exception &e)
    {
        throw(ConvertErrorException());
    }
    return (ret);
}

Convert::operator double(void) const
{
    float ret = 0.0;
    try
    {
        ret = std::strtod(this->input, NULL);
    }
    catch (const std::exception &e)
    {
        throw(ConvertErrorException());
    }
    return (ret);
}

// Exception Convert
//-------------------*/
Convert::ConvertErrorException::ConvertErrorException(void) throw()
{
    return;
}
Convert::ConvertErrorException::ConvertErrorException(ConvertErrorException const &src) throw()
{
    *this = src;
    return;
}
Convert::ConvertErrorException::~ConvertErrorException(void) throw()
{
    return;
}
Convert::ConvertErrorException &Convert::ConvertErrorException::operator=(ConvertErrorException const &r) throw()
{
    (void)r;
    return (*this);
}
const char *Convert::ConvertErrorException::what() const throw()
{
    return ("impossible");
}