/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:16:58 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/24 13:55:34 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <algorithm>

template<typename T>
class MutantStack: public std::stack<T>
{
    public:
        MutantStack(void) {};
        MutantStack(MutantStack const *instance) : std::stack<T>(instance) {};
		~MutantStack(void) {};
        MutantStack &operator=(const MutantStack &rightHandSide)
        {
            std::stack<T>::operator=(rightHandSide);
            return (*this);
        };

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        iterator begin() {return (std::stack<T>::c.begin());};
        const_iterator begin() const {return (std::stack<T>::c.begin());};

        iterator end() {return (std::stack<T>::c.end());};
        const_iterator end() const {return (std::stack<T>::c.end());};

        reverse_iterator rbegin() {return (std::stack<T>::c.rbegin());};
        const_reverse_iterator rbegin() const {return (std::stack<T>::c.rbegin());};

        reverse_iterator rend() {return (std::stack<T>::c.rend());};
        const_reverse_iterator rend() const {return (std::stack<T>::c.rend());};
};

#endif
