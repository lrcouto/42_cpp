/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fragtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:14:24 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/19 20:34:45 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fragtrap.hpp"

FragTrap::FragTrap(void)
{
    this->m_name = "FR4G-TP";
    this->m_attackDamage = 30;
    this->m_energyPoints = 100;
    this->m_hitPoints = 100;
    std::cout << "You want me? To join you? I am SO excited. We will be best friends. Designation: FR4G-TP." << std::endl;
    return ;
}

FragTrap::FragTrap(std::string name)
{
    this->m_name = name;
    this->m_attackDamage = 30;
    this->m_energyPoints = 100;
    this->m_hitPoints = 100;
    std::cout << "You want me? To join you? I am SO excited. We will be best friends. Designation: " << this->getName() << std::endl;
    return ;
}

FragTrap::~FragTrap(void)
{
    std::cout << "I'm afraid. My mind is going. I can feel it. My mind is going! There's no question about it. I can feel it. I'm a... fraid." << std::endl;
    std::cout << this->getName() << " has been destroyed in a glorious explosion." << std::endl;
    return ;
}
FragTrap::FragTrap(FragTrap const &instancedObject)
{
	*this = instancedObject;
    std::cout << "F to the R to the 4 to the G to the WHAAT!" << std::endl;
	return ;
}

void	FragTrap::attack(const std::string& target)
{
    if (this->m_energyPoints > 0 && this->m_hitPoints > 0)
    {
        std::cout << "Is that what people look like inside?" << std::endl;
        std::cout << this->getName() << " attacks " << target << " for " << this->getAttackDamage() << " damage." << std::endl;
        this->m_energyPoints -= 1;
    }
    else
        std::cout << this->getName() << " seems to be inactive." << std::endl;
    return ;
}

void	FragTrap::takeDamage(unsigned int amount)
{
    if (this->m_energyPoints > 0 && this->m_hitPoints > 0)
    {
        std::cout << "I'm too pretty to die!" << std::endl;
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

void	FragTrap::beRepaired(unsigned int amount)
{
    if (this->m_energyPoints > 0 && this->m_hitPoints > 0)
    {
        std::cout << "You can't keep a good 'bot down!" << std::endl;
        std::cout << this->getName() << " recovers " << amount << " hit points." << std::endl;
        this->m_energyPoints -= 1;
        this->m_hitPoints += amount;
    }
    else if (this->m_energyPoints <= 0 || this->m_hitPoints <= 0)
        std::cout << this->getName() << " seems to be inactive. Maybe kick it to see if it wakes up?" << std::endl;
    return ;
}

void    FragTrap::highFiveGuys(void)
{
    if (this->m_energyPoints > 0 && this->m_hitPoints > 0)
    {
        std::cout << "HIGH FIVES GUYS!!!" << std::endl;
        std::cout << this->getName() << " extends his arm, expectantly waiting for a high five." << std::endl;
        this->m_energyPoints -= 1;
    }
    else
        std::cout << this->getName() << " seems to be inactive." << std::endl;
    return ;
}