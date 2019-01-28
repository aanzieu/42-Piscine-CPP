/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:23:15 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/09 10:55:16 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	//----------------------- FRIST ////////////////////////////
	Bureaucrat zaz("Zaz", 8);
	std::cout << "Bureaucrat zaz, grade 8" << std::endl
			  << "Get Info Bueraucrat : " << zaz << std::endl;

	Form form("42 First Intership", 7, 7);
	std::cout << "Created Form" << COLOR_YELLOW << " <42 First Intership> " << COLOR_RESET << "with sign & exec requirement 7" << std::endl
			  << form << std::endl;

	std::cout << std::endl
			  << "---------------------" << std::endl
			  << std::endl;

	std::cout << "Zaz try signing" << std::endl;

	try
	{
		form.beSigned(zaz);

		std::cout << std::endl
				  << "Zaz try signing it again" << std::endl;
		zaz.signForm(form);
		std::cout << std::endl
				  << "Zaz don't remenber if he signed or not" << std::endl;
		form.beSigned(zaz);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	//----------------------------------------Second ////////////////////////////////////
	std::cout << std::endl
			  << "---------------------" << std::endl
			  << std::endl;
	std::cout << std::endl
			  << "Create forms with 0 and 151 grade error catch" << std::endl
			  << std::endl;

	int i = 0;
	int x = 0;
	while (i++ < 10)
	{
		try
		{
			if (i % 2 == 0)
				x = 0;
			else
				x = 151;
			Form form_next("Error", x, x);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	//----------------------------------------Trhird ////////////////////////////////////
	std::cout << std::endl
			  << "---------------------" << std::endl
			  << std::endl;

	std::cout << std::endl
			  << "Bureaucrat Ol with grade 100 - form requirement 50"
			  << std::endl
			  << std::endl;
	i = 0;
	try
	{
		Bureaucrat ol("Ol", 100);
		std::cout << ol;

		Form form3("42 Final Intership", 50, 50);
		std::cout << form3 << std::endl;;

		while (i++ < 80)
		{	
			ol.upgrade();
			// ol.signForm(form3);
		}
		ol.signForm(form3);
		ol.signForm(form3);
		std::cout << std::endl << form3 << std::endl;
	}
	// catch (Form::GradeTooHighException &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// catch (Form::GradeTooLowException &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}