/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:24:04 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/22 13:51:47 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"
# include <iostream>

Cat::Cat(void)
{
	this->type = "Cat";
	brain = new Brain();
	std::cout << "\033[0;36mCat constructor called\033[0m" << '\n';
	return ;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "\033[0;36mCat destructor called\033[0m" << '\n';
	return ;
}

Cat::Cat(Cat const &instancedObject)
{
	*this = instancedObject;
	std::cout << "\033[0;36mCat copy constructor called\033[0m" << '\n';
	return ;
}

Cat &Cat::operator=(Cat const &rightHandSide)
{
	this->type = rightHandSide.getType();
	this->brain = new Brain();
	std::cout << "\033[0;36mCat = operator overload function called\033[0m" << '\n';
	return (*this);
}

void        Cat::makeSound(void) const
{
    std::cout << "\033[0;36mMeow!\033[0m" << '\n';
    return ;
}

Brain*		Cat::getBrain(void) const
{
	return (this->brain);
}

std::string Cat::getIdea(int index) const
{
    if (index >= 100 || index < 0)
        return ("\033[0;36mCats don't think that deep\033[0m");
    else
        return (this->brain->ideas[index]);
}

void		Cat::getBrainAddress(void) const
{
	std::cout << &this->brain << '\n';
}
