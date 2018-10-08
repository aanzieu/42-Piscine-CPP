/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 21:45:03 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/08 22:21:25 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//************************//
//****** FORM ROBOT*******//
//************************//

// Cannonic
//------------------
// Constructor void
// RobotomyRequestForm::RobotomyRequestForm(void) : Form()
// {
//     return;
// }
RobotomyRequestForm::RobotomyRequestForm(std::string name) : Form(name, 72, 45)
{
    return;
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form(src.getName(), 72, 45)
{
    *this = src;
    return;
}
RobotomyRequestForm::~RobotomyRequestForm(void)
{
    return;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &r)
{
    (void)r;
    return (*this);
}

// Functions
//------------------
// Form Robotomy Execute
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    static int i = 0;

    if ((this->getSigned() == true) && (executor.getGrade() <= this->getExecGrade()))
    {
        if (i % 2 == 0)
        {
            system("afplay transmission.mp3 &");
            std::cout << COLOR_GREEN << "<" << executor.getName() << ">" << COLOR_RESET << " has been robotomized successfully" << std::endl;
        }
        else
            std::cout << COLOR_MAGENTA << "<" << executor.getName() << "<" << COLOR_RESET << " has failed to be robotomized" << std::endl;
        i = i + 1;
    }
    else if (this->getSigned() == false)
        std::cout << COLOR_RED << "You must signed this form first before continue and execute this form" << COLOR_RESET << std::endl;
    else
        throw Form::GradeTooLowException();
    return;
}

// DISPATCH Operator for Special Form ROBOTOMY
std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &r)
{
    o << COLOR_YELLOW << "Robotomy Request Form Details:" << COLOR_RESET << std::endl
      << "Name: " << COLOR_CYAN << r.getName() << COLOR_RESET << std::endl
      << "Signing Grade Requirement: " << COLOR_BLUE << r.getSignedGrade() << COLOR_RESET << std::endl
      << "Execution Grade Requirement: " << COLOR_MAGENTA << r.getExecGrade() << COLOR_RESET << std::endl;
    if (r.getSigned())
        o << COLOR_GREEN << "Form has been signed." << COLOR_RESET << std::endl;
    else
        o << COLOR_RED << "Form has not been signed yet." << COLOR_RESET << std::endl;
    return (o);
}