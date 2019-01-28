/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:18:00 by nbouchin          #+#    #+#             */
/*   Updated: 2018/10/07 09:17:13 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_CLASS_HPP
#define MISSILE_CLASS_HPP

#include "AEntity.class.hpp"

class Missile : public AEntity
{
  private:
  public:
	Missile(void);
	Missile(Missile const &src);
	Missile(struct position position, short healthPoint, char form, short speed);
	~Missile(void);

	virtual Missile			*clone() const;
	virtual AEntity			*attack() const;
	Missile &operator=(Missile const &rhs);
};

#endif /* USERSHIP_CLASS_H */
