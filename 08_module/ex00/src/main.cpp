/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:04:39 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/23 16:11:23 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>

int main(void)
{
	std::cout << "\n~~~ VECTOR TEST ~~~\n" << std::endl;

	std::vector<int> intVector;

	for (int i = 0; i < 10; i++)
		intVector.push_back((i * 10) + i);

	std::cout << "Iterating through integer vector : " << std::endl;
	std::vector<int>::iterator itVec = intVector.begin();
	while (itVec != intVector.end())
	{
		std::cout << *itVec << " ";
		itVec++;
	}
	std::cout << std::endl;
	std::cout << "\nCalling easyfind function for true result (55) : " << std::endl;
	try
	{
		std::vector<int>::iterator valueIterator = easyfind(intVector, 55);
		std::cout << "Found target " << *valueIterator << " at index " << std::distance(intVector.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nCalling easyfind function for false result (42) : " << std::endl;
	try
	{
		std::vector<int>::iterator valueIterator = easyfind(intVector, 42);
		std::cout << "Found target " << *valueIterator << "at index " << std::distance(intVector.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n~~~ DEQUE TEST ~~~\n" << std::endl;

	std::deque<int> intDeque;

	for (int i = 0; i < 10; i++)
		intDeque.push_back((i * -10) + i);

	std::cout << "Iterating through integer deque : " << std::endl;
	std::deque<int>::iterator itDeque = intDeque.begin();
	while (itDeque != intDeque.end())
	{
		std::cout << *itDeque << " ";
		itDeque++;
	}
	std::cout << std::endl;
	std::cout << "\nCalling easyfind function for true result (-45) : " << std::endl;
	try
	{
		std::deque<int>::iterator valueIterator = easyfind(intDeque, -45);
		std::cout << "Found target " << *valueIterator << " at index " << std::distance(intDeque.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nCalling easyfind function for false result (42) : " << std::endl;
	try
	{
		std::deque<int>::iterator valueIterator = easyfind(intDeque, 42);
		std::cout << "Found target " << *valueIterator << "at index " << std::distance(intDeque.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n~~~ LIST TEST ~~~\n" << std::endl;

	std::list<int> intList;

	for (int i = 0; i < 10; i++)
		intList.push_back((i * 15) + i);

	std::cout << "Iterating through integer list : " << std::endl;
	std::list<int>::iterator itList = intList.begin();
	while (itList != intList.end())
	{
		std::cout << *itList << " ";
		itList++;
	}
	std::cout << std::endl;
	std::cout << "\nCalling easyfind function for true result (112) : " << std::endl;
	try
	{
		std::list<int>::iterator valueIterator = easyfind(intList, 112);
		std::cout << "Found target " << *valueIterator << " at index " << std::distance(intList.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nCalling easyfind function for false result (42) : " << std::endl;
	try
	{
		std::list<int>::iterator valueIterator = easyfind(intList, 42);
		std::cout << "Found target " << *valueIterator << "at index " << std::distance(intList.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n~~~ SET TEST ~~~\n" << std::endl;

	std::set<int> intSet;

	for (int i = 0; i < 10; i++)
		intSet.insert((i * 8 * 2));

	std::cout << "Iterating through integer set : " << std::endl;
	std::set<int>::iterator itSet = intSet.begin();
	while (itSet != intSet.end())
	{
		std::cout << *itSet << " ";
		itSet++;
	}
	std::cout << std::endl;
	std::cout << "\nCalling easyfind function for true result (112) : " << std::endl;
	try
	{
		std::set<int>::iterator valueIterator = easyfind(intSet, 112);
		std::cout << "Found target " << *valueIterator << " at index " << std::distance(intSet.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nCalling easyfind function for false result (42) : " << std::endl;
	try
	{
		std::set<int>::iterator valueIterator = easyfind(intSet, 42);
		std::cout << "Found target " << *valueIterator << "at index " << std::distance(intSet.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n~~~ MAP TEST ~~~\n" << std::endl;

	std::map<char, int> intMap;

	for (int i = 0; i < 10; i++)
		intMap.insert(std::pair<char, int>(('A' + i), (i * 12)));

	std::cout << "Iterating through integer map : " << std::endl;
	std::map<char, int>::iterator itMap = intMap.begin();
	while (itMap != intMap.end())
	{
		std::cout << "[" << itMap->first << ", " << itMap->second << "]" << std::endl;
		itMap++;
	}
	std::cout << std::endl;
	std::cout << "\nCalling easyfind function for true result (72) : " << std::endl;
	try
	{
		std::map<char, int>::iterator valueIterator = easyfind(intMap, 72);
		std::cout << "Found target at key: [" << valueIterator->first << "], value: [" << valueIterator->second << "]" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nCalling easyfind function for false result (42) : " << std::endl;
	try
	{
		std::map<char, int>::iterator valueIterator = easyfind(intMap, 42);
		std::cout << "Found target at key: [" << valueIterator->first << "] value: [" << valueIterator->second << "]" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

