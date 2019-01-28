/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.Contacts.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:36:45 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/02 15:50:13 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CONTACTS_H
# define CLASS_CONTACTS_H
#include <iostream>

class Contacts {

	public:
        Contacts(void); 
        ~Contacts(void);

        void    		set_contact(std::string, int i);
		std::string		get_contact(int i); // Const empeche de 

		// Compare les instances
		int				compare(Contacts *other) const;
		void			display_info();

		// Récupère le nombre d'instance de class existante;
		static	int		getNbrContact(void);

		void 			add_contact(void);

	private:
		// nbr instance static 
		static int _nbrcontact;
        std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _login;
		std::string _address;
		std::string _email;
		std::string _phone;
		std::string _birthday;
		std::string _meal;
		std::string _secret;
};

#endif