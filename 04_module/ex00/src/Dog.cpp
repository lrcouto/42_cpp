/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:20:02 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/21 01:08:07 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"
# include <iostream>

Dog::Dog(void)
{
	this->type = "Dog";
	return ;
}

Dog::~Dog(void)
{
	return ;
}

Dog::Dog(Dog const &instancedObject)
{
	*this = instancedObject;
	return ;
}

Dog &Dog::operator=(Dog const &rightHandSide)
{
	this->type = rightHandSide.getType();
	return (*this);
}

void        Dog::makeSound(void) const
{
    std::cout << "Woof!" << '\n';
    return ;
}
