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
# include <algorithm>
# include <cctype>

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

int  RPN::getLastResult(void)
{
    if (this->_operationStack.empty())
        return -1;
    else
        return this->_operationStack.top();
}

bool validateString(std::string expression)
{
    std::string operators = "+-*/";
    std::string digits = "0123456789";
    bool containsOperator = false;
    bool containsDigit = false;

    for (std::string::const_iterator it = operators.begin(); it != operators.end(); ++it) {
        if (expression.find(*it) != std::string::npos) {
            containsOperator = true;
        }
    }
    for (std::string::const_iterator it = digits.begin(); it != digits.end(); ++it) {
        if (expression.find(*it) != std::string::npos) {
            containsDigit = true;
        }
    }
    if (containsDigit && containsOperator)
        return true;
    else if (!containsOperator)
    {
        std::cerr << "\033[31;1mError - String does not contain any operators.\033[0m" << std::endl;
        return false;
    }
    else if (!containsDigit)
    {
        std::cerr << "\033[31;1mError - String does not contain any digits.\033[0m" << std::endl;
        return false;
    }
    return false;
}

void RPN::processInput()
{
    std::string expression = this->_userInput;

    expression.erase(std::remove_if(expression.begin(), expression.end(), ::isspace), expression.end());
    if (!::validateString(expression))
        return ;
    while (!this->_operationStack.empty())
        this->_operationStack.pop();
    for (std::string::const_iterator it = expression.begin(); it != expression.end(); it++)
    {
        char c = *it;

        if(std::isdigit(c))
        {
            this->_operationStack.push(c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (this->_operationStack.size() < 2)
            {
                std::cerr << "\033[31;1mError - less than two operands.\033[0m" << std::endl;
                while (!this->_operationStack.empty())
                    this->_operationStack.pop();
                return ;   
            }
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
                    if (second == 0)
                    {
                        std::cerr << "\033[31;1mError - Attempting to divide by 0.\033[0m" << std::endl;
                        return ;
                    }
                    else
                    {
                        this->_operationStack.push(first / second);
                        break;
                    }
                default:
                    std::cerr << "\033[31;1mUnrecognized operator.\033[0m" << std::endl;
                    return ;
            }
        }
        else
        {
            std::cerr << "\033[31;1mInvalid character.\033[0m" << std::endl;
            return ;
        }
    }
    std::cout << this->_operationStack.top() << std::endl;
}
