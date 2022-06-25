/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:55:18 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/22 21:25:05 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include <iostream>

Animal::Animal(void)
{
	return ;
	std::cout << "Animal constructor called" << '\n';
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << '\n';
	return ;
}

Animal::Animal(Animal const &instancedObject)
{
	*this = instancedObject;
	std::cout << "Animal copy constructor called" << '\n';
	return ;
}

Animal &Animal::operator=(Animal const &rightHandSide)
{
	this->type = rightHandSide.getType();
	std::cout << "Animal = operator overload function called" << '\n';
	return (*this);
}

void    Animal::setType(std::string type)
{
    this->type = type;
    return ;
}

std::string Animal::getType(void) const
{
    return (this->type);
}
