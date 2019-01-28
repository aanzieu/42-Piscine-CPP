/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IEntityPool.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:57:19 by nbouchin          #+#    #+#             */
/*   Updated: 2018/10/07 16:00:19 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IENTITYPOOL_CLASS_HPP
#define IENTITYPOOL_CLASS_HPP

#include "AEntity.class.hpp"

class IEntityPool
{
	public:
		virtual ~IEntityPool() {}
		virtual int getCount() const = 0;
		virtual AEntity* getUnit(int) const = 0;
		virtual int push(AEntity*) = 0;
};

#endif /* ifndef IENTITYPOOL_CLASS_HPP */
