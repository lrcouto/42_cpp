/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:41:21 by lcouto            #+#    #+#             */
/*   Updated: 2023/04/02 15:08:21 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define DOCTEST_CONFIG_IMPLEMENT

# include "doctest.h"
# include "PmergeMe.hpp"

int callPmergeMe()
{
    return 0;
}

int logic(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "\033[31;1mPlease enter a sequence of positive integers,\nor the word \"test\" to run unit tests.\033[0m" << std::endl;
        exit(1);
    }
    std::string input = argv[1];
    if (input.compare("test") == 0)
        return doctest::Context(argc, argv).run();
    else
    {
        PmergeMe sorterObj(argc, argv);
        return 0;
    }
}

int main(int argc, char **argv)
{
    return logic(argc, argv);
}

TEST_CASE("Running tests for PmergeMe")
{
    CHECK(callPmergeMe() == 0);

}