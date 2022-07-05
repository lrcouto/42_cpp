/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConversion.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:13:20 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/05 03:08:35 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "TypeConversion.hpp"
# include <iostream>

TypeConversion::TypeConversion(std::string inputString)
{
    this->m_inputString = inputString;
    return ;
}

TypeConversion::~TypeConversion(void)
{
    return ;
}

TypeConversion::TypeConversion(TypeConversion const &instancedObject)
{
    *this = instancedObject;
}

TypeConversion &TypeConversion::operator=(TypeConversion const &rightHandSide)
{
    this->m_inputString = rightHandSide.getInputString();
    this->m_type = rightHandSide.getType();
}

std::ostream &operator<<(std::ostream &output, TypeConversion const &instance)
{
    return (output << "Your input was: " << this->getInputString << std::endl
            << "Its type is: " << this->getType() << std::endl;)
}

TypeConversion  getInputString(void)
{
    return (this->m_inputString);
}

TypeConversion  getType(void)
{
    return (this->m_type);
}

void    identifyType(std::string inputString)
{
    bool (TypeConversion::*typeFnPtr[4])(std::string inputString) =  {TypeConversion::&m_isChar, TypeConversion::&m_isIntr, TypeConversion::&m_isFloat, TypeConversion::&m_isDouble}
    void (TypeConversion::*convertTypePtr[4])(std::string inputString) =  {TypeConversion::&m_convertChar, TypeConversion::&m_convertIntr, TypeConversion::&m_convertFloat, TypeConversion::&m_convertDouble}

    // for loop will use the first vector to verify and dispatch the second fn to convert.
}
