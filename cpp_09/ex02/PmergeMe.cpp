/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:30:26 by caalbert          #+#    #+#             */
/*   Updated: 2024/03/07 08:59:28 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "PmergeMe.tpp"

PmergeMe::PmergeMe(void)
{
	return;
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe::~PmergeMe(void)
{
	return;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

const std::vector<unsigned int>& PmergeMe::getVector() const
{
	return _inputVector;
}

const std::deque<unsigned int>& PmergeMe::getDeque() const
{
	return _inputDeque;
}

const std::vector<unsigned int>& PmergeMe::getOrderedVector() const
{
	return _orderedVector;
}

const std::deque<unsigned int>& PmergeMe::getOrderedDeque() const
{
	return _orderedDeque;
}


bool PmergeMe::LoadNumberContainer(int argc, char** argv)
{
	for (int i = 1; i < argc; ++i)
	{
		int number = std::atoi(argv[i]);

		if (number < 0)
		{
			return false;
		}
		this->_inputVector.push_back(number);
		this->_inputDeque.push_back(number);
	}
	return true;
}

bool PmergeMe::hasDuplicateNumb(void)
{
	_checkDuplicate = this->_inputVector;
	std::sort(_checkDuplicate.begin(), _checkDuplicate.end(), &PmergeMe::compare);
	return (std::unique(_checkDuplicate.begin(), _checkDuplicate.end()) != _checkDuplicate.end());
}

bool PmergeMe::compare(unsigned int a, unsigned int b)
{
	return a < b;
}

size_t PmergeMe::containerSize(void)
{
	return this->_inputVector.size();
}

//Ford–Johnson VECTOR algorithm
void PmergeMe::sortVectorContainer()
{
	int straggler = -1;
	_orderedVector = this->_inputVector;
	std::vector<std::pair<unsigned int, unsigned int> > pairs;
	std::vector<unsigned int> mainSequence, pendingSeq, jacobSeq, indexSeq;

	if (_orderedVector.size() < 2 or isSortedAscending(_orderedVector))
	{
		return;
	}
	if (hasStraggler(_orderedVector))
	{
		straggler = _orderedVector.back();
		_orderedVector.pop_back();
	}
	pairs = createVectorPairs(_orderedVector);
	sortPairs(pairs);
	insertionSortByLargestValue(pairs, pairs.size());
	mainSequence = createVectormainSequence(pairs);
	pendingSeq = createVectorPendingSeq(pairs);
	jacobSeq = createJacobsthalSequence(pendingSeq);
	indexSeq = createIndexSequence(jacobSeq, pendingSeq);
	fillMainSequence(mainSequence, indexSeq, pendingSeq);
	if (straggler >= 0)
		insertStragglerElement(mainSequence, straggler);
	_orderedVector.assign(mainSequence.begin(), mainSequence.end());
}

std::vector<std::pair<uint, uint> >
PmergeMe::createVectorPairs(std::vector<uint> &_orderedVector)
{
	std::vector<uint>::iterator it, next;
	std::vector<std::pair<uint, uint> > pairs;

	it = _orderedVector.begin();
	while (it != _orderedVector.end())
	{
		next = it + 1;
		pairs.push_back(std::make_pair(*it, *next));
		it += 2;
	}
	return (pairs);
}

std::vector<uint> PmergeMe::createVectormainSequence(std::vector<std::pair<uint, uint> > &pairs)
{
std::vector<uint> mainSequence;
std::vector<std::pair<uint, uint> >::iterator it = pairs.begin();

for (it = pairs.begin(); it != pairs.end(); it++)
{
	mainSequence.push_back(it->second);
}
return (mainSequence);
}

std::vector<uint> PmergeMe::createVectorPendingSeq(std::vector<std::pair<uint, uint> > &pairs)
{
std::vector<uint> mainSequence;
std::vector<std::pair<uint, uint> >::iterator it;

for (it = pairs.begin(); it != pairs.end(); it++)
{
	mainSequence.push_back(it->first);
}
return (mainSequence);
}


//Ford–Johnson DEQUE algorithm
void PmergeMe::sortDequeContainer()
{
	int straggler = -1;
	_orderedDeque = this->_inputDeque;
	std::deque<std::pair<unsigned int, unsigned int> > pairs;
	std::deque<unsigned int> mainSequence, pendingSeq, jacobSeq, indexSeq;

	if (_orderedDeque.size() < 2 or isSortedAscending(_orderedDeque))
	{
		return;
	}
	if (hasStraggler(_orderedDeque))
	{
		straggler = _orderedDeque.back();
		_orderedDeque.pop_back();
	}
	pairs = createDequePairs(_orderedDeque);
	sortPairs(pairs);
	insertionSortByLargestValue(pairs, pairs.size());
	mainSequence = createDequemainSequence(pairs);
	pendingSeq = createDequePendingSeq(pairs);
	jacobSeq = createJacobsthalSequence(pendingSeq);
	indexSeq = createIndexSequence(jacobSeq, pendingSeq);
	fillMainSequence(mainSequence, indexSeq, pendingSeq);
	if (straggler >= 0)
		insertStragglerElement(mainSequence, straggler);
	_orderedDeque.assign(mainSequence.begin(), mainSequence.end());
}

// createDequePairs cria pares de números que estão na sequência principal
std::deque<std::pair<uint, uint> > PmergeMe::createDequePairs(std::deque<uint> &arr)
{
	std::deque<uint>::iterator it, next;
	std::deque<std::pair<uint, uint> > pairs;

	it = arr.begin();
	while (it != arr.end())
	{
		next = it + 1;
		pairs.push_back(std::make_pair(*it, *next));
		it += 2;
	}
	return (pairs);
}

// createDequemainSequence cria uma sequência de números que estão na sequência principal
std::deque<uint> PmergeMe::createDequemainSequence(std::deque<std::pair<uint, uint> > &pairs)
{
	std::deque<uint> mainSequence;
	std::deque<std::pair<uint, uint> >::iterator it = pairs.begin();

	for (it = pairs.begin(); it != pairs.end(); it++)
	{
		mainSequence.push_back(it->second);
	}
	return (mainSequence);
}

// createDequePendingSeq cria uma sequência de números que não estão na sequência principal
std::deque<uint> PmergeMe::createDequePendingSeq(std::deque<std::pair<uint, uint> > &pairs)
{

	std::deque<uint> mainSequence;
	std::deque<std::pair<uint, uint> >::iterator it;

	for (it = pairs.begin(); it != pairs.end(); it++)
	{
		mainSequence.push_back(it->first);
	}
	return (mainSequence);
}


//Ford–Johnson Jacobsthal number: Permite criar uma sequência de números de Jacobsthal
// que são menores que o tamanho da sequência principal e que são usados para criar
// uma sequência de índices que são usados para criar a sequência principal. neste caso
// a sequência principal é a sequência de números ordenados. e é usado na função fillMainSequence
// para criar a sequência principal.
int PmergeMe::jacobsthal(int n)
{
if (n == 0)
	return (0);
if (n == 1)
	return (1);
return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}
