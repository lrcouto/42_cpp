/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:28:07 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/13 18:06:44 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " is dead (for real now) and will eat no more brains. [¬ x-x]¬" << std::endl;
	return ;
}

void	Zombie::setZombieName(std::string name)
{
	this->_name = name;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << " has risen from their grave, and hungers! BraaaAAAAAAAAiiiIIInZ! [¬ º-°]¬" << std::endl;
}