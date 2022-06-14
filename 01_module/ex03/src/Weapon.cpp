/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:23:10 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/14 02:49:34 by lcouto           ###   ########.fr       */
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

void Weapon::setType(std::string weaponType)
{
	this->_type = weaponType;
}

std::string	&Weapon::getType(void)
{
	return (this->_type);
}


