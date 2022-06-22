/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:24:04 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/22 02:36:26 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"
# include <iostream>

Cat::Cat(void)
{
	this->type = "Cat";
	brain = new Brain();
	return ;
}

Cat::~Cat(void)
{
	delete this->brain;
	return ;
}

Cat::Cat(Cat const &instancedObject)
{
	*this = instancedObject;
	return ;
}

Cat &Cat::operator=(Cat const &rightHandSide)
{
	this->type = rightHandSide.getType();
	this->brain = new Brain();
	return (*this);
}

void        Cat::makeSound(void) const
{
    std::cout << "Meow!" << '\n';
    return ;
}

Brain*		Cat::getBrain(void) const
{
	return (this->brain);
}

std::string Cat::getIdea(int index) const
{
    if (index >= 100 || index < 0)
        return ("Cats don't think that deep");
    else
        return (this->brain->ideas[index]);
}

void		Cat::getBrainAddress(void) const
{
	std::cout << &this->brain << '\n';
}
