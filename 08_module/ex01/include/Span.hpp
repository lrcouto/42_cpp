/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:01:45 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/23 23:31:46 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iterator>
# include <algorithm>

class Span
{
    private:
        unsigned int        m_n;
        std::vector<int>    m_content;

    public:
        Span(void);
        Span(unsigned int n);
        ~Span(void);
        Span(Span const &instance);
        Span &operator=(Span const &rightHandSide);

        void            addNumber(int number);

        template < class It >
        void            addNumber(It begin, It end)
        {
            if ((end - begin) <= m_n)
            {
                std::copy(begin, end, std::back_inserter(this->m_content));
                std::sort(this->m_content.begin(), this->m_content.end());
                return ;
            }
            throw Span::NotEnoughSpaceException();
        }

        unsigned int    shortestSpan(void);
        unsigned int    longestSpan(void);
    
    class SpanIsFullException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("\e[0;31mException: cannot append element because this collection is full\e[0m");
			}
	};

    class NotEnoughSpaceException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("\e[0;31mException: the range of elements is too large to be inserted in this collection\e[0m");
			}
	};

    class NotEnoughElementsException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("\e[0;31mException: not enough elements in the collection to do this operation\e[0m");
			}
	};
};

#endif
