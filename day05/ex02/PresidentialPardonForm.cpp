/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 22:12:14 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/09 14:32:41 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//******************************//
//****** FORM PRESIDENTE *******//
//******************************//

// Cannonic
//------------------
// Constructor void
PresidentialPardonForm::PresidentialPardonForm(void) : Form()
{
    return;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, 72, 45)
{
    return;
}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form(src.getName(), 72, 45)
{
    *this = src;
    return;
}
PresidentialPardonForm::~PresidentialPardonForm(void)
{
    return;
}
// Operator for this;
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    (void)rhs;
    return (*this);
}

// Functions
//------------------
// Form Robotomy Execute
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if ((this->getSigned() == true) && (executor.getGrade() <= this->getExecGrade()))
        std::cout << COLOR_GREEN << executor.getName() << " has been pardoned by Zafod Beeblebrox" << COLOR_RESET << std::endl;
    else if (this->getSigned() == false)
        std::cout << COLOR_RED << "You must signed this form first before continue and execute this form" << COLOR_RESET << std::endl;
    else
        throw Form::GradeTooLowException();
    return;
}

// DISPATCH Operator for Special Form PRESIDENTE
std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &r)
{
    o << "Presidential Pardon Form Details:" << std::endl
      << "Name: " << COLOR_CYAN << r.getName() << COLOR_RESET << std::endl
      << "Signing Grade Requirement: " << COLOR_BLUE << r.getSignedGrade() << COLOR_RESET << std::endl
      << "Execution Grade Requirement: " << COLOR_MAGENTA << r.getExecGrade() << COLOR_RESET << std::endl;
    if (r.getSigned())
        o << COLOR_GREEN << "Form has been signed." << COLOR_RESET << std::endl;
    else
        o << COLOR_RED << "Form has not been signed yet." << COLOR_RESET << std::endl;
    return (o);
}