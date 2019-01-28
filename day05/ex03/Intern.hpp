/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:42:24 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/09 14:32:58 by aanzieu          ###   ########.fr       */
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

  protected:
    // Attributes

    // Member functions

  private:
    // Attributes

    // Member functions
};
#endif