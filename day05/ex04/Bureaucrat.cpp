/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:12:55 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/09 17:22:48 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
//*************************//
//****** BUREAUCRAT *******//
//*************************//

// Cannonic
//------------------
// Constructor void
Bureaucrat::Bureaucrat(void)
{
    std::cout << "Create Bureaucrat" << std::endl;
    return;
}
// Constuctor return src (not deep)
Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
    *this = src;
    return;
}
// Detroy constructor
Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Delete Bureaucrat" << std::endl;
    return;
}
// Operator = return only grade, name is const
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    this->_grade = rhs._grade;
    return (*this);
}
//----Special Constructor -----//
Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;
    return;
}

// Functions GET
//------------------
// Get Name
std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}
// Get Grade
int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

// Operator Class
//------------------
// Operator +=
void Bureaucrat::upgrade()
{
    if ((this->_grade - 1) < 1)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade -=  1;
}
// Operator -=
void Bureaucrat::downgrade()
{
    if ((this->_grade + 1) > 150)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade += 1;
}

void        Bureaucrat::signForm(Form &src)  {

    src.beSigned(*this);
}

// EXECUTE FORM PROGRAMME
void Bureaucrat::executeForm(Form const &form)
{
    if (this->_grade <= form.getExecGrade())
    {
        std::cout << "Bureaucrat " << this->_name << " executes " << form.getName() << std::endl;
        form.execute(*this);
    }
    else
        std::cout << "Bureaucrat " << this->_name << " grade is too low (" << this->_grade << "). They need a grade of "
                  << form.getExecGrade() << " to execute " << form.getName() << std::endl;
    return;
}

//**************************//
//***** EXEPTION ERROR *****//
//**************************//

/*
** GradeTool LOW **
*/
Bureaucrat::GradeTooLowException::GradeTooLowException(void) throw()
{
    return;
}
Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src) throw()
{
    *this = src;
    return;
}
Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw()
{
    return;
}
Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &rhs) throw()
{
    (void)rhs;
    if (this != &rhs)
    {
    }
    return (*this);
}
// Function WHAT for Low
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Error: Grade too low (> 150)");
}

//---------------------------------------------------//

/*
** GradeTool HIGHT **
*/
Bureaucrat::GradeTooHighException::GradeTooHighException(void) throw()
{
    // std::cout << "Exeption Grade to Hight create " << std::endl;
    return;
}
Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src) throw()
{
    *this = src;
    return;
}
Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw()
{
    return;
}
Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &rhs) throw()
{
    (void)rhs;
    // std::cout << "Exeption Grade egale " << std::endl;
    if (this != &rhs)
    {
    }
    return (*this);
}
// Function WHAT for Hight
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Error: Grade too high (< 1)");
}

//--------------------------------------//

// Out Of Class
//-----------------
// Operator <<
std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
    o << COLOR_BLUE "<" << rhs.getName() << ">, bureaucrat grade <" << rhs.getGrade() << ">" << COLOR_RESET << std::endl;
    return (o);
}