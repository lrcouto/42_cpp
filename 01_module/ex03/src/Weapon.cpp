/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:23:10 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/15 20:29:28 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon(std::string weaponType)
{
	this->_type = weaponType;
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

void	Weapon::setType(std::string weaponType)
{
	std::cout << "The fighter drops their " << this->getType();
	this->_type = weaponType;
	std::cout << " and grabs a " << this->getType() << std::endl;
}

std::string	const	&Weapon::getType(void)
{
	return (this->_type);
}


