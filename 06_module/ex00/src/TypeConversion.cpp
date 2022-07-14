/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConversion.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:13:20 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/14 03:19:04 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "TypeConversion.hpp"
# include <iostream>
# include <iomanip>
# include <stdlib.h>
# include <limits.h>
# include <float.h>

TypeConversion::TypeConversion(std::string inputString)
{
    std::cout << std::fixed << std::setprecision(1);
    this->m_inputString = inputString;
    if (inputString == "nan" || inputString == "+inf" || inputString == "-inf")
    {
            this->m_type = "double";
            this->m_typeCode = 3;
    }
    else if (inputString == "nanf" || inputString == "+inff" || inputString == "-inff")
    {
        this->m_type = "float";
        this->m_typeCode = 2;
    }
    else
    {
        this->m_type = "";
        this->m_typeCode = -1;
        this->identifyType(inputString);
    }
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
    instance.displayConvertedValue();
    return (output << "Your input was: " << instance.getInputString() << std::endl
            << "Conversion type is: " << instance.getType() << std::endl);
}

void    TypeConversion::displayConvertedValue(void) const
{
    std::cout << "\nYour converted values are: \n\n";
    this->displayChar();
    this->displayInt();
    this->displayFloat();
    this->displayDouble();
    std::cout << '\n';
}

void         TypeConversion::displayChar(void) const
{
    if (this->m_charValue > '~' || this->m_charValue < '!')
        std::cout << "char: Non-displayable\n";
    else if (this->m_inputString == "nan" || this->m_inputString == "nanf" || this->m_inputString == "-inff" ||
            this->m_inputString == "+inff" || this->m_inputString == "+inf" || this->m_inputString == "-inf")
        std::cout << "char: Impossible\n";
    else
        std::cout << "char: " << this->m_charValue << '\n';
    return ;
}

void         TypeConversion::displayInt(void) const
{
    if (atol(this->m_inputString.c_str()) > INT_MAX)
        std::cout << "integer: Overflow\n";
    else if (atol(this->m_inputString.c_str()) < INT_MIN)
        std::cout << "integer: Underflow\n";
    else if (this->m_inputString == "nan" || this->m_inputString == "nanf" || this->m_inputString == "-inff" ||
            this->m_inputString == "+inff" || this->m_inputString == "+inf" || this->m_inputString == "-inf")
        std::cout << "integer: Impossible\n";
    else
        std::cout << "integer: " << this->m_intValue << '\n';
}

void         TypeConversion::displayFloat(void) const
{
    if (this->m_inputString == "nan" || this->m_inputString == "nanf")
        std::cout << "float: nanf\n";
    else if (this->m_inputString == "-inff" || this->m_inputString == "-inf")
        std::cout << "float: -inff\n";
    else if (this->m_inputString == "+inff" || this->m_inputString == "+inf")
        std::cout << "float: +inff\n";
    else
        std::cout << "float: " << this->m_floatValue << '\n';
}

void         TypeConversion::displayDouble(void) const
{
    if (this->m_inputString == "nan" || this->m_inputString == "nanf")
        std::cout << "float: nan\n";
    else if (this->m_inputString == "-inff" || this->m_inputString == "-inf")
        std::cout << "float: -inf\n";
    else if (this->m_inputString == "+inff" || this->m_inputString == "+inf")
        std::cout << "float: +inf\n";
    else
        std::cout << "double: " << this->m_doubleValue << '\n';
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
    if ((inputString[1] == '\0' && (inputString[0] >= '!' && inputString[0] < '0')) || 
        (inputString[1] == '\0' && (inputString[0] > '9' && inputString[0] <= '~')))
    {
        this->m_type = "char";
        this->m_typeCode = TYPE_CHAR;
        return (true);
    }
    return (false);
}

bool    TypeConversion::m_isInt(char const *inputString)
{
    for (int i = (inputString[0] == '-') ? 1 : 0; inputString[i] != '\0'; i++)
    {
        if (inputString[i] < '0' || inputString[i] > '9')
            return (false);
    }
    this->m_type = "integer";
    this->m_typeCode = TYPE_INT;
    return (true);
}

bool    TypeConversion::m_isFloat(char const *inputString)
{
    bool point = false;

    for (int i = (inputString[0] == '-') ? 1 : 0; inputString[i] != '\0'; i++)
    {
        if ((inputString[i] < '0' || inputString[i] > '9') && inputString[i] != '.' && inputString[i] != 'f')
            return (false);
        if (inputString[i] == '.')
        {
            if (point == true)
                return (false);
            point = true;
        }
        if (inputString[i] == 'f')
        {
            if (inputString[i + 1] == '\0' && point == true)
            {
                this->m_type = "float";
                this->m_typeCode = TYPE_FLOAT;
                return (true);
            }
        }
    }
    return (false);
}

bool    TypeConversion::m_isDouble(char const *inputString)
{
    bool point = false;

    for (int i = (inputString[0] == '-') ? 1 : 0; inputString[i] != '\0'; i++)
    {
        if ((inputString[i] < '0' || inputString[i] > '9') && inputString[i] != '.')
            return (false);
        if (inputString[i] == '.')
        {
            if (point == true)
                return (false);
            point = true;
        }
    }
    this->m_type = "double";
    this->m_typeCode = TYPE_DOUBLE;
    return (true);
}

void    TypeConversion::m_convertChar(char const *inputString)
{
    this->m_charValue = inputString[0];
    this->m_intValue = static_cast<int>(this->m_charValue);
    this->m_floatValue = static_cast<float>(this->m_charValue);
    this->m_doubleValue = static_cast<double>(this->m_charValue);
    return ;
}

void    TypeConversion::m_convertInt(char const *inputString)
{
    this->m_intValue = atoi(inputString);
    this->m_charValue = static_cast<char>(this->m_intValue);
    this->m_floatValue = static_cast<float>(this->m_intValue);
    this->m_doubleValue = static_cast<double>(this->m_intValue);
    return ;
}

void    TypeConversion::m_convertFloat(char const *inputString)
{
    this->m_floatValue = atof(inputString);
    this->m_charValue = static_cast<char>(this->m_floatValue);
    this->m_intValue = static_cast<int>(this->m_floatValue);
    this->m_doubleValue = static_cast<double>(this->m_floatValue);
    return ;
}

void    TypeConversion::m_convertDouble(char const *inputString)
{
    this->m_doubleValue = strtod(inputString, NULL);
    this->m_charValue = static_cast<char>(this->m_doubleValue);
    this->m_intValue = static_cast<int>(this->m_doubleValue);
    this->m_floatValue = static_cast<float>(this->m_doubleValue);
    return ;
}
