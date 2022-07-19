/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:04:39 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/18 22:40:46 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main(void)
{
	std::cout << "\nInitializing integer array of size 10\n" << std::endl;

	Array<int> intArray = Array<int>(10);

	std::cout << "\nPopulating array\n" << std::endl;

	for (unsigned int i = 0; i < intArray.getSize(); i++)
	{
		intArray[i] = i;
		std::cout  << intArray[i] << std::endl;
	}


	std::cout << "\nPurposefully going out of array boundaries to trigger exception\n" << std::endl;

	for (unsigned int i = 0; i < intArray.getSize() + 1; i++)
	{
		try
		{
			std::cout << intArray[i] <<  std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\nAccessing specific index element through overloaded operator\n" << std::endl;

	std::cout << "\nOriginal value:" << std::endl;
	std::cout << "intArray[2]: " << intArray[2] << std::endl;
	intArray[2] = 2147483627;
	std::cout << "\nNew value -> INT_MAX: " << std::endl;
	std::cout << "intArray[2]: " << intArray[2] << std::endl;


	std::cout << "\nTesting copy constructor\n" << std::endl;

	Array<int> intArrayCopy(intArray);
	std::cout << "intArrayCopy[2]: " << intArrayCopy[2] << std::endl;
	std::cout << "Changing value on original array" << intArrayCopy[2] << std::endl;
	intArray[2] = -1;
	std::cout << "intArray[2]: " << intArray[2] << std::endl;
	std::cout << "intArrayCopy[2]: " << intArrayCopy[2] << std::endl;


	std::cout << "\nTesting = operator overload to a smaller array than the original one:\n" << std::endl;

	Array<int> smallArray(1);
	smallArray = intArray;

	std::cout << "\nCreating and testing char array\n" << std::endl;

	Array<char> charArray(10);

	for (unsigned int i = 0; i < charArray.getSize(); i++)
	{
		try
		{
			charArray[i] = 'A' + i;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	for (unsigned int i = 0; i < charArray.getSize(); i++)
	{
		try
		{
			std::cout << charArray[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
		std::cout << "\nCreating and testing double array\n" << std::endl;

	Array<double> doubleArray(10);

	for (unsigned int i = 0; i < doubleArray.getSize(); i++)
	{
		try
		{
			doubleArray[i] = 1.7 + (double)(i * 1.3);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	for (unsigned int i = 0; i < doubleArray.getSize(); i++)
	{
		try
		{
			std::cout << doubleArray[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	return (0);
}

