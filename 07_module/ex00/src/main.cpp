/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:04:39 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/18 23:00:37 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Whatever.hpp"

int main(void)
{   
	std::cout << "\nComparing integers" << std::endl;
	std::cout << "min(5, 10) = " << min(5, 10) << std::endl;
	std::cout << "max(5, 10) = " << max(5, 10) << std::endl;
	std::cout << "\nComparing floats" << std::endl;
	std::cout << "min(5.5f, 10.7f) = " << min(5.5f, 10.7f) << std::endl;
	std::cout << "max(5.5f, 10.7f) = " << max(5.5f, 10.7f) << std::endl;
	std::cout << "\nComparing doubles" << std::endl;
	std::cout << "min(5.5, 10.7) = " << min(5.5, 10.7) << std::endl;
	std::cout << "max(5.5, 10.7) = " << max(5.5, 10.7) << std::endl;
	std::cout << "\nComparing chars" << std::endl;
	std::cout << "min('a', 'A') = " << min('a', 'A') << std::endl;
	std::cout << "max('a', 'A') = " << max('a', 'A') << std::endl;
	std::cout << "\nComparing strings" << std::endl;
	std::cout << "min(\"abcd\", \"ABCD\") = " << min("abcd", "ABCD") << std::endl;
	std::cout << "max(\"abcd\", \"ABCD\") = " << max("abcd", "ABCD") << std::endl;
	std::cout << "\nSwapping integers" << std::endl;
	
	int a, b;
	a = 7;
	b = 12;

	std::cout << "integer a = " << a << " and integer b = " << b << std::endl;
	std::cout << "Now swapping..." << std::endl;
	swap(a, b);
	std::cout << "integer a = " << a << " and integer b = " << b << std::endl;

	std::cout << "\nSwapping floats" << std::endl;
	
	float c, d;
	c = 7.5f;
	d = 12.8f;

	std::cout << "float c = " << c << " and float d = " << d << std::endl;
	std::cout << "Now swapping..." << std::endl;
	swap(c, d);
	std::cout << "float c = " << c << " and float d = " << d << std::endl;

	std::cout << "\nSwapping doubles" << std::endl;
	
	double e, f;
	e = 7.1;
	f = 12.2;

	std::cout << "double e = " << e << " and double f = " << f << std::endl;
	std::cout << "Now swapping..." << std::endl;
	swap(e, f);
	std::cout << "double e = " << e << " and double f = " << f << std::endl;

	std::cout << "\nSwapping strings" << std::endl;
	
	std::string g = "World";
	std::string h = "Hello";

	std::cout << "string g = " << g << " and string f = " << h << std::endl;
	std::cout << "Now swapping..." << std::endl;
	swap(g, h);
	std::cout << "string g = " << g << " and string h = " << h << std::endl;

	std::cout << "\nSwapping with pointers" << std::endl;
	
	int *i = &a;
	int *j = &b;

	std::cout << "pointer i's address is " << &i << " and it's pointing to memory " << i << std::endl;
	std::cout << "pointer j's address is " << &j << " and it's pointing to memory " << j << std::endl;
	std::cout << "Now swapping..." << std::endl;
	swap(i, j);
	std::cout << "pointer i's address is " << &i << " and it's pointing to memory " << i << std::endl;
	std::cout << "pointer j's address is " << &j << " and it's pointing to memory " << j << std::endl;
	std::cout << std::endl;
    return (0);
}
