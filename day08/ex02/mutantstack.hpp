/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:16:18 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/12 18:09:30 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <list>
#include <iostream>

template <typename T>

class MutantStack : public std::stack<T>
{
  public:
    MutantStack<T>(void)
    {
        return;
    }

    MutantStack(MutantStack const &rhs)
    {
        (void)rhs;
        return;
    }

    ~MutantStack<T>(void)
    {
        return;
    }

    MutantStack &operator=(MutantStack const &rhs)
    {
        this->_stack_List = rhs._stack_List;
        return *this;
    }

    // Utiles Methods
    T top(void)
    {
        return (_stack_List.back());
    }
    // Size
    T size(void)
    {
        return (_stack_List.size());
    }

    typedef std::list<int>::iterator iterator;
    //
    iterator begin()
    {
        return (_stack_List.begin());
    }
    // 
    iterator end()
    {
        return (_stack_List.end());
    }
    // Push
    void push(T value)
    {
        _stack_List.push_back(value);
    }
    // pop
    void pop(void)
    {
        _stack_List.pop_back();
    }

  private:
    std::list<T> _stack_List;
};

#endif