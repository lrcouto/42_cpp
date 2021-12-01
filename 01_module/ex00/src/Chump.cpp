/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Chump.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:29:10 by lcouto            #+#    #+#             */
/*   Updated: 2021/11/30 22:20:37 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie *chump;

	chump = newZombie(name);
	chump->announce();
	std::cout << "their memory address is " << &chump << std::endl;
	std::cout << "\nYou aim your shotgun at the zombie's head and pull the trigger" << std::endl;
	delete chump;
	std::cout << "\n";
}