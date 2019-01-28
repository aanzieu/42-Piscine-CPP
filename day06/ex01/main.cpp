/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:36:38 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/11 15:13:05 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

void * serialize(void)
{
    char *data = new char[20];

    char output[] = { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" };

    int i = -1;
    // Random al[ha]
    while (++i < 8)
        data[i] = output[rand() % 32];

   
    // Random imtegrer
     i = 7;
    while (++i < 12)
        data[i] = rand() % 10;
    // Cast implicite
    i = 11;
    // Random another alpha
    while (++i < 20)
        data[i] = output[rand() % 32];
    data[i] = '\0';


    // Display iformation first 8
    i = -1;
    while (++i < 8)
        std::cout << data[i];
    i = 7;
    // Display int
    while(++i < 12)
        std::cout << static_cast<int>(data[i]);

    i = 11;
    while (++i < 20)
        std::cout << data[i];

    return (reinterpret_cast<void *>(data));
}

Data *deserialize(void *raw)
{
    Data *data = new Data;

    data->n = 0;
    // Reinterpret Cast to Char * to recup dwongrade the void 
    char *input = reinterpret_cast<char *>(raw);


    int i = -1;
    // The first random
    while (++i < 8)
        data->s1 += input[i];

    i = 7;
    // the integrer
    while(++i < 12)
        data->n += input[i];
    
    i = 11;
    while (++i < 20)
        data->s2 += input[i];
    return (data);
}


int main()
{
    void *serial;
    Data *deserial;

    srand(time(0));
    
    serial = serialize();
    
    std::cout << std::endl << "Address of serialized : " << serial << std::endl
              << std::endl;

    deserial = deserialize(serial);
    
    std::cout << "deserializing the serialized" << std::endl
        << "Data->S1 : " << deserial->s1 << std::endl
        << "Data->INTEGRER : " << deserial->n << std::endl
        << "Data->S2 : " << deserial->s2 << std::endl;

    delete deserial;

    return (0);


    
}
