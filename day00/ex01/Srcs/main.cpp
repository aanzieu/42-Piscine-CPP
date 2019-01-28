/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:44:19 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/02 15:58:42 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
#include "../Includes/Class.Contacts.hpp"
#include "../Includes/Class.Tools.hpp"

static inline bool exit_option()
{
    std::string response;
    std::cout << "Are you sure you want to exit? Nothing will be saved." << std::endl;
    std::cout << "Enter YES to exit program, all other input will not quit." << std::endl;
    std::cout << "> ";
    if (!std::getline(std::cin, response))
    {
        std::cout << "Good bye." << std::endl;
        exit(-1);
    }
    else if (!response.compare("YES"))
    {
        std::cout << "Goodbye" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Restart Command :)" << std::endl;
        return false;
    }
}

std::string check_length(Contacts *instance, int i, int x)
{
    std::string input = instance[i].get_contact(x);
    int a = input.length();

    if (a > 10)
    {
        input.erase(9, a);
        std::cout << input;
        return (".");
    }
    while (a++ < 10)
        std::cout << " ";
    return (input);
}

static inline bool searh_option(Contacts *instances)
{
    int i = 0;
    std::string output;
    std::string response;
    std::stringstream number;
    bool bol = false;
    int num = 0;

    if (Contacts::getNbrContact() == 0)
    {
        std::cout << "Sorry, there are no contacts here" << std::endl;
        return false;
    }
    std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
    while (i < Contacts::getNbrContact())
    {
        std::cout << "|" << std::setw(10) << (i + 1) << "|";
        output = check_length(instances, i, 0);
        std::cout << output << "|";
        output = check_length(instances, i, 1);
        std::cout << output << "|";
        output = check_length(instances, i, 2);
        std::cout << output << "|" << std::endl;
        i++;
    }
    std::cout << std::endl;
    std::cout << "Which contact would you like to look? enter the index number." << std::endl;
    while (!bol)
    {
        std::cout << "< ";
        if (!std::getline(std::cin, response))
        {
            std::cout << "Good bye." << std::endl;
            exit(-1);
        }
        else
        {
            number.clear();
            number.str(response);
            number >> num;
            if (num <= Contacts::getNbrContact() && num > 0)
            {
                instances[num - 1].display_info();
                bol = true;
            }
            else
            {
                std::cout << "No Valid Number" << std::endl;
            }
        }
    }
    return false;
}

void check_string_exact(Contacts *instance, std::string type, int i, bool check)
{
    std::string response;

    while (!check)
    {
        std::cout << type;
        if (!std::getline(std::cin, response))
        {
            std::cout << "Good bye." << std::endl;
            exit(-1);
        }
        else
        {
            Tools::trim(response);
            if (response.length() > 0)
            {
                instance->set_contact(response, i);
                check = true;
            }
            else
            {
                std::cout << "Nothing enter retry" << std::endl;
            }
        }
    }
}

static inline bool add_option(Contacts *instances)
{

    std::string response;
    int i = 0;
    int j;
    j = Contacts::getNbrContact();

    if (j < 8)
    {
        std::cout << "Please enter the following details for contact:" << std::endl;
        check_string_exact(&(instances)[j], "> First Name: ", i++, false);
        check_string_exact(&(instances)[j], "> Last Name: ", i++, false);
        check_string_exact(&(instances)[j], "> Nickname: ", i++, false);
        check_string_exact(&(instances)[j], "> Login: ", i++, false);
        check_string_exact(&(instances)[j], "> Address: ", i++, false);
        check_string_exact(&(instances)[j], "> Email: ", i++, false);
        check_string_exact(&(instances)[j], "> Phone number: ", i++, false);
        check_string_exact(&(instances)[j], "> Birth Day: ", i++, false);
        check_string_exact(&(instances)[j], "> Meal: ", i++, false);
        check_string_exact(&(instances)[j], "> Your secret: ", i++, false);
        std::cout << " ---------------------- " << std::endl;
        std::cout << " - Successfully added ---> " << instances[j].get_contact(0) << " " << instances[j].get_contact(1) << std::endl;
        std::cout << " ---------------------- " << std::endl;
        instances->add_contact();
    }
    else
    {
        std::cout << "already " << Contacts::getNbrContact() << " contacts exist, sorry !" << std::endl;
    }
    return false;
}

static inline bool check_options(std::string option, Contacts *instances)
{

    if (!option.compare("ADD"))
    {
        return add_option(instances);
    }
    else if (!option.compare("SEARCH"))
    {
        return searh_option(instances);
    }
    else if (!option.compare("EXIT"))
    {
        return exit_option();
    }
    else
    {
        std::cout << "Error, bad input" << std::endl;
        return false;
    }
}

int main()
{
    Contacts instances[8];
    std::string option;

    std::cout << "Welcome on Best PhoneBook of the World ! " << std::endl;
    std::cout << "What you want to do ?" << std::endl;
    while (1)
    {
        std::cout << "Choose: ADD, SEARCH, EXIT" << std::endl;
        std::cout << "> ";
        if (!std::getline(std::cin, option))
        {
            std::cout << "Good bye." << std::endl;
            return (0);
        }
        else
        {
            if (check_options(Tools::trim(option), instances))
            {
                return 0;
            }
        }
    }
    return 0;
}