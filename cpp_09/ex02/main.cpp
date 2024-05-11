/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:30:26 by caalbert          #+#    #+#             */
/*   Updated: 2024/03/07 15:32:28 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "PmergeMe.tpp"

// colors
const std::string RESET = "\033[0m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

/**
 * @brief  Print a vector
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[])
{
	std::cout << std::endl;

	PmergeMe input;
	clock_t start;
	clock_t end;

	if (argc < 2)
	{
		std::cerr << "Error: Missing arguments\n"
				  << std::endl;
		return (1);
	}
	// Load the number
	if (!input.LoadNumberContainer(argc, argv))
	{
		std::cerr << "Error: Negative number not allowed\n"
				  << std::endl;
		return (1);
	}
	// Check for duplicated numbers
	if (input.hasDuplicateNumb())
	{
		std::cerr << "Error: Duplicated numbers not allowed\n"
				  << std::endl;
		return (1);
	}

	std::cout << YELLOW << "::: VECTOR :::" << RESET << std::endl;
	std::cout << "Before: ";
	// Show the unsorted vector
	showUnsorted(input.getVector());

	start = clock();
	input.sortVectorContainer();
	end = clock();

	std::cout << "After: ";
	showSorted(input.getOrderedVector());
	std::cout << std::endl;
	std::cout << GREEN << "Time to process a range of " << input.containerSize()
			<< " elements with std::vector : " << static_cast<double>(end - start) / CLOCKS_PER_SEC
			<< " seconds\n" << RESET << std::endl;

	std::cout << YELLOW << "::: DEQUE :::" << RESET << std::endl;
	std::cout << "Before: ";
	showUnsorted(input.getDeque());

	start = clock();
	input.sortDequeContainer();
	end = clock();

	std::cout << "After: ";
	showSorted(input.getOrderedDeque());
	std::cout << std::endl;

	// Show the time to process the vector
	std::cout << GREEN << "Time to process a range of " << input.containerSize()
			  << " elements with std::deque : " << static_cast<double>(end - start) / CLOCKS_PER_SEC
			  << " seconds" << RESET << std::endl;

	std::cout << std::endl;

	return 0;
}
