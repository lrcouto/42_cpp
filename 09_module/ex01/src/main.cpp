/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:41:21 by lcouto            #+#    #+#             */
/*   Updated: 2023/03/20 00:53:24 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

# include "doctest.h"

int main(int argc, char **argv)
{
    if (argc =! 1)
}

bool testTheTester(void)
{
    std::cout << "\nTesting the tester:";
    if (true)
    {
        std::cout << "\033[32;1m OK!\033[0m" << std::endl;
        return (true);
    }
    std::cout << "\033[31;1m FAILED!\033[0m" << std::endl;
    return (false);
}


TEST_CASE("Running tests for ex01")
{
    CHECK(testTheTester() == true);
}