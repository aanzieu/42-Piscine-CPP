/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:48:22 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/09 12:16:32 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;


class Form
{
    // Public informaton
    //------------------
  public:
    // Canonic
    Form(void);
    Form(Form const &src);
    virtual ~Form(void);
    Form &operator=(Form const &r);

    // Other construtor
    Form(std::string const name, int grade_to_signed, int garde_to_exec);

    // Operator
    void upgrade();
    void downgrade();

    // Abastract
		virtual void 		execute(Bureaucrat const &obj) const = 0;

    // Get Function private informations
    std::string			getName(void) const;
    bool				    getSigned(void) const;
    int					    getSignedGrade(void) const;
    int					    getExecGrade(void) const;

    void				    signForm(void);
    void				    beSigned(Bureaucrat const & r);

    // Form request
   

    // Exeption class public
    class GradeTooHighException : public std::exception
    {
      public:
        // Canonical
        GradeTooHighException(void) throw();
        GradeTooHighException(GradeTooHighException const &src) throw();
        virtual ~GradeTooHighException(void) throw();
        GradeTooHighException &operator=(GradeTooHighException const &rhs) throw();
        // Return throw for Grade Tool Hight Exeption
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      public:
        GradeTooLowException(void);
        GradeTooLowException(GradeTooLowException const &obj) throw();
        virtual ~GradeTooLowException(void) throw();
        GradeTooLowException &operator=(GradeTooLowException const &r) throw();

        // Return throw for Grade Tool Low Exeption
        virtual const char *what() const throw();
    };

    // Private information
    //------------------
  private:
    std::string const    _name;
    bool                _is_signed;
    int const           _grade_to_signed;
    int const           _grade_to_exec;
};

// Reference operator ostream out of class
std::ostream &operator<<(std::ostream &o, Form const &r);

#endif