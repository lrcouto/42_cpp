/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:55:16 by lcouto            #+#    #+#             */
/*   Updated: 2021/11/04 18:23:04 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.hpp"

PhoneBook::PhoneBook(void)
{
	this->_insertionIndex = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

std::string	PhoneBook::_truncateLine(std::string line)
{
	std::string	newLine;

	if (line.length() > 10)
	{
		newLine = line.substr(0, 10);
		newLine[9] = '.';
	}
	else
		newLine = line;
	return (newLine);
}

void PhoneBook::_printContact(int index)
{
	std::cout << index << " |";
	std::cout << std::right << std::setw(10) << _truncateLine(this->_contacts[index].getFirstName()) << " |";
	std::cout << std::right << std::setw(10) << _truncateLine(this->_contacts[index].getLastName()) << " |";
	std::cout << std::right << std::setw(10) << _truncateLine(this->_contacts[index].getNickname()) << " |";
	std::cout << std::endl;
}

void PhoneBook::_printFullContactInfo(int index)
{
	if (this->_contacts[index].isEmpty() == true)
	{
		std::cout << "The entry under this index is empty." << std::endl;
	}
	else
	{
		std::cout << "This is all the information I have on Contact #" << index << ":" << std::endl;
		std::cout << "FIRST NAME: " << this->_contacts[index].getFirstName() << std::endl;
		std::cout << "LAST NAME: " << this->_contacts[index].getLastName() << std::endl;
		std::cout << "PHONE NUMBER: " << this->_contacts[index].getPhoneNumber() << std::endl;
		std::cout << "NICKNAME: " << this->_contacts[index].getNickname() << std::endl;
		std::cout << "DARKEST SECRET: " << this->_contacts[index].getDarkestSecret() << std::endl;
	}
	std::cout << "Waiting for user input." << std::endl;
}

void PhoneBook::_fetchByIndex(void)
{
	std::string charIndex;
	int index;

	std::getline(std::cin, charIndex);
	index = atoi(charIndex.c_str());

	if (index >= 0 && index <= 7)
		_printFullContactInfo(index);
	else
	{
		std::cout << "I'm a very stupid phonebook and I can only count from 0 to 7." << std::endl;
		std::cout << "Waiting for user input." << std::endl;
	}
}

void PhoneBook::add(void)
{
	std::string buffer;

	this->_contacts[_insertionIndex].setFirstName(buffer);
	this->_contacts[_insertionIndex].setLastName(buffer);
	this->_contacts[_insertionIndex].setPhoneNumber(buffer);
	this->_contacts[_insertionIndex].setNickname(buffer);
	this->_contacts[_insertionIndex].setDarkestSecret(buffer);

	std::cout << "I have saved your contact on index " << _insertionIndex << "." << std::endl;
	std::cout << "Waiting for user input." << std::endl;


	if (_insertionIndex <= 6)
		_insertionIndex++;
	else
		_insertionIndex = 0;
}

void PhoneBook::search(void)
{
	std::cout << "These are all the contacts I know about:" << std::endl;
	for (int i = 0; i < 8; i++)
		_printContact(i);
	std::cout << "Input the contact index to see more." << std::endl;
	_fetchByIndex();
}

void PhoneBook::exit(void)
{
	std::cout << "Goodbye!" << std::endl;
}