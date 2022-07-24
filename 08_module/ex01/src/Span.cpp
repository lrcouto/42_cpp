/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:34:33 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/24 00:18:41 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"
# include <limits.h>
# include <iostream>

Span::Span(void) : m_n(0) {};

Span::Span(unsigned int n) : m_n(n) {};

Span::~Span(void) {};

Span::Span(Span const &instance) : m_n(instance.m_n), m_content(instance.m_content) {};

Span &Span::operator=(Span const &rightHandSide)
{
    this->m_n = rightHandSide.m_n;
    this->m_content = rightHandSide.m_content;
    return (*this);
}

void    Span::addNumber(int number)
{
    if (this->m_content.size() < (unsigned long)this->m_n)
    {
        this->m_content.push_back(number);
        std::sort(this->m_content.begin(), this->m_content.end());
        return ;
    }
    throw Span::SpanIsFullException();
}

unsigned int    Span::shortestSpan(void)
{
	if (this->m_content.size() <= 1)
		throw Span::NotEnoughElementsException();
    
    unsigned int smallestDiff = INT_MAX;

    for (unsigned long int i = 0; i < this->m_content.size(); i++)
    {
        for (unsigned long int j = i + 1; j < this->m_content.size(); j++)
        {
            if((unsigned int)std::abs(this->m_content[i] - this->m_content[j]) < smallestDiff)
                smallestDiff = (std::abs(this->m_content[i] - this->m_content[j]));
        }
    }
    return (smallestDiff);
}

unsigned int    Span::longestSpan(void)
{
	if (this->m_content.size() <= 1)
		throw Span::NotEnoughElementsException();

	int largestNumber = *std::max_element(this->m_content.begin(), this->m_content.end());
	int smallestNumber = *std::min_element(this->m_content.begin(), this->m_content.end());
	return (std::abs(largestNumber - smallestNumber));
}
