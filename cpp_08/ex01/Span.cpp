/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:11:44 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/29 08:06:56 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/**
 * @brief Construct a new Span:: Span object

*/
Span::Span() : _N(0), _size(0), _array(NULL) {}

/**
 * @brief Construct a new Span:: Span object
 *
 * @param N
 */
Span::Span(unsigned int N) : _N(N), _size(0)
{
	_array = new std::vector<int>();
}

/**
 * @brief Destroy the Span:: Span object
 *
 */
Span::~Span()
{
	delete _array;
}

/**
 * @brief Construct a new Span:: Span object
 *
 * @param copy
 */
Span::Span(const Span &copy)
{
	*this = copy;
}

/**
 * @brief Overload of the = operator
 *
 * @param copy
 * @return Span&
 */
Span &Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		delete _array;
		_N = copy._N;
		_size = copy._size;
		_array = new std::vector<int>(*copy.getArray());
	}
	return *this;
}

/**
 * @brief Add a number to the array
 *
 * @param begin
 * @param end
 */
int Span::size() const
{
	return (int)_size;
}

/**
 * @brief Add a number to the array
 *
 * @param begin
 * @param end
 */
std::vector<int> *Span::getArray() const
{
	return _array;
}

/**
 * @brief Add a number to the array
 *
 * @param begin
 * @param end
 */
void Span::addNumber(int n)
{
	if (_size == _N)
	{
		throw std::runtime_error("Span is full");
	}
	_array->push_back(n);
	_size++;
}

/**
 * @brief Add a number to the array
 *
 * @param begin
 * @param end
 */
int Span::shortestSpan()
{
	if (_size < 2)
	{
		throw std::runtime_error("Span is too small");
	}
	int shortest = 2147483647;
	std::vector<int> sorted(*this->_array);
	std::sort(sorted.begin(), sorted.end());
	for (unsigned int i = 1; i < sorted.size(); ++i)
	{
		int span = std::abs(sorted[i] - sorted[i - 1]);
		if (span < shortest)
		{
			shortest = span;
		}
	}
	return shortest;
}

/**
 * @brief Add a number to the array
 *
 * @param begin
 * @param end
 */
int Span::longestSpan()
{
	if (_array->size() < 2)
	{
		throw std::runtime_error("Span is too small to find longest span");
	}
	int min_num = *std::min_element(_array->begin(), _array->end());
	int max_num = *std::max_element(_array->begin(), _array->end());
	return max_num - min_num;
}
