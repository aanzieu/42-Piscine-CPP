/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:23:15 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/08 22:17:15 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat zaz("Zaz", 5);
	std::cout << "Bureaucrat zaz, grade 5" << std::endl
			  << zaz;

	Form form("42 First Intership", 7, 7);
	std::cout << "Created Form" << COLOR_YELLOW << "<42 First Intership> " << COLOR_RESET << "with sign & exec requirement 7" << std::endl
			  << form << std::endl;

	std::cout << "Zaz try signing" << std::endl;
	try
	{
		form.beSigned(zaz);

		std::cout << std::endl
				  << "Zaz try signing it again" << std::endl;
		form.beSigned(zaz);
		std::cout << std::endl
				  << "Zaz don't remenber if he signed or not" << std::endl;
		form.beSigned(zaz);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << std::endl
			  << "---------------------" << std::endl
			  << std::endl;
	std::cout << std::endl
			  << "Create forms with 0 and 151 grade error catch" << std::endl;
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
	std::cout << std::endl
			  << "---------------------" << std::endl
			  << std::endl;

	std::cout << std::endl
			  << "New Bureaucrat Ol with grade 100 and new form with requirement grade 50 or higher"
			  << std::endl
			  << std::endl;

	try
	{
		Bureaucrat ol("Ol", 100);
		std::cout << ol;

		Form form3("42 Final Intership", 50, 50);
		std::cout << form3;

		form3.beSigned(ol);
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