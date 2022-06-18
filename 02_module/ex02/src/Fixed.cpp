/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 02:06:18 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/18 19:45:17 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include <iostream>
# include <cmath>

Fixed::Fixed(void)
{
    this->m_rawBits = 0;
    return ;
}

Fixed::Fixed(int const value)
{
    this->m_rawBits = value * 1 << this->m_fractionalBits;
    return ;
}

Fixed::Fixed(float const value)
{
    this->m_rawBits = roundf(value * (1 << this->m_fractionalBits));
    return ;
}

Fixed::~Fixed(void)
{
    return ;
}

Fixed::Fixed(Fixed const &instancedObject)
{
	*this = instancedObject;
	return ;
}

Fixed &Fixed::operator=(Fixed const &rightHandSide)
{
	this->m_rawBits = rightHandSide.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &outputFile, Fixed const &value)
{
	outputFile << value.toFloat();
	return outputFile;
}

bool Fixed::operator>(Fixed const &rightHandSide) const
{
	return (this->getRawBits() > rightHandSide.getRawBits());
}

bool Fixed::operator<(Fixed const &rightHandSide) const
{
	return (this->getRawBits() < rightHandSide.getRawBits());
}

bool Fixed::operator>=(Fixed const &rightHandSide) const
{
	return (this->getRawBits() >= rightHandSide.getRawBits());
}

bool Fixed::operator<=(Fixed const &rightHandSide) const
{
	return (this->getRawBits() <= rightHandSide.getRawBits());
}

bool Fixed::operator==(Fixed const &rightHandSide) const
{
	return (this->getRawBits() == rightHandSide.getRawBits());
}

bool Fixed::operator!=(Fixed const &rightHandSide) const
{
	return (this->getRawBits() != rightHandSide.getRawBits());
}

Fixed Fixed::operator+(Fixed const &rightHandSide)
{
	this->setRawBits(this->getRawBits() + rightHandSide.getRawBits());
	return (*this);
}

Fixed Fixed::operator-(Fixed const &rightHandSide)
{
	this->setRawBits(this->getRawBits() - rightHandSide.getRawBits());
	return (*this);
}

Fixed Fixed::operator*(Fixed const &rightHandSide)
{
	this->setRawBits(((long)this->getRawBits() * (long)rightHandSide.getRawBits()) / (1 << this->m_fractionalBits));
	return (*this);
}

Fixed Fixed::operator/(Fixed const &rightHandSide)
{
	this->setRawBits(((long)this->getRawBits() * (1 << this->m_fractionalBits)) / (long)rightHandSide.getRawBits());
	return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->m_rawBits++;
	return (temp);
}

Fixed Fixed::operator++(void)
{
	this->m_rawBits++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->m_rawBits--;
    return (temp);
}

Fixed Fixed::operator--(void)
{
	this->m_rawBits--;
	return (*this);
}

Fixed const &Fixed::min(Fixed const &first, Fixed const &second)
{
	if (first > second)
		return (second);
	return (first);
}

Fixed const &Fixed::max(Fixed const &first, Fixed const &second)
{
	if (first > second)
		return (first);
	return (second);
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	if (first > second)
		return (second);
	return (first);
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	if (first > second)
		return (first);
	return (second);
}

void	Fixed::setRawBits(int const rawBits)
{
    this->m_rawBits = rawBits;
}

int		Fixed::getRawBits(void) const
{
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

