/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:17:11 by nbouchin          #+#    #+#             */
/*   Updated: 2018/10/07 09:17:19 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_CLASS_HPP
#define USER_CLASS_HPP

#include "AEntity.class.hpp"
#include "Missile.class.hpp"

class User : public AEntity
{
  private:
  public:
	User(void);
	User(User const &src);
	User(struct position position, short healthPoint, char form, short speed);
	~User(void);

	virtual User		*clone() const;
	virtual AEntity		*attack() const;
	User &operator=(User const &rhs);
};

#endif /* USERSHIP_CLASS_H */
