/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 21:18:43 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 23:11:07 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_H
#define TACTICALMARINE_H

#include "TacticalMarine.hpp"
#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
  public:
	TacticalMarine(void);
	TacticalMarine(TacticalMarine const &obj);
	virtual ~TacticalMarine(void);
	TacticalMarine &operator=(TacticalMarine const &r);

	ISpaceMarine *clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};

#endif