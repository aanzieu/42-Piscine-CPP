/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 17:29:48 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/09 17:42:13 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRALBUREAUCRACY_H
#define CENTRALBUREAUCRACY_H

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

class CentralBureaucracy
{

  public:
    CentralBureaucracy(void);
    CentralBureaucracy(CentralBureaucracy  &src);
    virtual ~CentralBureaucracy(void);
    // Operator
    CentralBureaucracy &operator=(CentralBureaucracy   &rhs);
    // Attributes

    // Member functions
    void feedSigner(Bureaucrat &src);
    void feedExecuter(Bureaucrat &src);

    void queueUp(std::string src);

    void doBureaucracy(void);

  private:
   // Attributes

    // Member functions
    OfficeBlock _OfficeBlock[20];
    std::string _target[100];
};

#endif