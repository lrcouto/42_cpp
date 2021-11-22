/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:40:26 by lcouto            #+#    #+#             */
/*   Updated: 2021/11/04 17:54:23 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.hpp"

void	runPhoneBook(PhoneBook *pbook)
{
	std::string	userInput;

	while(1)
	{
		std::getline(std::cin, userInput);
		if (userInput == "SEARCH")
			pbook->search();
		else if (userInput == "ADD")
			pbook->add();
		else if (userInput == "EXIT")
		{
			pbook->exit();
			return ;
		}
		else
			std::cout << "I am a very dumb phonebook and I only understand ADD, SEARCH or EXIT." << std::endl;
	}
}

int	main(void)
{
	PhoneBook	pbook;

	std::cout << "Hello! I am a shitty phonebook. Input your command." << std::endl;
	runPhoneBook(&pbook);
	return (0);
}