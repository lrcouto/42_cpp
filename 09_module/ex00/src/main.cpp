/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:41:21 by lcouto            #+#    #+#             */
/*   Updated: 2023/03/14 23:05:29 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

# include "doctest.h"

bool testCreateEmptyVector(void)
{
    std::cout << "\nTesting ft::vector constructor:";
    ft::vector<int> myVector;
    void *ptr = &myVector;
    if (ptr != NULL)
    {
        std::cout << "\033[32;1m OK!\033[0m" << std::endl;
        return (true);
    }
    std::cout << "\033[31;1m FAILED!\033[0m" << std::endl;
    return (false);
}

bool testCopyConstructor(void)
{
    std::cout << "\nTesting ft::vector copy constructor:";
    ft::vector<int> myVector;
    ft::vector<int> myVector2(myVector);
    void *ptr = &myVector2;
    if (ptr != NULL && typeid(myVector) == typeid(myVector2))
    {
        std::cout << "\033[32;1m OK!\033[0m" << std::endl;
        return (true);
    }
    std::cout << "\033[31;1m FAILED!\033[0m" << std::endl;
    return (false);
}

TEST_CASE("Checking if the vector was set up properly")
{
    CHECK(testCreateEmptyVector() == true);
    CHECK(testCopyConstructor() == true);
}