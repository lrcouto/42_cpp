/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scavtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:58:18 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/19 19:35:49 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Scavtrap.hpp"

ScavTrap::ScavTrap(void)
{
    this->m_name = "SC4V-TP";
    this->m_attackDamage = 20;
    this->m_energyPoints = 50;
    this->m_hitPoints = 100;
    std::cout << "Halt, moon citizen! I've been chosen to stand out here! Designation: SC4V-TP." << std::endl;
    return ;
}

ScavTrap::ScavTrap(std::string name)
{
    this->m_name = name;
    this->m_attackDamage = 20;
    this->m_energyPoints = 50;
    this->m_hitPoints = 100;
    std::cout << "Halt, moon citizen! I've been chosen to stand out here! Designation: " << this->getName() << std::endl;
    return ;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "My servos... are seizing..." << std::endl;
    std::cout << this->getName() << " has been destroyed in a glorious explosion." << std::endl;
    return ;
}
ScavTrap::ScavTrap(ScavTrap const &instancedObject)
{
	*this = instancedObject;
    std::cout << "Hey! Over here! I'm over heere!" << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string& target)
{
    if (this->m_energyPoints > 0 && this->m_hitPoints > 0)
    {
        std::cout << "Ha ha ha! Fall before your robot overlord!" << std::endl;
        std::cout << this->getName() << " attacks " << target << " for " << this->getAttackDamage() << " damage." << std::endl;
        this->m_energyPoints -= 1;
    }
    else
        std::cout << this->getName() << " seems to be inactive." << std::endl;
    return ;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
    if (this->m_energyPoints > 0 && this->m_hitPoints > 0)
    {
        std::cout << "Please don't shoot me, please don't shoot me, please don't shoot me!" << std::endl;
        std::cout << this->getName() << " loses " << amount << " hit points" << std::endl;
        this->m_hitPoints -= amount;
    }
    else if (this->m_energyPoints <= 0 || this->m_hitPoints <= 0)
    {
        std::cout << this->getName() << " seems to be inactive, but you can still kick it around for fun if you want." << std::endl;
        std::cout << this->getName() << " loses " << amount << " hit points" << std::endl;
        this->m_hitPoints -= amount;
    }
    return ;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
    if (this->m_energyPoints > 0 && this->m_hitPoints > 0)
    {
        std::cout << "Good as new, I think. Am I leaking?" << std::endl;
        std::cout << this->getName() << " recovers " << amount << " hit points." << std::endl;
        this->m_energyPoints -= 1;
        this->m_hitPoints += amount;
    }
    else if (this->m_energyPoints <= 0 || this->m_hitPoints <= 0)
        std::cout << this->getName() << " seems to be inactive. Maybe kick it to se if it wakes up?" << std::endl;
    return ;
}

void    ScavTrap::guardGate(void)
{
    if (this->m_energyPoints > 0 && this->m_hitPoints > 0)
    {
        std::cout << "Guarding gates is FUN!" << std::endl;
        std::cout << this->getName() << " is in Gate Keeper mode" << std::endl;
        this->m_energyPoints -= 1;
    }
    else
        std::cout << this->getName() << " seems to be inactive." << std::endl;
    return ;
}