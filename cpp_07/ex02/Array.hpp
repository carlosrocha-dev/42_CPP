/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:56:08 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/28 17:26:15 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <cstddef>
#include <stdexcept>
#include <iostream>

template <typename T>
class Array {
private:
	unsigned int _size;
	T* _array;
public:
	Array();
	explicit Array(unsigned int n);
	Array(const Array& src);
	~Array();

	Array& operator=(const Array& rhs);
	T& operator[](unsigned int i);
	const T& operator[](unsigned int i) const;

	unsigned int size() const;
};

#include "Array.tpp"

#endif
