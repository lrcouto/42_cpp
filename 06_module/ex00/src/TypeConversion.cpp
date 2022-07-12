/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConversion.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:13:20 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/12 01:25:31 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "TypeConversion.hpp"
# include <iostream>
# include <stdlib.h>

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
    return (*this);
}

std::ostream &operator<<(std::ostream &output, TypeConversion const &instance)
{
    switch (instance.getTypeCode()) 
    {
        case 0: this->m_charValue; break;
        case 1: this->m_intValue; break;
        case 2: this->m_floatValue; break;
        case 3: this->m_doubleValue; break;
    }

    return (output << "Your input was: " << instance.getInputString() << std::endl
            << "Its type is: " << instance.getType() << std::endl
            << "Its conversion result is: " <<  << std::endl);
}

std::string  TypeConversion::getInputString(void) const
{
    return (this->m_inputString);
}

std::string  TypeConversion::getType(void) const
{
    return (this->m_type);
}

int  TypeConversion::getTypeCode(void) const
{
    return (this->m_typeCode);
}

void    TypeConversion::identifyType(std::string inputString)
{
    char const *cString = inputString.c_str();
    bool (TypeConversion::*typeFnPtr[4])(char const *inputString) =  {&TypeConversion::m_isChar, &TypeConversion::m_isInt, &TypeConversion::m_isFloat, &TypeConversion::m_isDouble};
    void (TypeConversion::*convertTypePtr[4])(char const *inputString) =  {&TypeConversion::m_convertChar, &TypeConversion::m_convertInt, &TypeConversion::m_convertFloat, &TypeConversion::m_convertDouble};

    for (int i = 0; i < 4; i++)
    {
        if ((this->*typeFnPtr[i])(cString))
            return ((this->*convertTypePtr[i])(cString));
    }
    throw TypeConversion::NotRecognizedException();
    return ;
}

bool    TypeConversion::m_isChar(char const *inputString)
{
    if (inputString[1] == '\0' && (inputString[0] >= 32 && inputString[0] <= 47) && (inputString[0] >= 58 && inputString[0] <= 126))
    {
        this->m_type = "char";
        this->m_typeCode = TYPE_CHAR;
        return (true);
    }
    return (false);
}

bool    TypeConversion::m_isInt(char const *inputString)
{
    return (false);
}

bool    TypeConversion::m_isFloat(char const *inputString)
{
    return (false);
}

bool    TypeConversion::m_isDouble(char const *inputString)
{
    return (false);
}

void    TypeConversion::m_convertChar(char const *inputString)
{
    this->m_charValue = inputString[0];
    this->m_intValue = static_cast<int>(NULL);
    this->m_floatValue = static_cast<float>(NULL);
    this->m_doubleValue = static_cast<double>(NULL);
    return ;
}

void    TypeConversion::m_convertInt(char const *inputString)
{
    this->m_charValue = '\0';
    this->m_intValue = atoi(inputString);
    this->m_floatValue = static_cast<float>(NULL);
    this->m_doubleValue = static_cast<double>(NULL);
    return ;
}

void    TypeConversion::m_convertFloat(char const *inputString)
{
    this->m_charValue = '\0';
    this->m_intValue = static_cast<int>(NULL);
    this->m_floatValue = atof(inputString);
    this->m_doubleValue = static_cast<double>(NULL);
    return ;
}

void    TypeConversion::m_convertDouble(char const *inputString)
{
    this->m_charValue = '\0';
    this->m_intValue = static_cast<int>(NULL);
    this->m_floatValue = static_cast<float>(NULL);
    this->m_doubleValue = strtod(inputString, 0);
    return ;
}
