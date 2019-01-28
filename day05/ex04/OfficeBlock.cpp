/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:16:51 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/09 17:17:18 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

//*******************//
//****** FORM *******//
//*******************//

// Cannonic
//------------------
// Constructor void
OfficeBlock::OfficeBlock(void) : _intern(NULL), _signer(NULL), _executer(NULL)
{
    return;
}
// Special construct
OfficeBlock::OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executer) : _intern(&intern), _signer(&signer), _executer(&executer)
{
    return;
}
// Destroy
OfficeBlock::~OfficeBlock(void)
{
    // if(this->_executer)
    //     delete _executer;
    // if(this->_intern)
    //     delete _intern;
    // if(this->_signer)
    //     delete _signer;
    return;
}
void OfficeBlock::doBureaucracy(std::string form, std::string target)
{
    // Check Inter or return
    if (!this->_intern)
    {
        throw OfficeBlock::NoInternException();
        return;
    }
    if (!this->_signer)
    {
        throw OfficeBlock::NoSignerException();
        return;
    }
    if (!this->_executer)
    {
        throw OfficeBlock::NoExecuterException();
        return;
    }

   
        Form *formulaire;
        // Create form by intern
        if((formulaire = this->_intern->makeForm(form, target)) == NULL){
            std::cout << COLOR_BLUE << "ATTENTION" << std::endl;
            throw Intern::NoFormAvailableException();
            return ;
        }
        // Create form by intern
        // if (this->_signer->getGrade() > formulaire->getSignedGrade())
        // {
        //     if (formulaire)
        //         delete formulaire;
        //     throw OfficeBlock::SignerLowGradeException();
        //     return;
        // }
        if(formulaire)
            this->_signer->signForm(*formulaire);
        // formulaire->beSigned();

        // if (this->_signer->getGrade() > formulaire->getExecGrade())
        // {
            // if (formulaire)
                // delete formulaire;
            // throw OfficeBlock::ExecuterLowGradeException();
            // return;
        // }
        if(formulaire)
            this->_executer->executeForm(*formulaire);
        if(formulaire != NULL)
            delete formulaire;
    return;
}

// Set Method office
void OfficeBlock::setIntern(Intern &src)
{
    this->_intern = &src;
    return;
}
void OfficeBlock::setSigner(Bureaucrat &src)
{
    this->_signer = &src;
    return;
}
void OfficeBlock::setExecutor(Bureaucrat &src)
{
    this->_executer = &src;
    return;
}

//---------------------------------------------------//

//**************************//
//***** EXEPTION ERROR *****//
//**************************//

/*
** Inter Exeption **
*/

OfficeBlock::NoInternException::NoInternException(void) throw()
{
    return;
}
OfficeBlock::NoInternException::NoInternException(NoInternException const &src) throw()
{
    *this = src;
    return;
}
OfficeBlock::NoInternException::~NoInternException(void) throw()
{
    return;
}
OfficeBlock::NoInternException &OfficeBlock::NoInternException::operator=(NoInternException const &r) throw()
{
    (void)r;
    return (*this);
}
const char *OfficeBlock::NoInternException::what() const throw()
{
    return ("OfficeBlock Error: No Intern");
}

/*
** NoSignerException
*/

OfficeBlock::NoSignerException::NoSignerException(void) throw()
{
    return;
}
OfficeBlock::NoSignerException::NoSignerException(NoSignerException const &src) throw()
{
    *this = src;
    return;
}
OfficeBlock::NoSignerException::~NoSignerException(void) throw()
{
    return;
}
OfficeBlock::NoSignerException &OfficeBlock::NoSignerException::operator=(NoSignerException const &r) throw()
{
    (void)r;
    return (*this);
}
const char *OfficeBlock::NoSignerException::what() const throw()
{
    return ("OfficeBlock Error: No Signer");
}

/*
** NoExecuterException 
*/
OfficeBlock::NoExecuterException::NoExecuterException(void) throw()
{
    return;
}
OfficeBlock::NoExecuterException::NoExecuterException(NoExecuterException const &src) throw()
{
    *this = src;
    return;
}
OfficeBlock::NoExecuterException::~NoExecuterException(void) throw()
{
    return;
}
OfficeBlock::NoExecuterException &OfficeBlock::NoExecuterException::operator=(NoExecuterException const &r) throw()
{
    (void)r;
    return (*this);
}
const char *OfficeBlock::NoExecuterException::what() const throw()
{
    return ("OfficeBlock Error: No Executor ");
}

/*
** SignerLowGradeException 
*/

OfficeBlock::SignerLowGradeException::SignerLowGradeException(void) throw()
{
    return;
}
OfficeBlock::SignerLowGradeException::SignerLowGradeException(SignerLowGradeException const &src) throw()
{
    *this = src;
    return;
}
OfficeBlock::SignerLowGradeException::~SignerLowGradeException(void) throw()
{
    return;
}
OfficeBlock::SignerLowGradeException &OfficeBlock::SignerLowGradeException::operator=(SignerLowGradeException const &r) throw()
{
    (void)r;
    return (*this);
}
const char *OfficeBlock::SignerLowGradeException::what() const throw()
{
    return ("OfficeBlock Error: Signer's Grade too low to sign this form");
}

/*
** ExecuterLowGradeException 
*/

OfficeBlock::ExecuterLowGradeException::ExecuterLowGradeException(void) throw()
{
    return;
}
OfficeBlock::ExecuterLowGradeException::ExecuterLowGradeException(ExecuterLowGradeException const &src) throw()
{
    *this = src;
    return;
}
OfficeBlock::ExecuterLowGradeException::~ExecuterLowGradeException(void) throw()
{
    return;
}
OfficeBlock::ExecuterLowGradeException &OfficeBlock::ExecuterLowGradeException::operator=(ExecuterLowGradeException const &r) throw()
{
    (void)r;
    return (*this);
}
const char *OfficeBlock::ExecuterLowGradeException::what() const throw()
{
    return ("OfficeBlock Error: Excecuteur's Grade too low for this form");
}