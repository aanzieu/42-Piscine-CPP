/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:48:22 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/08 17:21:19 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#define ANSI_COLOR_RED     "\33[31m"
#define ANSI_COLOR_GREEN   "\33[32m"
#define ANSI_COLOR_YELLOW  "\33[33m"
#define ANSI_COLOR_BLUE    "\33[34m"
#define ANSI_COLOR_MAGENTA "\33[35m"
#define ANSI_COLOR_CYAN    "\33[36m"
#define ANSI_COLOR_RESET   "\33[0m"

#include <iostream>

class Bureaucrat
{
  // Public informaton
  //------------------
public:
  // Canonic
  Bureaucrat(void);
  Bureaucrat(Bureaucrat const &src);
  virtual ~Bureaucrat(void);
  Bureaucrat &operator=(Bureaucrat const &r);

  // Other construtor
  Bureaucrat(std::string const name, int grade);

  // Operator
  void upgrade() ;
  void downgrade() ;

  // Get Function private informations
  std::string getName(void) const;
  int getGrade(void) const;

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
  std::string const _name;
  int _grade;
};

// Reference operator ostream out of class
std::ostream &operator<<(std::ostream &o, Bureaucrat const &r);

#endif