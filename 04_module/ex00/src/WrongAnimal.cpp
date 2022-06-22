/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:55:18 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/22 20:49:39 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongAnimal.hpp"
# include <iostream>

WrongAnimal::WrongAnimal(void)
{
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &instancedObject)
{
	*this = instancedObject;
	return ;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rightHandSide)
{
	this->type = rightHandSide.getType();
	return (*this);
}

void    WrongAnimal::setType(std::string const type)
{
    this->type = type;
    return ;
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}

void        WrongAnimal::makeSound(void) const
{
    std::cout << "\033[0;31mK̸I̴L̵L̵ ̴M̸E̵ ̷P̸L̸E̷A̷S̵E̶ ̴I̵ ̵A̶M̶ ̴W̴R̷O̴N̷G̴\033[0m" << '\n';
    return ;
}
