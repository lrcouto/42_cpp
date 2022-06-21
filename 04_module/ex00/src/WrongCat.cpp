/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:24:04 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/21 01:41:23 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"
# include <iostream>

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	return ;
}

WrongCat::~WrongCat(void)
{
	return ;
}

WrongCat::WrongCat(WrongCat const &instancedObject)
{
	*this = instancedObject;
	return ;
}

WrongCat &WrongCat::operator=(WrongCat const &rightHandSide)
{
	this->type = rightHandSide.getType();
	return (*this);
}

void        WrongCat::makeSound(void) const
{
    std::cout << "M̵͈̩̖͎̦̅̈́́̎̾̈́̊̃͐͑̎̈́͛̈́̾͝ ̸̡̙̘̝̬̯̭̺̣̼̞̟̪̬̯̖͛̍̊͝Ě̵̝͐̒̈́̇͛͝ ̶̛͖͉͐̀̄̍̇́̀̄̂̿̓͠͝ͅO̵̧͖̞̦̮̬͋̓̌́͜ ̵̬͖͚̠̹̭̫͎̖̜̙̥͗͌̈́̊̐͐̓͒͊̓̒̅̚̚͝Ẃ̸̙̯̹̗" << '\n';
    return ;
}
