/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:42:24 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/09 16:48:33 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include "Bureaucrat.hpp"
#include "Form.hpp"

class Form;

class Intern
{
  public:
    Intern(void);
    Intern(Intern const &rhs);
    ~Intern(void);

    // Attributes

    // Member functions
    Form *          makeForm(std::string name, std::string const target) ;


    Form *          robotomyRequestForm(std::string const & target);
    Form *          shrubberyCreationForm(std::string const & target);
    Form *          presidentialPardonForm(std::string const & target);
    // Operators
    Intern &operator=(Intern const &rhs);

     class NoFormAvailableException : public std::exception
    {
      public:
        NoFormAvailableException(void) throw();
        NoFormAvailableException(NoFormAvailableException const &src) throw();
        virtual ~NoFormAvailableException(void) throw();
        NoFormAvailableException &operator=(NoFormAvailableException const &rhs) throw();
        virtual const char *what() const throw();
    };

  protected:
    // Attributes

    // Member functions

  private:
    // Attributes

    // Member functions
};
#endif