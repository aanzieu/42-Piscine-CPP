/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:15:05 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/09 17:36:24 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_H
#define OFFICEBLOCK_H

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

class OfficeBlock
{
  // Public informaton
  //------------------
public:
  // Canonic
  OfficeBlock(void);
  OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executer);
  virtual ~OfficeBlock(void);
  // SET Private
  void setIntern(Intern &src);
  void setSigner(Bureaucrat &src);
  void setExecutor(Bureaucrat &src);
  // Get IPntern
  int getIntern(void);
  int getSigner(void);
  int getExecuter(void);

  //To Attrib Signer and Executer
  Bureaucrat attribSigner(void);
  Bureaucrat attribExecuter(void);

  int getAll(void);
  void doBureaucracy(std::string form, std::string target);

  // Exeption class public NO INTERN
  class NoInternException : public std::exception
  {
  public:
    NoInternException(void) throw();
    NoInternException(NoInternException const &src) throw();
    virtual ~NoInternException(void) throw();
    NoInternException &operator=(NoInternException const &rhs) throw();
    virtual const char *what() const throw();
  };
  // Exeption class public NO SIGNER
  class NoSignerException : public std::exception
  {
  public:
    NoSignerException(void) throw();
    NoSignerException(NoSignerException const &src) throw();
    virtual ~NoSignerException(void) throw();
    NoSignerException &operator=(NoSignerException const &rhs) throw();
    virtual const char *what() const throw();
  };
  // Exeption class public NO EXECUTER
  class NoExecuterException : public std::exception
  {
  public:
    NoExecuterException(void) throw();
    NoExecuterException(NoExecuterException const &src) throw();
    virtual ~NoExecuterException(void) throw();
    NoExecuterException &operator=(NoExecuterException const &rhs) throw();
    virtual const char *what() const throw();
  };
  // Exeption class public SIGNER Low
  class SignerLowGradeException : public std::exception
  {
  public:
    SignerLowGradeException(void) throw();
    SignerLowGradeException(SignerLowGradeException const &src) throw();
    virtual ~SignerLowGradeException(void) throw();
    SignerLowGradeException &operator=(SignerLowGradeException const &rhs) throw();
    virtual const char *what() const throw();
  };
  // Exeption class public EXECUTER Low
  class ExecuterLowGradeException : public std::exception
  {
  public:
    ExecuterLowGradeException(void) throw();
    ExecuterLowGradeException(ExecuterLowGradeException const &src) throw();
    virtual ~ExecuterLowGradeException(void) throw();
    ExecuterLowGradeException &operator=(ExecuterLowGradeException const &rhs) throw();
    virtual const char *what() const throw();
  };

private:
  OfficeBlock(OfficeBlock &src);
  // Operator
  OfficeBlock &operator=(OfficeBlock const &rhs);
  //
  Intern *_intern;
  Bureaucrat *_signer;
  Bureaucrat *_executer;
};

#endif