/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:40:26 by lcouto            #+#    #+#             */
/*   Updated: 2021/11/04 01:40:33 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <PhoneBook.hpp>

void	runPhoneBook(PhoneBook *pbook)
{
	std::string	userInput;

	std::getline(std::cin, userInput);
	if (userInput == "SEARCH")
		pbook->search();
}

int	main(void)
{
	PhoneBook	pbook;

	std::cout << "This is my shitty phonebook. Input your command." << std::endl;
	runPhoneBook(&pbook);
	return (0);
}