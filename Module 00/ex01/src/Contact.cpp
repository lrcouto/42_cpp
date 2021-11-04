/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:55:37 by lcouto            #+#    #+#             */
/*   Updated: 2021/11/04 18:25:47 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string Contact::getFirstName(void)
{
	return (this->_firstName);
}

std::string Contact::getLastName(void)
{
	return (this->_lastName);
}

std::string Contact::getPhoneNumber(void)
{
	return (this->_phoneNumber);
}

std::string Contact::getNickname(void)
{
	return (this->_nickname);
}

std::string Contact::getDarkestSecret(void)
{
	return (this->_darkestSecret);
}

void Contact::setFirstName(std::string buffer)
{
	std::cout << "Input your contact's first name:";
	std::getline(std::cin, buffer);
	this->_firstName = buffer;
}

void Contact::setLastName(std::string buffer)
{
	std::cout << "Input your contact's last name:";
	std::getline(std::cin, buffer);
	this->_lastName = buffer;
}

void Contact::setPhoneNumber(std::string buffer)
{
	std::cout << "Input your contact's phone number:";
	std::getline(std::cin, buffer);
	this->_phoneNumber = buffer;
}

void Contact::setNickname(std::string buffer)
{
	std::cout << "Input a nickname for your contact:";
	std::getline(std::cin, buffer);
	this->_nickname = buffer;
}

void Contact::setDarkestSecret(std::string buffer)
{
	std::cout << "Input your contact's darkest, dirtiest, most embarrassing secret:";
	std::getline(std::cin, buffer);
	this->_darkestSecret = buffer;
}

bool Contact::isEmpty(void)
{
    if (this->getFirstName().empty())
		return (true);
	if (this->getLastName().empty())
		return (true);
    if (this->getPhoneNumber().empty())
		return (true);
	if (this->getNickname().empty())
		return (true);
	if (this->getDarkestSecret().empty())
		return (true);
	return (false);
}
