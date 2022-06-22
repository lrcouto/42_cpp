/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:24:04 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/22 20:46:53 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"
# include <iostream>

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "\033[0;36mCat constructor called\033[0m" << '\n';
	return ;
}

Cat::~Cat(void)
{
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
	std::cout << "\033[0;36mCat = operator overload called\033[0m" << '\n';
	return (*this);
}

void        Cat::makeSound(void) const
{
    std::cout << "\033[0;36mMeow!\033[0m" << '\n';
    return ;
}
