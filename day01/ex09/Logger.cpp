/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by _| |_|\__|        #+#    #+#             */
/*   Updated: 2018/10/04 10:05:36 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger() { return; }
Logger::~Logger(){ return; }

void	Logger::log(std::string const &dest, std::string const &message) {
	std::string msg;
	msg = LogTime(message);
	int i = 0;

    typedef void (Logger::*MyLog)(std::string const & target);
	
	MyLog log_[2] = {
       &Logger::logToConsole,
		&Logger::logToFile
    };

	std::string commands[2] = {
		"console",
		"file",
	};

	while (i < 4) {
		if (commands[i] == dest) {
			(this->*log_[i])(msg);
			break;
		}
		i++;
	}
	return;
}

void	Logger::logToConsole(std::string const &input) {
	std::cout << input << std::endl;
	return;
}

void	Logger::logToFile(std::string const &input) {
	std::string		file = "Logger";
	std::string		ofile;

	std::ofstream	ofs(file, std::ios_base::app | std::ios_base::out);
	if (ofs.is_open())
		ofs << input << std::endl;
	ofs.close();
	return;
}

std::string	Logger::LogTime(std::string input)
{
	std::ostringstream timestamp;
	time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    static char _retval[20];
    strftime(_retval, sizeof(_retval), "%Y-%m-%d %H:%M:%S", timeinfo);

	timestamp << "[" << _retval << "] ";
	timestamp << " " << input;
	std::string logtime(timestamp.str());
	return (logtime);
}

// http://www.cplusplus.com/reference/ctime/strftime/?kw=strftime