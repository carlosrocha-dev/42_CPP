/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:30:26 by caalbert          #+#    #+#             */
/*   Updated: 2024/03/28 12:23:57 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <deque>
#include <vector>
#include <list>

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &src);
		~PmergeMe(void);

		PmergeMe &operator=(const PmergeMe &rhs);

		const std::vector<unsigned int>& getVector() const;
		const std::deque<unsigned int>& getDeque() const;
		const std::vector<unsigned int>& getOrderedVector() const;
		const std::deque<unsigned int>& getOrderedDeque() const;

		bool LoadNumberContainer(int argc, char **argv);
        bool hasDuplicateNumb(void);
		static bool compare(unsigned int a, unsigned int b);


		size_t containerSize(void);

		void sortVectorContainer(void);
		void sortDequeContainer(void);

		static int jacobsthal(int n);


	private:
		std::vector<unsigned int> _checkDuplicate;

		std::vector<unsigned int> _inputVector;
		std::vector<unsigned int> _orderedVector;

		std::deque<unsigned int> _inputDeque;
		std::deque<unsigned int> _orderedDeque;

		static std::vector<std::pair<uint, uint> >
  		createVectorPairs(std::vector<uint> &_orderedVector);

		static std::vector<uint>
  		createVectormainSequence(std::vector<std::pair<uint, uint> > &pairs);

		static std::vector<uint>
  		createVectorPendingSeq(std::vector<std::pair<uint, uint> > &pairs);

		static std::deque<std::pair<uint, uint> >
  		createDequePairs(std::deque<uint> &_orderedDeque);

		static std::deque<uint>
  		createDequemainSequence(std::deque<std::pair<uint, uint> > &pairs);

		static std::deque<uint>
  		createDequePendingSeq(std::deque<std::pair<uint, uint> > &pairs);

};

#endif
