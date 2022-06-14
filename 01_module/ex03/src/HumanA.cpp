/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:31:59 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/14 02:46:38 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
	this->_name = name;
    std::cout << this->_name << " enters the arena, holding a " << this->_weapon.getType() << std::endl;
	return ;
}

HumanA::~HumanA(void)
{
    std::cout << this->_name << " despairs, regretting their life of violence, and falls on their own " << this->_weapon.getType() << std::endl;
    return ;
}

void    HumanA::attack(void)
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
    return ;
}