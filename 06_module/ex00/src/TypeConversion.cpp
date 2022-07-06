/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConversion.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:13:20 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/06 03:10:39 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "TypeConversion.hpp"
# include <iostream>

TypeConversion::TypeConversion(std::string inputString)
{
    this->m_inputString = inputString;
    this->m_type = "";
    this->m_typeCode = -1;
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
    this->m_typeCode = rightHandSide.getTypeCode();
}

std::ostream &operator<<(std::ostream &output, TypeConversion const &instance)
{
    return (output << "Your input was: " << instance.getInputString() << std::endl
            << "Its type is: " << instance.getType() << std::endl);
}

TypeConversion  TypeConversion::getInputString(void) const
{
    return (this->m_inputString);
}

TypeConversion  TypeConversion::getType(void) const
{
    return (this->m_type);
}

TypeConversion  TypeConversion::getTypeCode(void) const
{
    return (this->m_typeCode);
}

void    TypeConversion::identifyType(std::string inputString)
{
    bool (TypeConversion::*typeFnPtr[4])(char *inputString) =  {TypeConversion::&m_isChar, TypeConversion::&m_isIntr, TypeConversion::&m_isFloat, TypeConversion::&m_isDouble}
    void (TypeConversion::*convertTypePtr[4])(char *inputString) =  {TypeConversion::&m_convertChar, TypeConversion::&m_convertIntr, TypeConversion::&m_convertFloat, TypeConversion::&m_convertDouble}

    for (int i = 0; i < 4; i++)
    {
        if ((this->*typeFnPtr[i])(inputString.c_str()))
            return ((this->*convertTypePtr[i])(inputString.c_str()));
    }
    throw TypeConversion::NotRecognizedException();
    return ;
}

bool    TypeConversion::m_isChar(char *inputString)
{
    if (inputString[1] == '\0' && (inputString[0] >= 32 && inputString[0] <= 47) && (inputString[0] >= 58 && inputString[0] <= 126))
    {
        this->m_type = "char";
        this->m_typeCode = TYPE_CHAR;
        return (true);
    }
    return (false);
}

bool    TypeConversion::m_isInt(char *inputString)
{

}

bool    TypeConversion::m_isFloat(char *inputString)
{

}

bool    TypeConversion::m_isDouble(char *inputString)
{

}

void    TypeConversion::m_convertChar(char *inputString)
{

}

void    TypeConversion::m_convertInt(char *inputString)
{

}

void    TypeConversion::m_convertFloat(char *inputString)
{

}

void    TypeConversion::m_convertDouble(char *inputString)
{
vb
}
