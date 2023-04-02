/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:30:38 by lcouto            #+#    #+#             */
/*   Updated: 2023/04/02 11:30:38 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include <sys/time.h>
# include <vector>
# include <deque>
# include <set>
# include <algorithm>

class PmergeMe
{
    private:
		int					_size;
		bool				_sorted;
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		double				_deltaTimeVector;
		double				_deltaTimeDeque;

		std::vector<int>	parseInputToVector(int size, char **input);
		std::deque<int>		parseInputToDeque(int size, char **input);
		void				checkForDuplicates(void);

        double				getTime(void);
		double				deltaTime(long long time);
        void				printDifference(void);
		void				printTime(std::string containerType) const;

		template <typename T>
		void				sort(T& container);

	public:
		PmergeMe(void);
		PmergeMe(int size, char **input);
        ~PmergeMe(void);
		PmergeMe(const PmergeMe& other);
        PmergeMe&	operator=(const PmergeMe& other);

		double	getDeltaTimeForVector(void) const;
		double	getDeltaTimeForDeque(void) const;

};

std::ostream&	operator<<(std::ostream& o, const PmergeMe& i);

#endif