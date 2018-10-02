/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.Contacts.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:55:39 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/02 14:13:20 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/Class.Contacts.hpp"


// Create Instance
Contacts::Contacts(void){
    // Contacts::_nbrcontact +=1;
    return;
}

// Destroy Instance
Contacts::~Contacts(void){
    // Contacts::_nbrcontact -=1;
    return;
}


void            Contacts::display_info()  {
	std::cout << "First Name: " << this->_firstname << std::endl;
	std::cout << "Last Name: " << this->_lastname << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Login: " << this->_login << std::endl;
	std::cout << "Postal Address: " << this->_address << std::endl;
	std::cout << "Email Address: " << this->_email << std::endl;
	std::cout << "Phone Number: " << this->_phone << std::endl;
	std::cout << "Favorite Meal: " << this->_meal << std::endl;
	std::cout << "Secret User: " << this->_secret << std::endl;
}

// Set Contact instance
void Contacts::add_contact(){
    Contacts::_nbrcontact +=1;
}

void            Contacts::set_contact(std::string input, int i) {


    switch ( i ) {
    case 0:     
		this->_firstname = input;
        break;
    case 1:     
		this->_lastname = input;
        break;
    case 2:    
		this->_nickname = input;
        break;
    case 3:    
		this->_login = input;
        break;
    case 4:    
		this->_address = input;
        break;
    case 5:    
		this->_email = input;
        break;
    case 6:    
		this->_phone = input;
        break;
    case 7:    
		this->_birthday = input;
        break;
    case 8:    
		this->_meal = input;
        break;
    case 9:    
		this->_secret = input;
        break;
    default:
        std::cout<<"Error, bad input" << std::endl;
        break;
    }
}

// Get Contact instance
std::string    Contacts::get_contact(int i) {

    switch ( i ) {
    case 0:     
		return this->_firstname;
        break;
    case 1:     
		return this->_lastname;
        break;
    case 2:    
		return this->_nickname;
        break;
    case 3:    
		return this->_login;
        break;
    case 4:    
		return this->_address;
        break;
    case 5:    
		return this->_email;
        break;
    case 6:    
		return this->_phone;
        break;
    case 7:    
		return this->_birthday;
        break;
    case 8:    
		return this->_meal;
        break;
    case 9:    
		return this->_secret;
        break;
    default:
        std::cout<<"Error, bad input" << std::endl;
        return "";
        break;
    }
}

int            Contacts::getNbrContact(void) {
    return Contacts::_nbrcontact;
}

// Init _nbr Instance 
int             Contacts::_nbrcontact = 0;


