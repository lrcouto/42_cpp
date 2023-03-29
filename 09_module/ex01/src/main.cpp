/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:41:21 by lcouto            #+#    #+#             */
/*   Updated: 2023/03/29 00:49:07 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define DOCTEST_CONFIG_IMPLEMENT

# include "doctest.h"
# include "RPN.hpp"

int logic(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "\033[31;1mPlease enter a string with an inverted polish mathematical expression,\nor the work \"test\" to run unit tests.\033[0m" << std::endl;
        return 1;
    }
    RPN rpnObj(argv[1]);
    std::string input = argv[1];
    if (input.compare("test") == 0)
        return doctest::Context(argc, argv).run();
    else
        return 0;
}

int main(int argc, char **argv)
{
    return logic(argc, argv);
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