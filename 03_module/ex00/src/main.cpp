/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 02:06:58 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/19 03:57:29 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"
# include <iostream>

int	main(void)
{
	std::cout << "\n ------- Creating ClapTrap from default constructor ------- \n" << std::endl;

	ClapTrap claptrap;

	std::cout << "\n ------- Creating named ClapTrap from name constructor ------- \n" << std::endl;

	ClapTrap namedClaptrap("Claptrap P. Claptrappington");

	std::cout << "\n ------- Creating ClapTrap from copy constructor ------- \n" << std::endl;

	ClapTrap copyTrap(claptrap);

	std::cout << "\n ------- Dealing overkill damage to copy ClapTrap ------- \n" << std::endl;

	copyTrap.takeDamage(12);

	std::cout << "\n ------- Attempt to repair downed ClapTrap ------- \n" << std::endl;

	copyTrap.beRepaired(5);

	std::cout << "\n ------- Performing attacks. ------- \n" << std::endl;

	claptrap.attack("Ultimate Badass Goliath");
	namedClaptrap.attack("Vermivorous the Invincible");
	copyTrap.attack("Handsome Jack");

	std::cout << "\n ------- Over repairing ClapTrap to deplete energy. ------- \n" << std::endl;

	claptrap.beRepaired(1);
	claptrap.beRepaired(1);
	claptrap.beRepaired(1);
	claptrap.beRepaired(1);
	claptrap.beRepaired(1);
	claptrap.beRepaired(1);
	claptrap.beRepaired(1);
	claptrap.beRepaired(1);
	claptrap.beRepaired(1);
	claptrap.beRepaired(1);

	std::cout << "\n ------- Attempt attack with depleted energy. ------- \n" << std::endl;

	claptrap.attack("Ultimate Badass Goliath");

	std::cout << "\n ------- Damage active ClapTrap. ------- \n" << std::endl;

	namedClaptrap.takeDamage(5);

	std::cout << "\n ------- Damage depleted ClapTrap. ------- \n" << std::endl;

	claptrap.takeDamage(5);

	std::cout << "\n ------- End program. ------- \n" << std::endl;

	return (0);
}