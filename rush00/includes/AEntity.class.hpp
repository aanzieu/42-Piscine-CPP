/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:00:57 by nbouchin          #+#    #+#             */
/*   Updated: 2018/10/07 16:40:33 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_CLASS_HPP
#define AENTITY_CLASS_HPP

struct position
{
	int x;
	int y;
};

class AEntity
{
	private:
		short				_healthPoint;
		struct position		_position;
		char				_form;
		short				_speed;

	public:
		AEntity( void );
		AEntity( struct position position, short healthPoint, char form, short speed);
		AEntity( AEntity const & src );
		virtual ~AEntity();

		virtual AEntity			*clone() const = 0;
		virtual AEntity			*attack() const = 0;
		bool					moveRandom( char dir, int sec, int max, int end);
		bool					moveMissile( char dir, int sec, int max, int end);
		bool					checkColision(position self, position target, char type) const;

		short			getHP();
		void			setHP( int healthPoint );

		void			getHit( int damages );

		struct position	getPosition() const;
		void			setPosition(int x, int y);

		char			getForm() const;

		short			getSpeed( void ) const;
		void			setSpeed( short speed );


		AEntity &	operator=( AEntity const & rhs );
};

#endif /* ifndef ISHIP_CLASS_HPP */
