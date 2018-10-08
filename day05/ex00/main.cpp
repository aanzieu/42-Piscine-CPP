/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:23:15 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/08 17:40:29 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    // FIRST
    std::cout << "Try to created Bureaucrat Zaz " << std::endl
              << std::endl;
    try
    {
        Bureaucrat zaz("zaz", 0);;// = new Bureaucrat("zaz", 0);
        zaz.upgrade();
    }
    // catch (Bureaucrat::GradeTooHighException &e)
    // {
    // //         /* handle exception */
    //         std::cout << e.what() << std::endl;
    // }
    catch (std::exception const &e)
    {
        std::cout << e.what() << std::endl;
    }


    // SECOND
    int i = 0;
    int x = 0;
    std::cout << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << "Created Bureaucrat Zaz, provide an overload of the << operator to ostream" << std::endl
              << "and error, overide" << std::endl
              << std::endl;

    while (i++ < 5)
    {
        try
        {
            /* do some stuff with bureaucrats */
            if (i % 2 == 0)
                x = 0;
            else
                x = 151;
            Bureaucrat zaz("zaz", x);
            // std::cout << "std::cout " << zaz << std::endl;
        }
        catch (Bureaucrat::GradeTooHighException &e)
        {
            /* handle exception */
            std::cout << e.what() << std::endl;
        }
        catch (Bureaucrat::GradeTooLowException &e)
        {
            /* handle exception */
            std::cout << e.what() << std::endl;
        }
        catch (const std::exception &e)
        {
            /* handle exception */
            std::cout << "This is overead exeption" << e.what() << std::endl;
        }
    }


    std::cout << std::endl;
    std::cout << "----------" << std::endl;
   std::cout << "Created Bureaucrat Zaz, provide an overload of the << operator to ostream" << std::endl
              << "and error, overide" << std::endl
              << std::endl;
    try
    {
        Bureaucrat ol("Ol", 145);
        std::cout << ol;
        i = 1;
        while (i++ < 10)
        {
            std::cout << "Decremente " << ol.getName() << " grade." << std::endl;
            std::cout << "Ol grade:  " << ol.getGrade() << std::endl;
            ol.downgrade();
            std::cout << "New Grade: " << ol.getGrade() << " grade" << std::endl;
        }
        std::cout << ol;
        i = 150;
        while (i++ < 170)
        {
            std::cout << "Incremented " << ol.getName() << " grade." << std::endl;
            std::cout << "Ol grade:  " << ol.getGrade() << std::endl;
            ol.upgrade();
            std::cout << "New Grade: " << ol.getGrade() << " grade" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << " Exeption Catch " << std::endl;
    }

    return (0);
}