/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:55:18 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/22 02:19:14 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include <iostream>

Animal::Animal(void)
{
	return ;
}

Animal::~Animal(void)
{
	return ;
}

Animal::Animal(Animal const &instancedObject)
{
	*this = instancedObject;
	return ;
}

Animal &Animal::operator=(Animal const &rightHandSide)
{
	this->type = rightHandSide.getType();
	return (*this);
}

void    Animal::setType(std::string const type)
{
    this->type = type;
    return ;
}

std::string Animal::getType(void) const
{
    return (this->type);
}

void        Animal::makeSound(void) const
{
    std::cout << "Ą̷̱̲̝̝̪̞̬̼̰̰͍͔͆̀̃͗͋̉͋͋͋̒̕̕̕̕a̶͓̯̜͓͈͒̄͑͆̋̓̄̾͋͛̑̅̈͂̚͝͝A̶̡̟̰̖̟̙̜̖̳̩̙̒̍̀͊̀͛̔́̀̌͑̀̂̈́̚͝À̷̛̗̫̰̱̟̻̖͉̈͊͗̑̍͐̈̾̏͌̽̚̚͝ͅǍ̸̹̥̤͎͚̟̬̙̎͑̓̌̊̊̆̑̈̀͘͝ą̴͉͓̜͕̗͕͋͂̀̃̎̋̆͂̎̾͆͒̕Ą̷͓̩̝̣̩͖̽͒͒̓̊̒̿͛̀͂̚͝a̵̧̗͍̣̠̾͊̑͐͝Ą̷̱̲̝̝̪̞̬̼̰̰͍͔͆̀̃͗͋̉͋͋͋̒̕̕̕̕a̶͓̯̜͓͈͒̄͑͆̋̓̄̾͋͛̑̅̈͂̚͝͝A̶̡̟̰̖̟̙̜̖̳̩̙̒̍̀͊̀͛̔́̀̌͑̀̂̈́̚͝À̷̛̗̫̰̱̟̻̖͉̈͊͗̑̍͐̈̾̏͌̽̚̚͝ͅǍ̸̹̥̤͎͚̟̬̙̎͑̓̌̊̊̆̑̈̀͘͝ą̴͉͓̜͕̗͕͋͂̀̃̎̋̆͂̎̾͆͒̕Ą̷͓̩̝̣̩͖̽͒͒̓̊̒̿͛̀͂̚͝a̵̧̗͍̣̠̾͊̑͐͝" << '\n';
    return ;
}

std::string	Animal::getIdea(int index) const
{
    if (index >= 100 || index < 0)
        return ("Bro I don't even have a brain");
    else
        return ("No thoughts. Head empty.");
}

void		Animal::getBrainAddress(void) const
{
	std::cout << "I have no brain." << '\n';
}
