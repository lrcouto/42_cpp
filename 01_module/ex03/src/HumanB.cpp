/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:31:56 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/14 02:14:15 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
    this->_weapon = NULL;
    std::cout << this->_name << " enters the arena, empty-handed " << std::endl;
	return ;
}

HumanB::~HumanB(void)
{
    std::cout << this->_name << " realizes it's not too late to give up on their life of fighting, and leaves the arena forever" << std::endl;
    return ;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
    std::cout << this->_name << " acquires a " << this->_weapon->getType() << std::endl;
}

void    HumanB::attack(void)
{
    if (this->_weapon)
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " attacks with their fists" << std::endl;
}