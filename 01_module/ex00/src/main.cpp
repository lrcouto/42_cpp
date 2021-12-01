/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:29:04 by lcouto            #+#    #+#             */
/*   Updated: 2021/11/30 22:21:10 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	stackZombie("Adalberto");
	Zombie	stackZombie2("Roberto");
	Zombie	stackZombie3("Dagoberto");

	std::cout << "A zombie was created on the STACK, but wasn't announced yet." << std::endl;
	std::cout << "their memory address is " << &stackZombie << "" << std::endl ;
	std::cout << "\nA zombie was created on the STACK, but wasn't announced yet." << std::endl;
	std::cout << "their memory address is " << &stackZombie2 << "" << std::endl;
	std::cout << "\nA zombie was created on the STACK, but wasn't announced yet." << std::endl;
	std::cout << "their memory address is " << &stackZombie3 << "" << std::endl;
	std::cout << "\nI will now create three zombies on the HEAP, and destroy them.\n" << std::endl;
	randomChump("Valdo");
	randomChump("Givaldo");
	randomChump("Etevaldo");
	std::cout << "Now the zombies on the STACK will be announced.\n" << std::endl;
	stackZombie.announce();
	stackZombie2.announce();
	stackZombie3.announce();
	std::cout << "\nThe zombies on the STACK will be destroyed as the program ends.\n" << std::endl;
	return (0);
}