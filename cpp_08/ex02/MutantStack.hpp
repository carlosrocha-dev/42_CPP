/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:11:26 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/29 08:06:25 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{

public:
	MutantStack() : std::stack<T>(){};
	MutantStack(const MutantStack &copy) : std::stack<T>(copy){};
	MutantStack &operator=(const MutantStack &copy)
	{
		if (this != &copy)
		{
			std::stack<T>::operator=(copy);
		}
		return *this;
	};
	~MutantStack(){};

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin()
	{
		return std::stack<T>::c.begin();
	};
	iterator end()
	{
		return std::stack<T>::c.end();
	};
};

#endif