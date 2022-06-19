/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 02:06:58 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/19 19:21:27 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Claptrap.hpp"
# include "Scavtrap.hpp"
# include <iostream>

int	main(void)
{
	std::cout << "\n ------- Creating ClapTrap from default constructor ------- \n" << std::endl;

	ClapTrap claptrap;

	std::cout << "\n ------- Creating named ClapTrap from name constructor ------- \n" << std::endl;

	ClapTrap namedClaptrap("Claptrap P. Claptrappington");

	std::cout << "\n ------- Creating ScavTrap from name constructor ------- \n" << std::endl;

	ScavTrap namedScavtrap("Scavtrap");

	std::cout << "\n ------- Creating ScavTrap from default constructor ------- \n" << std::endl;

	ScavTrap scavtrap;

	std::cout << "\n ------- Performing attacks. ------- \n" << std::endl;

	claptrap.attack("Ultimate Badass Goliath");
	namedClaptrap.attack("Vermivorous the Invincible");
	scavtrap.attack("Ultimate Badass Goliath");
	namedScavtrap.attack("Vermivorous the Invincible");

	std::cout << "\n ------- Repairing. ------- \n" << std::endl;

	claptrap.beRepaired(1);
	scavtrap.beRepaired(1);

	std::cout << "\n ------- Taking damage. ------- \n" << std::endl;

	namedClaptrap.takeDamage(5);
	namedScavtrap.takeDamage(5);

	std::cout << "\n ------- Scavtrap guarding gate. ------- \n" << std::endl;

	scavtrap.guardGate();

	std::cout << "\n ------- End program. ------- \n" << std::endl;

	return (0);
}