/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:23:15 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/09 11:25:01 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	//--------------------------FIRST////////////////////////////////
	Bureaucrat	zaz("Zaz", 1);
	Bureaucrat	noich("Noich", 150);

	std::cout << COLOR_YELLOW << "Bureaucrat Zaz, grade 1 " << std::endl << COLOR_RESET << zaz << std::endl <<
		COLOR_YELLOW << "Bureaucrat Noich, grade 150 " << std::endl << noich << COLOR_RESET << std::endl <<
		COLOR_MAGENTA << "******* Create Shrubbery Form < 42-InterShip >" << COLOR_RESET << std::endl;

	ShrubberyCreationForm intership("42-InterShip");
	std::cout << std::endl << intership << std::endl 
	<< "******* Test - Executing" << std::endl;
	intership.execute(zaz);

	//-----------------------------------------
	std::cout << std::endl 
	<< "******* Sign the form with Zaz and execute the form **" << std::endl;
	zaz.signForm(intership);
	zaz.executeForm(intership);
	
	//
	try
	{
		std::cout << std::endl
		<< "******* Try to execute form with Noich **" << std::endl;
		noich.executeForm(intership);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}






	//--------------------FIRTS //////////////////////////////
	std::cout << COLOR_MAGENTA <<std::endl << "******* Creating Form Robotomy < Robot >" << COLOR_RESET << std::endl;

	RobotomyRequestForm robot("Robot");
	std::cout << robot << std::endl 
	<< "******* Test - Executing **" << std::endl;

	robot.execute(zaz);

	std::cout << std::endl << "******* Sign the form with Zaz and execute the form twice " << std::endl;
	robot.beSigned(zaz);
	zaz.executeForm(robot);
	zaz.executeForm(robot);

	// TRY
	try
	{
		std::cout << std::endl 
		<< "******* Try to execute form with Noich **" << std::endl;
		noich.executeForm(robot);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	//---------------------------------- THRID
	std::cout << COLOR_MAGENTA << std::endl << "******* Create Presidential Pardon Form < Sorry, Sorry BOCALIENS > " << COLOR_RESET << std::endl;

	PresidentialPardonForm pres("Sorry, Sorry BOCALIENS");
	std::cout << pres << std::endl << "******* Executing form before signing, it will not work **" << std::endl;

	pres.execute(zaz);

	std::cout << std::endl << "******* Sign form with Zaz and execute the form" << std::endl;
	pres.beSigned(zaz);
	zaz.executeForm(pres);

	try
	{
		std::cout << std::endl << "******* Execute form with Noich" << std::endl;
		noich.executeForm(pres);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}