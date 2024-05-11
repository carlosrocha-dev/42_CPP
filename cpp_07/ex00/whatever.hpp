/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:56:43 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/28 10:57:53 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>


template <typename T>
T const & max(T const & a, T const & b) {
	return (a > b ? a : b);
}

template <typename T>
T const & min(T const & a, T const & b) {
	return (a < b ? a : b);
}

template <typename T>
void swap(T & a, T & b) {
	T tmp = a;
	a = b;
	b = tmp;
}

#endif