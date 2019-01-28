/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 23:06:43 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/04 07:54:23 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_H
# define LOGGER_H

#include <iostream>
#include <sstream>
#include <fstream>

class Logger {

	public:
		Logger(void);
		~Logger(void);

		void            log(std::string const &dest, std::string const &message);

	private:

		void            logToConsole(std::string const &input);
		void			logToFile(std::string const &input);
		std::string		LogTime(std::string message);
}; 

#endif