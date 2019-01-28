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

int	main()
{
	//--------------------------FIRST////////////////////////////////
	Bureaucrat	zaz("Zaz", 1);
	Bureaucrat	noich("Noich", 150);
	////////////
	std::cout << COLOR_YELLOW << "******* Bureaucrat Zaz, grade 1 " << std::endl
	<< COLOR_RESET << zaz
	<< std::endl << COLOR_YELLOW <<	"******* Bureaucrat Noich, grade 150 " << std::endl
	<< COLOR_RESET << noich << std::endl;

	Intern	intern;
	///////////////
	std::cout << COLOR_MAGENTA << "******* new Intern, proceed to make forms " << std::endl
	<< COLOR_RESET << std::endl;
	// FIRST FORM
	Form	*form_zaz;
	std::cout << "******* Shrubbery Creation form with target lov_tree with Intern " << std::endl;
	form_zaz = intern.makeForm("shrubbery request", "lov_tree");

	std::cout << *form_zaz << std::endl;
	std::cout << COLOR_BLUE << "******* Zaz signe the form,Noich execute form " << COLOR_RESET << std::endl;
	zaz.signForm(*form_zaz);
	noich.executeForm(*form_zaz);


	// SECONT FORM
	Form	*form_noich;

	std::cout << std::endl << "******* Creating Robotomy Request form with target " << std::endl;
	form_noich = intern.makeForm("robotomy request", "kevin");

	std::cout << *form_noich << std::endl;
	std::cout << COLOR_BLUE << "******* Zaz signe form,Noich execute form " << COLOR_RESET << std::endl;
	form_noich->beSigned(zaz);
	noich.executeForm(*form_noich);

	Form	*form_zaz2;

	std::cout << std::endl << "******* Creating Presidential Pardon form with target" << std::endl;
	form_zaz2 = intern.makeForm("presidential pardon", "macon");

	std::cout << *form_zaz2 << std::endl;
	std::cout << COLOR_BLUE << "******* Zaz signe the form, Noich execute form " << COLOR_RESET << std::endl;
	form_zaz2->beSigned(zaz);
	noich.executeForm(*form_zaz2);
	zaz.executeForm(*form_zaz2);
	std::cout << *form_zaz2 << std::endl;

	Form *form_zaz3;
	std::cout << COLOR_BLUE << std::endl << "******* Creating Non Existent form with target Whatever with Intern, should fail " <<
	COLOR_RESET << std::endl;

	form_zaz3 = intern.makeForm("Non Existent", "Whatever");

	std::cout << form_zaz3 << std::endl;
	// delete form_zaz;
	// delete form_noich;
	// delete form_zaz2;
	// delete form_zaz3;

	return (0);
}