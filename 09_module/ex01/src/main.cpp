/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:41:21 by lcouto            #+#    #+#             */
/*   Updated: 2023/04/01 19:01:53 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define DOCTEST_CONFIG_IMPLEMENT

# include "doctest.h"
# include "RPN.hpp"

int callRPN(std::string input)
{
    std::cout << "\033[33;22mTesting expression \"" << input << "\" \033[0m " << std::endl;
    RPN rpnObj(input.c_str());
    std::cout << std::endl;
    return rpnObj.getLastResult();
}

int logic(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "\033[31;1mPlease enter a string with an inverted polish mathematical expression,\nor the word \"test\" to run unit tests.\033[0m" << std::endl;
        return 1;
    }
    std::string input = argv[1];
    if (input.compare("test") == 0)
        return doctest::Context(argc, argv).run();
    else
    {
        RPN rpnObj(argv[1]);
        return 0;
    }
}

int main(int argc, char **argv)
{
    return logic(argc, argv);
}

TEST_CASE("Running tests for RPN")
{
    CHECK(callRPN("1 2 +") == 3);
    CHECK(callRPN("8 9 * 9 - 9 - 9 - 4 - 1 +") == 42);
    CHECK(callRPN("7 7 * 7 -") == 42);
    CHECK(callRPN("1 2 * 2 / 2 * 2 4 - +") == 0);
    CHECK(callRPN("(1 + 1)") == -1);
    CHECK(callRPN("0 0 /") == -1);
    CHECK(callRPN("0 0") == -1);
    CHECK(callRPN("+") == -1);
    CHECK(callRPN("1 +") == -1);
}