/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConversion.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:06:24 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/06 03:11:30 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef TYPECONVERSION_HPP
# define TYPECONVERSION_HPP

# include <iostream>
# include <exception>

# define TYPE_CHAR 0;
# define TYPE_INT 1;
# define TYPE_FLOAT 2;
# define TYPE_DOUBLE 3;

class TypeConversion
{
    private:
        std::string m_inputString;
        std::string m_type;
        int         m_typeCode;

        char    m_charValue;
        int     m_intValue;
        float   m_floatValue;
        double  m_doubleValue;

        bool    m_isChar(char *inputString);
        bool    m_isInt(char *inputString);
        bool    m_isFloat(char *inputString);
        bool    m_isDouble(char *inputString);

        void    m_convertChar(char *inputString);
        void    m_convertInt(char *inputString);
        void    m_convertFloat(char *inputString);
        void    m_convertDouble(char *inputString);

        TypeConversion  getInputString(void) const;
        TypeConversion  getType(void) const;
        TypeConversion  getTypeCode(void) const;

    public:
        TypeConversion(std::string inputString);
        ~TypeConversion(void);
        TypeConversion(TypeConversion const &instancedObject);
        TypeConversion &operator=(TypeConversion const &rightHandSide);

        class NotRecognizedException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("\e[0;31mInput is not of a recognized type\e[0m");
                }   
        };

        class NotDisplayableException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("\e[0;31mCharacter is non-displayable\e[0m");
                }   
        };
};

std::ostream &operator<<(std::ostream &output, TypeConversion const &instance);

#endif
