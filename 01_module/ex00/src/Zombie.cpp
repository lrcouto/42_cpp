/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:28:07 by lcouto            #+#    #+#             */
/*   Updated: 2021/11/30 22:19:46 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	return ;
}

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " is dead (for real now) and will eat no more brains. [¬ x-x]¬" << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << " has risen from their grave, and hungers! BraaaAAAAAAAAiiiIIInZ! [¬ º-°]¬" << std::endl;
}