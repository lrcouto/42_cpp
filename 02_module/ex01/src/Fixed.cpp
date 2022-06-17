/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 02:06:18 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/16 02:36:46 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include <iostream>

Fixed::Fixed(void)
{
    this->m_rawBits = 0;
    std::cout << "Constructor called for " << this << std::endl;
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