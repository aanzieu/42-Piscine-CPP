/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:52:24 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/09 14:32:39 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

//*******************//
//****** FORM *******//
//*******************//

// Cannonic
//------------------
// Constructor void
Form::Form(void) : _name("undefined"), _is_signed(false), _grade_to_signed(1), _grade_to_exec(1){
    return;
}
// Constuctor return src (not deep)
Form::Form(Form const & src) : _grade_to_signed(src._grade_to_signed), _grade_to_exec(src._grade_to_exec)
{
	*this = src;
	return;
}
// Detroy constructor
Form::~Form(void)
{
	return;
}
// Operator = return only signed, rest const
Form &Form::operator=(Form const &rhs) 
{
	this->_is_signed = rhs._is_signed;
	return (*this);
}


//----Special Constructor -----//
Form::Form(std::string const name, int grade_to_signed, int grade_to_exec) : _name(name), _is_signed(false), _grade_to_signed(grade_to_signed), _grade_to_exec(grade_to_exec)
{
	if (grade_to_signed < 1 || grade_to_exec < 1)
		throw Form::GradeTooHighException();
	else if (grade_to_signed > 150 || grade_to_exec > 150)
		throw Form::GradeTooLowException();
	return;
}

// Functions 
//------------------
// Sign Form
void				Form::signForm(void) 
{
	this->_is_signed = true;
	return;
}
// BeSigned
void				Form::beSigned(Bureaucrat const &rhs)
{
	if (rhs.getGrade() > this->_grade_to_signed)
	{
		std::cout << COLOR_RED << "<Bureaucrat " << rhs.getName() << "> cannot sign <" << this->_name << "> because " << COLOR_RESET;
		throw Form::GradeTooLowException();
	}
	else
	{
		if (this->_is_signed)
			std::cout << COLOR_RED << "<Bureaucrat " << rhs.getName() << "> cannot sign <" << this->_name << "> because form is already signed" << COLOR_RESET << std::endl;
		else
		{
			std::cout << COLOR_GREEN << "<Bureaucrat " << rhs.getName() << "> signs <" << this->_name << ">" << COLOR_RESET << std::endl;
			signForm();
		}
	}

}
// Getname
std::string			Form::getName(void) const
{
	return (this->_name);
}
// GetSigned
bool				Form::getSigned(void) const
{
	return (this->_is_signed);
}
// Get Signed Grade
int					Form::getSignedGrade(void) const
{
	return (this->_grade_to_signed);
}
// Get Exec Grade
int					Form::getExecGrade(void) const
{
	return	(this->_grade_to_exec);
}

// Other Return Form Control;

//--------------------------------------//

// Out Of Class
//-----------------
// Operator << completely describes the state of the form.
std::ostream			&operator<<(std::ostream &o, Form const & rhs)
{
	o << "Form Details :" << std::endl
			<< "Name: " << COLOR_CYAN << rhs.getName() << COLOR_RESET << std::endl
			<< "Signing Grade Requirement: " << COLOR_BLUE << rhs.getSignedGrade() << COLOR_RESET << std::endl
			<< "Execution Grade Requirement: " << COLOR_MAGENTA << rhs.getExecGrade() << COLOR_RESET << std::endl;
	if (rhs.getSigned())
			o << COLOR_GREEN << "Form has been signed." << COLOR_RESET << std::endl;
	else
			o << COLOR_RED << "Form has not been signed yet." << COLOR_RESET << std::endl;
	return (o);
}

//---------------------------------------------------//

//**************************//
//***** EXEPTION ERROR *****//
//**************************//

/*
** GradeTool HIGJT **
*/

Form::GradeTooHighException::GradeTooHighException(void) throw()
{
    // std::cout << "Exeption Grade to Hight create " << std::endl;
	return;
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src) throw()
{
	*this = src;
	return;
}

Form::GradeTooHighException::~GradeTooHighException(void) throw()
{
	return;
}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(GradeTooHighException const &rhs) throw() 
{
	(void)rhs;
	if (this != &rhs) {}
    // std::cout << "Exeption Grade egale " << std::endl;
	return (*this);
}
// Function WHAT for Hight
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form Error: Grade too high");
}
//---------------------------------------------------//

/*
** GradeTool LOW **
*/


Form::GradeTooLowException::GradeTooLowException(void)
{
	return;
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src)  throw()
{
	*this = src;
	return;
}

Form::GradeTooLowException::~GradeTooLowException(void) throw()
{
	return;
}

Form::GradeTooLowException &Form::GradeTooLowException::operator=(GradeTooLowException const &rhs) throw() 
{
    (void)rhs;
	if (this != &rhs) {}
	return (*this);
}

const char* Form::GradeTooLowException::what() const throw()
{
    // Function WHAT for Hight
	return ("Form Error: Grade too low");
}