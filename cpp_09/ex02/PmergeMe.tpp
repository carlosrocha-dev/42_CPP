/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:30:26 by caalbert          #+#    #+#             */
/*   Updated: 2024/03/28 12:24:48 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"

template <class Sequence>
static bool isSortedAscending(const Sequence &container)
{
  typename Sequence::const_iterator current, next;

  for (current = container.begin(); current != container.end(); ++current)
  {
    next = current;
    ++next;
    if (next == container.end())
    {
      break;
    }
    if (*next < *current)
    {
      return false;
    }
  }
  return true;
}


template<typename Container>
void showUnsorted(const Container& inputContainer, size_t maxElements = 15)
{
  size_t i = 0;

  for (typename Container::const_iterator it = inputContainer.begin(); it != inputContainer.end(); ++it)
  {
  std::cout << *it << " ";
  i++;
  if (i >= maxElements)
  {
    std::cout << "[...]";
    break;
  }
  }
  std::cout << std::endl;
}

template<typename Container>
void showSorted(const Container& orderedContainer, size_t maxElements = 15)
{
  size_t i = 0;

  for (typename Container::const_iterator it = orderedContainer.begin(); it != orderedContainer.end(); ++it)
  {
    std::cout << *it << " ";
    i++;
    if (i >= maxElements)
    {
      std::cout << "[...]";
      break;
    }
  }
  std::cout << std::endl;
}

template <class Sequence> static bool hasStraggler(Sequence &container)
{
  return (static_cast<bool>(container.size() % 2));
};

template <class PairContainer> static void sortPairs(PairContainer &pairs)
{
  typename PairContainer::iterator it;

  for (it = pairs.begin(); it != pairs.end(); ++it)
  {
  if (it->first > it->second)
  {
    std::swap(it->first, it->second);
  }
  }
};

template <class PairSequence>
static void insertionSortByLargestValue(PairSequence &pairs, int size)
{
  if (size <= 1)
  {
    return;
  }

  insertionSortByLargestValue(pairs, size - 1);

  typename PairSequence::value_type lastPair = pairs[size - 1];
  int currentIndex = size - 2;

  while (currentIndex >= 0 && pairs[currentIndex].second > lastPair.second)
  {
    pairs[currentIndex + 1] = pairs[currentIndex];
    currentIndex--;
  }

  pairs[currentIndex + 1] = lastPair;
}

template <class Sequence>
static Sequence createJacobsthalSequence(Sequence &pendingSequence)
{
  int index;
  size_t size;
  size_t jacobsthalIndex;
  Sequence jacobsthalSequence;

  if (pendingSequence.empty())
  {
  return (jacobsthalSequence);
  }
  index = 3;
  size = pendingSequence.size();
  while ((jacobsthalIndex = PmergeMe::jacobsthal(index)) < size)
  {
  jacobsthalSequence.push_back(jacobsthalIndex);
  index++;
  }
  jacobsthalSequence.push_back(size);
  return (jacobsthalSequence);
};

/**
 * Gera uma sequência de índices baseada nas sequências de Jacobsthal e pendente.
 *
 * Esta função utiliza a sequência de Jacobsthal para determinar os índices que
 * serão utilizados na construção da sequência principal. A partir da sequência pendente
 * e da sequência de Jacobsthal, cria-se uma sequência de índices que mapeia a ordem que
 * os elementos devem ser inseridos para formar a sequência principal corretamente.
 *
 * A sequência de índices reflete a ordem de inserção derivada das propriedades da
 * sequência de Jacobsthal, ajudando a organizar os elementos da sequência pendente
 * de forma que a sequência principal seja formada seguindo critérios estabelecidos pela
 * sequência de Jacobsthal que determina a ordem de inserção através dos índices gerados por
 * que representam a ordem de inserção dos elementos da sequência pendente.
 *
 * @param jacobsthalSequence Sequência de Jacobsthal usada como referência para a geração dos índices.
 * @param pendingSequence Sequência pendente que será reordenada com base nos índices gerados.
 * @return Sequence Retorna uma sequência de índices que direciona a formação da sequência principal.
 */
template <class Sequence>static Sequence createIndexSequence(Sequence &jacobsthalSequence, Sequence &pendingSequence)
{
  Sequence indexSequence(1, 0);
  size_t index = 1;
  size_t lastIndex = 1;
  typename Sequence::iterator it;

  if (pendingSequence.empty())
  {
  return (indexSequence);
  }
  for (it = jacobsthalSequence.begin(); it != jacobsthalSequence.end(); it++)
  {
    index = *it;
    size_t pos = index;
    while (pos > lastIndex) {
      indexSequence.push_back(pos - 1);
      pos--;
    }
    lastIndex = index;
  }
  return (indexSequence);
};

template <class SequenceIterator>
// findPosition encontra a posição de um valor em uma sequência ordenada usando busca binária
// e retorna um iterador para a posição encontrada. Se o valor não for encontrado, retorna um iterador
// para a posição onde o valor deveria ser inserido.
static SequenceIterator findPosition(SequenceIterator begin, SequenceIterator end, uint target)
{
  SequenceIterator lowerBound = begin;
  SequenceIterator upperBound = end;

  while (lowerBound < upperBound) {
    SequenceIterator middle = lowerBound + (upperBound - lowerBound) / 2;

    if (*middle < target)
    {
      lowerBound = middle + 1;
    }
    else
    {
      upperBound = middle;
    }
  }
  return (lowerBound);
}

template <class Sequence>
// fillMainSequence preenche a sequência principal com os valores da sequência pendente
// e da sequência de índices que são usados para criar a sequência principal. Ordenando os
// valores da sequência pendente de acordo com a sequência de índices.
static void fillMainSequence(Sequence &mainSequence, Sequence &indexSequence, Sequence &pendingSequence)
{
  uint targetValue;
  uint addedCount;
  typename Sequence::iterator it;
  typename Sequence::iterator targetPosition;

  addedCount = 0;
  for (it = indexSequence.begin(); it != indexSequence.end(); it++)
  {
    targetValue = pendingSequence.at(*it);
    targetPosition = findPosition(mainSequence.begin(),
                        mainSequence.begin() + *it + 1 + addedCount, targetValue);
    mainSequence.insert(targetPosition, targetValue);
    addedCount++;
  }
};

template <class Sequence>
// insertStragglerElement insere um valor na sequência principal que não foi inserido
// durante o preenchimento da sequência principal. Este valor é chamado de "straggler".
static void insertStragglerElement(Sequence &mainSequence, uint stragglerValue)
{
  typename Sequence::iterator stragglerPos;

  stragglerPos = findPosition(mainSequence.begin(), mainSequence.end(), stragglerValue);
  mainSequence.insert(stragglerPos, stragglerValue);
};

#endif
