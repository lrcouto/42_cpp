/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 02:06:18 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/17 21:37:04 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include <iostream>
# include <cmath>

Fixed::Fixed(void)
{
    this->m_rawBits = 0;
    std::cout << "Constructor called for " << this << std::endl;
    return ;
}

Fixed::Fixed(int const value)
{
    this->m_rawBits = value * 1 << this->m_fractionalBits;
    std::cout << "Integer constructor called for " << this << std::endl;
    return ;
}

Fixed::Fixed(float const value)
{
    this->m_rawBits = roundf(value * (1 << this->m_fractionalBits));
    std::cout << "Float constructor called for " << this << std::endl;
    return ;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called for " << this << std::endl;
    return ;
}

Fixed::Fixed(Fixed const &instancedObject)
{
	*this = instancedObject;
    std::cout << "Copy constructor called for " << this << std::endl;
	return ;
}

Fixed &Fixed::operator=(Fixed const &rightHandSide)
{
	this->m_rawBits = rightHandSide.getRawBits();
    std::cout << "Copy assignment operator overload called for " << this << std::endl;
	return (*this);
}

std::ostream &operator<<(std::ostream &outputFile, Fixed const &value)
{
	outputFile << value.toFloat();
	return outputFile;
}

void	Fixed::setRawBits(int const rawBits)
{
    std::cout << "setRawBits called for " << this << std::endl;
    this->m_rawBits = rawBits;
}

int		Fixed::getRawBits(void) const
{
    std::cout << "getRawBits called for " << this << std::endl;
    return (this->m_rawBits);
}

float	Fixed::toFloat(void) const
{
    return ((float)this->m_rawBits / (float)(1 << this->m_fractionalBits));
}

int		Fixed::toInt(void) const
{
    return (this->m_rawBits >> this->m_fractionalBits);
}

