/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:24:04 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/21 01:08:25 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"
# include <iostream>

Cat::Cat(void)
{
	this->type = "Cat";
	return ;
}

Cat::~Cat(void)
{
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
	return (*this);
}

void        Cat::makeSound(void) const
{
    std::cout << "Meow!" << '\n';
    return ;
}
