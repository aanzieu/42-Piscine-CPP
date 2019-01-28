/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 08:16:07 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/10 17:21:00 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
#define CONVERT_H

#include <iostream>
#include <exception>

class Convert
{
  // Public informaton
  //-----------
  public:
    Convert(void);
    Convert(char *input);
    Convert(Convert const &src);
    virtual ~Convert(void);
    // Operator
    Convert &operator=(Convert const &rhs);
    char *input;

    class ConvertErrorException : public std::exception
    {
      public:
          ConvertErrorException(void) throw();
        ConvertErrorException(ConvertErrorException const &src) throw();
        virtual ~ConvertErrorException(void) throw();
        ConvertErrorException &operator=(ConvertErrorException const &rhs) throw();
        virtual const char *what() const throw();
      };
    //member operator
    operator char(void) const;
    operator int(void) const;
    operator float(void) const;
    operator double(void) const;

};
#endif
