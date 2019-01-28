/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 12:27:24 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/11 16:56:29 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename T>
class Array
{
  public:
	// Void Array NULL and _n 0 element;
	Array<T>(void) : _array(NULL), _n(0) { return; }

	// Array create a Array of N Array
	Array<T>(unsigned int n)
	{
		this->_n = n;
		this->_array = new T[n]();
		return;
	}
	//
	Array<T>(Array const &rhs)
	{
		*this = rhs;
		return;
	}
	// Operator Constructor
	Array<T> &operator=(Array const &r)
	{
		unsigned int i = 0;

		this->_n = r._n;
		if (this->_array != NULL)
			delete this->_array;
		this->_array = new T[this->_n];

		while (i < this->_n)
		{
			this->_array[i] = r._array[i];
			i++;
		}
		return (*this);
	}

	// Destructor peraprs delete Array ?
	~Array<T>(void)
	{
		if (this->_array != NULL)
		{
			delete this->_array;
		}
		return;
	}

	T &operator[](unsigned int n)
	{
		if (n >= this->_n)
			throw Array::ErrorLimitsException();
		return (this->_array[n]);
	}

	unsigned int getSize() const { return (this->_n); }

  private:
	T *_array;
	unsigned int _n;
	// EXEPTION ERROR
	class ErrorLimitsException : public std::exception
	{
	  public:
		ErrorLimitsException(void) throw() { return; };
		ErrorLimitsException(ErrorLimitsException const &src) throw()
		{
			*this = src;
			return;
		};
		virtual ~ErrorLimitsException(void) throw() { return; };
		ErrorLimitsException &operator=(ErrorLimitsException const &rhs) throw()
		{
			(void)rhs;
			if (this != &rhs)
			{
			}
			return (*this);
		};
		// Return throw for Grade Tool Hight Exeption
		virtual const char *what() const throw()
		{
			return ("Error: DON'T LOOK SO FAR");
		};
	};
};

#endif