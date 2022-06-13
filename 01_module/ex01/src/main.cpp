/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:29:04 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/13 18:34:36 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int howManyZombies = 10;
	std::string zombieName = "Epaminondas";
	
	std::cout << "\nThe ZOMBIE HORDE is coming towards you!\n" << std::endl;
	std::cout << "There are " << howManyZombies << " of them!\n" << std::endl;
	std::cout << "They all have the same name because this exercise is poorly written!\n" << std::endl;

	Zombie *myHorde = zombieHorde(howManyZombies, zombieName);

	std::cout << "\nQuick, use your magic " << howManyZombies << "-zombie-killing-shotgun to dispose of all of the " << zombieName << "!!\n" << std::endl;

	destroyHorde(howManyZombies, myHorde);

	std::cout << "\nThe horde is no more, and now this program will end. Goodbye.\n" << std::endl;
	return (0);
}