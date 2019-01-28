/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 17:08:46 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/04 11:08:49 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static void     sed_is_for_losers(std::string file, std::string search, std::string replace)
{
	std::ifstream	ifs(file);
    std::string		output, input, line, str;

    if(!ifs.is_open())
    {
        std::cout << "Error, file doesn't exist" << std::endl;
        return;
    }
    else
    { 
        std::locale loc;
        for (size_t j=0; j < file.length(); j++) {
            str.push_back(std::toupper(file[j], loc));
        }
        output.append(str + ".replace");
        std::ofstream	ofs(output);
        // int				i = 0;
        while (getline(ifs, input))
        {
            size_t find = input.find(search);
            while(find != std::string::npos) {
                if (find != std::string::npos)
                {
                    input.replace(find, search.length(), replace);
                    find = input.find(search, find + replace.length());
                }
            }
            if (!ifs.eof())
                ofs << input << std::endl;
            else
                ofs << input;
        }
        ifs.close();
        ofs.close();
    }
}

int     main(int ac, char **av) {

    if (ac != 4){
        std::cout << "Invalid Number of Element" << std::endl;
        std::cout << "[FILE] [STRING SEARCH] [STRING REPLACE]" << std::endl;
        return 0;
    } else {
        std::string search =  av[2];
        std::string replace =  av[3];
        if (search.empty() || replace.empty() ){
            std::cout << "Invalid word inputs. Enter valid words." << std::endl;
            return 0;
        } else if (search.compare(replace) == 0){
            std::cout << "Same Word for search and replace really ??" << std::endl;
            return 0;
        } else {
            sed_is_for_losers(av[1], av[2], av[3]);
        }
    }
    return 0;
}