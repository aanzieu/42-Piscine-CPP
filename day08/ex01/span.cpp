/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:03:35 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/12 17:13:51 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int n) 
{
    _stock.reserve(n);
    return;
}
Span::Span(Span const &obj)
{
    *this = obj;
    return;
}
Span::~Span(void)
{
    return;
}

Span &Span::operator=(Span const &r)
{
    this->_stock = r._stock;
    return (*this);
}

void Span::addNumber(int num)
{
    // If size max 
    // std::cout << "size: " << _stock.size() << std::endl;
    // std::cout << "capacity: " << _stock.capacity() << std::endl;
    // std::cout << "max_size: " << _stock.max_size() << std::endl;
    if (_stock.size() < _stock.capacity())
        _stock.push_back(num);
    else
        throw Span::StorageLimitException();
}

size_t Span::shortestSpan(void)
{
    if (_stock.capacity() <= 1)
        throw std::exception();

    std::vector<int> cpy = _stock;
    // cpy vector order
    std::sort(cpy.begin(), cpy.end());


    // std::vector<int>::iterator cp = cpy.begin();
    // std::vector<int>::iterator it = cpy.begin();
    // std::vector<int>::iterator ite = cpy.end();
    
    std::vector<int>::iterator it;// = cpy.begin();
    std::vector<int>::iterator ite;// = cpy.end();
    
    uint minDelta = UINT_MAX;
    
    // std::cout << "size: " << _stock.size() << std::endl;
    // std::cout << "capacity: " << _stock.capacity() << std::endl;
    
    for (it = ++cpy.begin(); it != cpy.end(); ++it) {
       unsigned int delta = abs(*it - *(it-1));
    if (minDelta >= delta) {
       minDelta = delta;
     }
   }

    // while (i < (_stock.size()))
    // {
    //     if (abs(*it - *cp) < abs(*it - *ite))
    //         ite = cp;
    //     else if (abs(*ite - *cp) < abs(*it - *ite))
    //         it = cp;
    //     i++;
    //     cp++;
    // }
    return (minDelta);
    // return (abs(*it - *ite));
}

size_t Span::longestSpan(void)
{
    if (_stock.capacity() <= 1)
        throw NotEnoughValuesException();
    std::vector<int> max = _stock;
    return (*std::max_element(max.begin(), max.end()) - *std::min_element(max.begin(), max.end()));
}

/*
** StorageLimitException Nested Class
*/

Span::StorageLimitException::StorageLimitException(void)
{
    return;
}


Span::StorageLimitException::StorageLimitException(StorageLimitException const &obj)
{
    *this = obj;
    return;
}

Span::StorageLimitException::~StorageLimitException(void) throw()
{
    return;
}

Span::StorageLimitException &Span::StorageLimitException::operator=(StorageLimitException const &r)
{
    (void)r;
    return (*this);
}
const char *Span::StorageLimitException::what() const throw()
{
    return ("Error: Storage capacity is maxed.");
}

///////////// Not Enoug
Span::NotEnoughValuesException::NotEnoughValuesException(NotEnoughValuesException const &obj)
{
    *this = obj;
    return;
}

Span::NotEnoughValuesException::~NotEnoughValuesException(void) throw()
{
    return;
}

Span::NotEnoughValuesException &Span::NotEnoughValuesException::operator=(NotEnoughValuesException const &r)
{
    (void)r;
    return (*this);
}
Span::NotEnoughValuesException::NotEnoughValuesException(void)
{
    return;
}

const char *Span::NotEnoughValuesException::what() const throw(){
    return ("Error : Not Enough Value !");
}
