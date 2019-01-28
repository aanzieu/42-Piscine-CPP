/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 17:31:19 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/09 17:53:49 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "OfficeBlock.hpp"

CentralBureaucracy::CentralBureaucracy(void)
{
    srand(time(0));
    Intern uckinstagiaire;

    int i = 0;

    while (i < 20)
    {
        _OfficeBlock[i].setIntern(uckinstagiaire);
        i++;
    }
    return;
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy &src)
{
    *this = src;
    return;
}

CentralBureaucracy::~CentralBureaucracy(void)
{
    return;
}

CentralBureaucracy &CentralBureaucracy::operator=(CentralBureaucracy &rhs)
{
    int i = 0;
    Bureaucrat *copy = new Bureaucrat;

    while (rhs._target[i] != "")
    {
        this->_target[i] = rhs._target[i];
        i++;
    }

    i = 0;
    while (rhs._OfficeBlock[i].getSigner() == 1)
    {
        *copy = rhs._OfficeBlock[i].attribSigner();
        _OfficeBlock[i].setSigner(*copy);
        i++;
    }

    i = 0;
    while (rhs._OfficeBlock[i].getExecuter() == 1)
    {
        *copy = rhs._OfficeBlock[i].attribExecuter();
        _OfficeBlock[i].setExecutor(*copy);
        i++;
    }

    delete copy;
    return (*this);
}

void CentralBureaucracy::doBureaucracy(void)
{
    int i = 0;
    int x = 0;
    std::string input[] = {
        "robotomy request",
        "shrubbery request",
        "presidential pardon"};

    if (_target[0] == "")
    {
        std::cout << "No targets queue'd" << std::endl;
        return;
    }
    while (_target[i] != "")
    {
        x = rand() % 20;
        if (_OfficeBlock[x].getAll() == 1)
        {
            _OfficeBlock[x].doBureaucracy(input[x % 3], _target[i]);
            i++;
            std::cout << std::endl;
        }
    }
    std::cout << std::endl
              << "Completed All" << std::endl;
}

void CentralBureaucracy::feedSigner(Bureaucrat &obj)
{
    int i = 0;

    while (i < 20)
    {
        if (_OfficeBlock[i].getSigner() == 0)
        {
            _OfficeBlock[i].setSigner(obj);
            return;
        }
        i++;
    }
    std::cout << "Central Bureaucracy is full, cannot add more Signers" << std::endl;
    return;
}

void CentralBureaucracy::feedExecuter(Bureaucrat &obj)
{
    int i = 0;

    while (i < 20)
    {
        if (_OfficeBlock[i].getExecuter() == 0)
        {
            _OfficeBlock[i].setExecutor(obj);
            return;
        }
        i++;
    }
    std::cout << "Central Bureaucracy is full, cannot add more Executer" << std::endl;
    return;
}

void CentralBureaucracy::queueUp(std::string obj)
{
    int i = 0;

    while (i < 100)
    {
        if (_target[i] == "")
        {
            _target[i] = obj;
            return;
        }
        i++;
    }
    std::cout << "Only 100 targets can be queue'd" << std::endl;
    return;
}
