/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:29:04 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/13 20:12:46 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int	main(void)
{
	std::string thisIsBrain = "HI THIS IS BRAIN";
	std::string* stringPTR = &thisIsBrain;
	std::string& stringREF = thisIsBrain;

	std::cout << "\n### VALUES ###\n" << std::endl;

	std::cout << "Original String: " << thisIsBrain << std::endl;
	std::cout << "Pointer:" << stringPTR << std::endl;
	std::cout << "Reference: " << stringREF << std::endl;

	std::cout << "\nNotice that the reference prints the same value as the original string" << std::endl;
	std::cout << "while the pointer prints the address of the string" << std::endl;

	std::cout << "\n### ADDRESSES ###\n" << std::endl;

	std::cout << "Original String: " << &thisIsBrain << std::endl;
	std::cout << "Pointer:" << &stringPTR << std::endl;
	std::cout << "Reference: " << &stringREF << std::endl;

	std::cout << "\nNotice how the original string and the reference print out the same address" << std::endl;
	std::cout << "which is the same one that was stored in our pointer variable. Printing the address" << std::endl;
	std::cout << "of the pointer shows a different value, which is the pointer's own value." << std::endl;

	std::cout << "\nLet's dereference our pointer and see what it prints out" << std::endl;

	std::cout << "Pointer:" << *stringPTR << std::endl;

	std::cout << "\nA reference and a dereferenced pointer work virtually the same way." << std::endl;
	std::cout << "There are further differences, but if you're seeing this program," << std::endl;
	std::cout << "you are probably evaluating me right now and I will explain them to you." << std::endl;

	std::cout << "\nGoodbye!\n" << std::endl;

	return (0);
}