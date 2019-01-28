/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:21:50 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 23:08:07 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_H
# define TIMER_H

# include <ctime>

class	Timer {

	public:

		Timer(void);
		Timer(clock_t t);
		Timer(Timer &obj);
		virtual ~Timer(void);
		Timer &operator=(Timer const &rhs);

		int		checkTime(clock_t t);
		int		getSec(clock_t t);
		
	private:
		clock_t	_timer;
};

#endif