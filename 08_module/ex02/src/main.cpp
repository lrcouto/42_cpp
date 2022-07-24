/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:04:39 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/24 14:44:21 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int	main(void)
{
    std::cout << "\nInstantiating integer MutantStack object and pushing elements into it: \n" << std::endl;

    MutantStack<int>	mutantStack;

    mutantStack.push(10);
    mutantStack.push(25);
    mutantStack.push(15);
    mutantStack.push(9);
    mutantStack.push(89);
    mutantStack.push(42);

    std::cout << "\nUsing iterators to print my stack: \n" << std::endl;

    MutantStack<int>::iterator bottom = mutantStack.begin();
    MutantStack<int>::iterator top = mutantStack.end();

    while(top != bottom)
	{
        std::cout << *bottom << std::endl;
        bottom++;
	}

    std::cout << "\nNotice the stack is being printed BOTTOM to TOP, as the first element of a stack is the one on the bottom." << std::endl;

    std::cout << "Now using reverse iterators to print the stack TOP to BOTTOM \n" << std::endl;

    MutantStack<int>::reverse_iterator rbottom = mutantStack.rend();
    MutantStack<int>::reverse_iterator rtop = mutantStack.rbegin();

    while(rbottom != rtop)
	{
        std::cout << *rtop << std::endl;
        rtop++;
	}

	std::cout << "\nNow for stack operations, popping top element of the stack and printing again\n" << std::endl;

	mutantStack.pop();

	rtop = mutantStack.rbegin();

	while(rbottom != rtop)
	{
        std::cout << *rtop << std::endl;
        rtop++;
	}

	std::cout << "\nNow pushing a new element on top of the stack.\n" << std::endl;

	mutantStack.push(123);

	rtop = mutantStack.rbegin();

	while(rbottom != rtop)
	{
        std::cout << *rtop << std::endl;
        rtop++;
	}

	std::cout << "\nThe reason why this works and we can do this at all is because the STL stack container is built on top of the" << '\n'
	<< "double-ended queue (deque) structure. Its deque iterators can be accessed through a protected attribute named \"c\"." << '\n'
	<< "By writing a class that inherits from the stack class, you can create public methods to access its protected attributes.\n\n" 
	<< "That's it, that was the end of the C++ piscine.\n" << std::endl;
}

