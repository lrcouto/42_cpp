/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:20:02 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/22 20:48:27 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"
# include <iostream>

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "\033[0;33mDog constructor called\033[0m" << '\n';
	return ;
}

Dog::~Dog(void)
{
	std::cout << "\033[0;33mDog destructor called\033[0m" << '\n';
	return ;
}

Dog::Dog(Dog const &instancedObject)
{
	*this = instancedObject;
	std::cout << "\033[0;33mDog copy constructor called\033[0m" << '\n';
	return ;
}

Dog &Dog::operator=(Dog const &rightHandSide)
{
	this->type = rightHandSide.getType();
	std::cout << "\033[0;33mDog = operator overload called\033[0m" << '\n';
	return (*this);
}

void        Dog::makeSound(void) const
{
    std::cout << "\033[0;33mWoof!\033[0m" << '\n';
    return ;
}
