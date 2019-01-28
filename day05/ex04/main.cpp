/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*    2018/10/08 12:23:15 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/09 12:32:15 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int	main()
{

	//--------------------------FIRST////////////////////////////////
	Bureaucrat	zaz("Zaz", 45);
	Bureaucrat	noich("Noich", 110);
	////////////
	std::cout << COLOR_YELLOW << "******* Bureaucrat Zaz, grade 50 " << std::endl
	<< COLOR_RESET << zaz
	<< std::endl << COLOR_YELLOW <<	"******* Bureaucrat Noich, grade 110 " << std::endl
	<< COLOR_RESET << noich << std::endl;

	Intern	intern;
	///////////////
	std::cout << COLOR_MAGENTA << "******* new Intern, for our BEAUTIFUL OFFICE !!! BUT not arrived" << std::endl
	<< COLOR_RESET << std::endl;
	
	// FIRST FORM
	try
	{
		OfficeBlock ob;
		ob.setSigner(zaz);
		ob.setExecutor(noich);
		std::cout << std::endl << "******* DoBureaucracy 1 *******" << std::endl;
		ob.doBureaucracy("shrubbery request", "ballshits");
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		// return(0);
	}


	std::cout << std::endl << "******* Intern ARRIVED YOUPPI" << std::endl;

	try
	{	
		OfficeBlock ob;
		ob.setSigner(zaz);
		ob.setExecutor(noich);
		ob.setIntern(intern);
		std::cout << std::endl << "******* DoBureaucracy 2 *******" << std::endl;
		ob.doBureaucracy("shrubbery request", "ballshits");
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		// return(0);
	}


	try
	{
		OfficeBlock ob;
		ob.setSigner(zaz);
		ob.setExecutor(noich);
		ob.setIntern(intern);
		std::cout << std::endl << "******* DoBureaucracy 3 *******" << std::endl;
		ob.doBureaucracy(" request", "ballshits");
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		// return (0);
	}


	try
	{
		OfficeBlock ob;
		ob.setSigner(zaz);
		ob.setExecutor(zaz);
		ob.setIntern(intern);
		std::cout << std::endl << "******* DoBureaucracy 4 *******" << std::endl;
		ob.doBureaucracy("robotomy request", "ballshits");
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		// return (0);
	}


	// try
	// {
	// 	std::cout << std::endl << "******* DoBureaucracy *******" << std::endl;
	// 	ob.doBureaucracy("shrubbery request", "ballshits");
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	return (0);
}