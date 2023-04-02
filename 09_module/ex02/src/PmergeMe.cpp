/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:30:34 by lcouto            #+#    #+#             */
/*   Updated: 2023/04/02 11:30:34 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _size(0), _sorted(false)
{
	return ;
}

PmergeMe::PmergeMe(int size, char **input) : _size(size - 1), _sorted(false)
{
	_vector = parseInputToVector(size, input);
	checkForDuplicates();
	_deque = parseInputToDeque(size, input);

	printDifference();

	double startingTime = getTime();
	sort(_vector);
	_deltaTimeVector = deltaTime(startingTime);

	startingTime = getTime();
	sort(_deque);
	_deltaTimeDeque = deltaTime(startingTime);

	_sorted = true;
	printDifference();

	printTime("vector");
	printTime("deque");
	return ;
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
	return ;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		this->_size = other._size;
		this->_sorted = other._sorted;
		this->_vector = other._vector;
		this->_deque = other._deque;
		this->_deltaTimeVector = other._deltaTimeVector;
		this->_deltaTimeDeque = other._deltaTimeDeque;
	}
	return (*this);
}

std::vector<int> PmergeMe::parseInputToVector(int size, char **input)
{
	std::vector<int>	args;
	for (int i = 1; i < size; ++i)
	{
		std::string arg = input[i];
		int value = atoi(arg.c_str());
		if (value < 0)
        {
			std::cerr << "\033[31;1mError - input must be only positive integers.\033[0m" << std::endl;
            exit(1);
        }
		args.push_back(value);
	}
	return (args);
}

std::deque<int> PmergeMe::parseInputToDeque(int size, char **input)
{
	std::deque<int>	args;
	for (int i = 1; i < size; ++i)
	{
		std::string arg = input[i];
		int value = atoi(arg.c_str());
		if (value < 0) 
        {
			std::cerr << "\033[31;1mError - input must be only positive integers.\033[0m" << std::endl;
            exit(1);
        }
		args.push_back(value);
	}
	return (args);
}

void PmergeMe::checkForDuplicates(void)
{
	std::set<int> checkerSet;
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it) {
		int num = *it;
		if (checkerSet.find(num) != checkerSet.end())
		    {
			std::cerr << "\033[31;1mError - Input must not contain duplicate integers.\033[0m" << std::endl;
            exit(1);
        }
		checkerSet.insert(num);
	}
}

template <typename T>
void PmergeMe::sort(T& container)
{
    const int threshold = 16;
    const int size = container.size();
    if (size < 2)
        return;
    if (size < threshold)
    {
        for (typename T::iterator i = container.begin() + 1; i != container.end(); ++i)
        {
            typename T::iterator j = i;
            while (j != container.begin() && *(j - 1) > *j)
            {
                std::swap(*j, *(j - 1));
                --j;
            }
        }
        return;
    }
    typename T::iterator middle = container.begin() + size / 2;
    std::rotate(middle, container.end(), container.end());
    T left(container.begin(), middle);
    T right(middle, container.end());
    sort(left);
    sort(right);
    typename T::iterator i = left.begin();
    typename T::iterator j = right.begin();
    typename T::iterator k = container.begin();
    while (i != left.end() && j != right.end())
    {
        if (*i < *j)
        {
            *k = *i;
            ++i;
        }
        else
        {
            *k = *j;
            ++j;
        }
        ++k;
    }
    std::copy(i, left.end(), k);
    std::copy(j, right.end(), k);
}

double	PmergeMe::getTime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

double	PmergeMe::deltaTime(long long time)
{
	if (time > 0)
		return (getTime() - time);
	return (0);
}

void	PmergeMe::printDifference(void)
{
	if (_sorted == false)
		std::cout << "\033[33;1mOriginal Input: \033[0m";
	else
		std::cout << "\033[33;1mSorted Input: \033[0m";
	std::vector<int>::iterator it = _vector.begin();
	std::vector<int>::iterator ite = _vector.end();
	while (it != ite)
	{
		std::cout << " " << *it;
		++it;
	}
	std::cout << std::endl;
}

void	PmergeMe::printTime(std::string containerType) const
{
	double delta;
	std::string color;
	if (containerType == "vector")
	{
		delta = _deltaTimeVector;
		color = "\033[35;1m";
	}
	else if (containerType == "deque")
	{
		delta = _deltaTimeDeque;
		color = "\033[36;1m";
	}
    else
    {
        std::cerr << "\033[31;1mError - Invalid container type.\033[0m" << std::endl;
        exit(1);
    }
	std::cout 
		<< color << "Time elapsed to sort " << _size 
		<< " integers with std::" << containerType << ": "
		<< std::fixed << std::setprecision(5) << delta << " ms\033[0m" << std::endl;
}

double	PmergeMe::getDeltaTimeForVector(void) const
{
	return (this->_deltaTimeVector);
}
double	PmergeMe::getDeltaTimeForDeque(void) const
{
	return (this->_deltaTimeDeque);
}

std::ostream&	operator<<(std::ostream& o, const PmergeMe& i)
{
	o 
		<< "DeltaTime for Vector: " << i.getDeltaTimeForVector() << std::endl
		<< "DeltaTime for Deque: " << i.getDeltaTimeForDeque();
	return o;
}