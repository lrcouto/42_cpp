/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:20:02 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/22 19:26:39 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"
# include <iostream>

Dog::Dog(void)
{
	this->type = "Dog";
	brain = new Brain();
	std::cout << "\033[0;32mDog constructor called\033[0m" << '\n';
	return ;
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "\033[0;32mDog destructor called\033[0m" << '\n';
	return ;
}

Dog::Dog(Dog const &instancedObject)
{
	*this = instancedObject;
	std::cout << "\033[0;32mDog copy constructor called\033[0m" << '\n';
	return ;
}

Dog &Dog::operator=(Dog const &rightHandSide)
{
	this->type = rightHandSide.getType();
	this->brain = new Brain();
	std::cout << "\033[0;32mDog = operator overload function called\033[0m" << '\n';
	return (*this);
}

void        Dog::makeSound(void) const
{
    std::cout << "Woof!" << '\n';
    return ;
}

std::string Dog::getIdea(int index) const
{
    if (index >= 100 || index < 0)
        return ("\033[1;32mDogs don't think that deep\033[0m");
    else
        return (this->brain->ideas[index]);
}

void		Dog::getBrainAddress(void) const
{
	std::cout << &this->brain << '\n';
}
