/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 21:11:34 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/08 22:21:18 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
//************************//
//****** FORM ROBOT*******//
//************************//

// Cannonic
//------------------
// ShrubberyCreationForm::ShrubberyCreationForm(void) : Form()
// {
//     return;
// }
ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : Form(name, 145, 137)
{
    return;
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src.getName(), 145, 137)
{
    *this = src;
    return;
}
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    return;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    (void)rhs;
    return (*this);
}

// Functions
//------------------
// EXECUTE PROGRAME
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if ((this->getSigned() == true) && (executor.getGrade() <= this->getExecGrade()))
    {
        std::string file = this->getName() + "_shrubbery";
        std::ofstream ofs(file);

        ofs << ""
               "                                                         ."
            << std::endl
            << std::endl
            << "          . . ." << std::endl
            << "        .        .  .     ..    ." << std::endl
            << "     .                 .         .  ." << std::endl
            << "                     ." << std::endl
            << "                    .                .." << std::endl
            << "    .          .            .              ." << std::endl
            << "    .            '.,        .               ." << std::endl
            << "    .              'b      *" << std::endl
            << "     .              '$    #.                .." << std::endl
            << "    .    .           $:   #:               ." << std::endl
            << "  ..      .  ..      *#  @):        .   . ." << std::endl
            << "               .     :@,@):   ,.**:'   ." << std::endl
            << "   .      .,         :@@*: ..**'      .   ." << std::endl
            << "            '#o.    .:(@'.@*§'  ." << std::endl
            << "    .  .       'bq,..:,@@*'   ,*      .  ." << std::endl
            << "               ,p$q8,:@)'  .p*'      ." << std::endl
            << "        .     '  . '@@Pp@@*'    .  ." << std::endl
            << "         .  . ..    Y7'.'     .  ." << std::endl
            << "                   :@):." << std::endl
            << "                  .:@:'." << std::endl
            << "                .::(@:.     " << std::endl
            << std::endl
            << std::endl
            << "          . . ." << std::endl
            << "        .        .  .     ..    ." << std::endl
            << "     .                 .         .  ." << std::endl
            << "                     ." << std::endl
            << "                    .                .." << std::endl
            << "    .          .            .              ." << std::endl
            << "    .            '.,        .               ." << std::endl
            << "    .              'b      *" << std::endl
            << "     .              '$    #.                .." << std::endl
            << "    .    .           $:   #:               ." << std::endl
            << "  ..      .  ..      *#  @):        .   . ." << std::endl
            << "               .     :@,@):   ,.**:'   ." << std::endl
            << "   .      .,         :@@*: ..**'      .   ." << std::endl
            << "            '#o.    .:(@'.@*§'  ." << std::endl
            << "    .  .       'bq,..:,@@*'   ,*      .  ." << std::endl
            << "               ,p$q8,:@)'  .p*'      ." << std::endl
            << "        .     '  . '@@Pp@@*'    .  ." << std::endl
            << "         .  . ..    Y7'.'     .  ." << std::endl
            << "                   :@):." << std::endl
            << "                  .:@:'." << std::endl
            << "                .::(@:.     " << std::endl;

        ofs.close();
        std::cout << COLOR_GREEN << "Shrubbery Form has been executed by " << COLOR_RESET << COLOR_MAGENTA << "<" << executor.getName() << "> " << COLOR_RESET << std::endl;
    }
    else if (this->getSigned() == false)
        std::cout << COLOR_RED << "You must signed this form first before continue and execute this form" << COLOR_RESET << std::endl;
    else
        throw Form::GradeTooLowException();
    return;
}

// Special Operator for Shurbbery Form
std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &r)
{
    o << COLOR_YELLOW << "Shrubbery Creation Form Details:" << COLOR_RESET << std::endl
      << "Name: " << COLOR_CYAN << r.getName() << COLOR_RESET << std::endl
      << "Signing Grade Requirement: " << COLOR_BLUE << r.getSignedGrade() << COLOR_RESET << std::endl
      << "Execution Grade Requirement: " << COLOR_MAGENTA << r.getExecGrade() << COLOR_RESET << std::endl;
    if (r.getSigned())
        o << COLOR_GREEN << "Form has been signed." << COLOR_RESET << std::endl;
    else
        o << COLOR_RED << "Form has not been signed yet." << COLOR_RESET << std::endl;
    return (o);
}