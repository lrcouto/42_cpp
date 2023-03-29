/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:28:58 by lcouto            #+#    #+#             */
/*   Updated: 2023/03/19 13:28:58 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

RPN::RPN(): _userInput("")
{
    return;
}

RPN::RPN(const char *input)
{
    setUserInput(input);
    processInput();
    return;
}

RPN::~RPN()
{
    return;
}

RPN::RPN(RPN const &other) 
{
    *this = other;
}

RPN &RPN::operator=(RPN const &other) 
{
    if (this == &other)
        return *this;

    this->_operationStack = other._operationStack;

    return *this;
}

void RPN::setUserInput(const char *input)
{
    this->_userInput = input;
}

void RPN::processInput()
{
    std::string expression = this->_userInput;

    for (std::string::const_iterator it = expression.begin(); it != expression.end(); it++)
    {
        char c = *it;

        if(std::isdigit(c))
        {
            this->_operationStack.push(c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            int second = this->_operationStack.top();
            this->_operationStack.pop();
            int first = this->_operationStack.top();
            this->_operationStack.pop();

            switch (c)
            {
                case '+':
                    this->_operationStack.push(first + second);
                    break;
                case '-':
                    this->_operationStack.push(first - second);
                    break;
                case '*':
                    this->_operationStack.push(first * second);
                    break;
                case '/':
                    this->_operationStack.push(first / second);
                    break;
                default:
                    std::cerr << "\033[31;1mUnrecognized operator\033[0m" << std::endl;
                    return ;
            }
        }
    }
    std::cout << this->_operationStack.top() << std::endl;
}

// TODO: Clean up input, do error checking, write unit tests.
