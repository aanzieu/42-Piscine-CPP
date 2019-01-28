/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 21:42:50 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 23:10:53 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_H
#define SQUAD_H

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad : public ISquad
{
  typedef struct s_marine
  {
    ISpaceMarine *marine;
    struct s_marine *next;
  } t_marine;

public:
  Squad(void);
  Squad(Squad const &src);
  virtual ~Squad(void);
  Squad &operator=(Squad const &rhs);

  int getCount() const;
  ISpaceMarine *getUnit(int) const;
  int push(ISpaceMarine *);

  void killSquad();

private:
  int _unit;
  struct s_marine *_s_marine;
};

#endif