/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:04:39 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/24 02:47:32 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\nTesting span of the elements suggested on the subject - [6 3 17 9 11]\n" << std::endl;
	
	Span subjectSpan = Span(5);
	subjectSpan.addNumber(6);
	subjectSpan.addNumber(3);
	subjectSpan.addNumber(17);
	subjectSpan.addNumber(9);
	subjectSpan.addNumber(11);
	std::cout << "SHORTEST SPAN: " << subjectSpan.shortestSpan() << " - LONGEST SPAN: "<< subjectSpan.longestSpan() << std::endl;

	std::cout << "\nTesting span of negative numbers - [-6 -3 -17 -9 -11 -12 -54 -100 -2345 -10000]\n" << std::endl;
	
	Span negativeSpan = Span(10);
	negativeSpan.addNumber(-6);
	negativeSpan.addNumber(-3);
	negativeSpan.addNumber(-17);
	negativeSpan.addNumber(-9);
	negativeSpan.addNumber(-11);
	negativeSpan.addNumber(-12);
	negativeSpan.addNumber(-54);
	negativeSpan.addNumber(-100);
	negativeSpan.addNumber(-2345);
	negativeSpan.addNumber(-10000);
	std::cout << "SHORTEST SPAN: " << negativeSpan.shortestSpan() << " - LONGEST SPAN: "<< negativeSpan.longestSpan() << std::endl;

	std::cout << "\nTesting span of random numbers on a vector with 15000 elements\n" << std::endl;

	srand(time(NULL));

	std::vector<int> temp;
	Span spanRandomNumbers = Span(15000);
	for (int i = 0; i < 15000; i++)
		temp.push_back(i % 2 == 0 ? i * 14653 : i * -28490);
	spanRandomNumbers.addNumber(temp.begin(), temp.end());
	std::cout << "SHORTEST SPAN: " << spanRandomNumbers.shortestSpan() << " - LONGEST SPAN: "<< spanRandomNumbers.longestSpan() << std::endl;
	std::cout << std::endl;
}

