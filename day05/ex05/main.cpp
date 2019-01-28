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

#include "CentralBureaucracy.hpp"

int	main()
{


	CentralBureaucracy	centralOffice;
	std::cout << "** Made central Bureaucracy **" << std::endl;
	try
	{
		std::cout << std::endl 
		<< COLOR_YELLOW << " - Bureaucracy 1 (feed Signer)" << COLOR_RESET << std::endl;
		centralOffice.doBureaucracy();
		centralOffice.feedSigner(*new Bureaucrat("TOTO", 1));
		centralOffice.feedSigner(*new Bureaucrat("TATA", 4));
		centralOffice.feedSigner(*new Bureaucrat("TITI", 3));
		centralOffice.feedSigner(*new Bureaucrat("TUTU", 2));

		std::cout << std::endl
		<< COLOR_YELLOW << " - Bureaucracy 2 Do Bureaucracy" << COLOR_RESET << std::endl;
		centralOffice.doBureaucracy();

		std::cout << std::endl
		<< COLOR_YELLOW << " - Bureaucracy 3 - (feed Executeur)" << COLOR_RESET << std::endl;
		centralOffice.feedExecuter(*new Bureaucrat("LOLO",1));
		centralOffice.feedExecuter(*new Bureaucrat("LALAL",2));
		centralOffice.feedExecuter(*new Bureaucrat("LILIL",8));
		centralOffice.feedExecuter(*new Bureaucrat("LOULOU", 5));

		std::cout << std::endl
		<< COLOR_YELLOW << " - Bureaucracy 3 - (20)" << COLOR_RESET << std::endl;
		centralOffice.doBureaucracy();
		centralOffice.queueUp("Andre 1");
		centralOffice.queueUp("Andre 2");
		centralOffice.queueUp("Andre 3");
		centralOffice.queueUp("Andre 4 ");
		centralOffice.queueUp("Andre 5 ");
		centralOffice.queueUp("Andre 6");
		centralOffice.queueUp("Andre 7");
		centralOffice.queueUp("Andre 8");
		centralOffice.queueUp("Andre 9");
		centralOffice.queueUp("Andre 10");
		centralOffice.queueUp("Andre 11");
		centralOffice.queueUp("Andre 12");
		centralOffice.queueUp("Andre 13");
		centralOffice.queueUp("Andre 14 ");
		centralOffice.queueUp("Andre 15 ");
		centralOffice.queueUp("Andre 16 ");
		centralOffice.queueUp("Andre 17 ");
		centralOffice.queueUp("Andre 18 ");
		centralOffice.queueUp("Andre 19 ");
		centralOffice.queueUp("Andre 20 ");

		std::cout << COLOR_MAGENTA 
		<< std::endl << "** Making Bureaucracy do stuff, watch the magic! **" << COLOR_RESET 
		<< std::endl;
		centralOffice.doBureaucracy();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);













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