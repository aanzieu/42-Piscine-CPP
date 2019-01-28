/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 10:55:41 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/12 15:25:29 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{

  public:
	Span(void);
	Span(unsigned int n);
	Span(Span const &src);
	virtual ~Span(void);
	Span &operator=(Span const &r);

	class StorageLimitException : public std::exception
	{
	  public:
		StorageLimitException(void);
		// StorageLimitException(void);
		virtual const char *what() const throw();
		StorageLimitException(StorageLimitException const &src);
		virtual ~StorageLimitException(void) throw();
		StorageLimitException &operator=(StorageLimitException const &r);
	};

	class NotEnoughValuesException : public std::exception
	{
	  public:
		NotEnoughValuesException(void);
		virtual const char *what() const throw();
		NotEnoughValuesException(NotEnoughValuesException const &src);
		virtual ~NotEnoughValuesException(void) throw();
		NotEnoughValuesException &operator=(NotEnoughValuesException const &r);
	};
	// ADD NUMBER
	void addNumber(int num);
	size_t shortestSpan(void);
	size_t longestSpan(void);

  private:
	std::vector<int> _stock;
	// size_t _capacity;
};

#endif