/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:56:38 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/28 19:19:55 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>


template <typename T>
void iter(T *array, size_t length, void (*f)(T const &)) {
	for (size_t i = 0; i < length; i++) {
		f(array[i]);
	}
}

template <typename T>
void	print(T const & x) {
	std::cout << x << std::endl;
}
template <typename T>
void	even(T & x) {
	if (x % 2 == 0) {
		std::cout << "even" << std::endl;
	} else {
		std::cout << "odd" << std::endl;
	}
}

#endif
