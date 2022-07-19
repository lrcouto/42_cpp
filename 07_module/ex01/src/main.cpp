/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:04:39 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/18 21:30:11 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main(void)
{   
	std::string stringArray[6] = {"This", "is", "an", "array", "of", "strings!"};
	int intArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	double doubleArray[10] = {1.9, 2.8, 3.7, 4.6, 5.5, 6.4, 7.3, 8.2, 9.1, 0.0};

	std::cout << "\nPrinting all 3 arrays using my iter function:\n" << std::endl;
	iter(stringArray, 6, print);
	std::cout << std::endl;
	iter(intArray, 10, print);
	std::cout << std::endl;
	iter(doubleArray, 10, print);
	std::cout << std::endl;

	std::cout << "\nTesting increment function, printing again:\n" << std::endl;
	iter(intArray, 10, inc);
	iter(intArray, 10, print);
	std::cout << std::endl;
	iter(doubleArray, 10, inc);
	iter(doubleArray, 10, print);
	std::cout << std::endl;

	std::cout << "\nDecrementing thrice, printing again:\n" << std::endl;
	iter(intArray, 10, dec);
	iter(intArray, 10, dec);
	iter(intArray, 10, dec);
	iter(intArray, 10, print);
	std::cout << std::endl;
	iter(doubleArray, 10, dec);
	iter(doubleArray, 10, dec);
	iter(doubleArray, 10, dec);
	iter(doubleArray, 10, print);
	std::cout << std::endl;

	std::cout << "\nRainbowfying your arrays, please wait:\n" << std::endl;
	iter(stringArray, 6, rainbowfy);
	std::cout << std::endl;
	iter(intArray, 10, rainbowfy);
	std::cout << std::endl;
	iter(doubleArray, 10, rainbowfy);
	std::cout << '\n' << std::endl;
    return (0);
}
