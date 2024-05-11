/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:26:34 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/28 17:28:20 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), _array(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[n]()) {}

template <typename T>
Array<T>::Array(const Array<T>& src) : _size(src._size), _array(new T[src._size]) {
    for (unsigned int i = 0; i < _size; i++) {
        _array[i] = src._array[i];
    }
}

template <typename T>
Array<T>::~Array() {
    delete[] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs) {
    if (this != &rhs) {
        delete[] _array;
        _size = rhs._size;
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
            _array[i] = rhs._array[i];
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) {
    if (i >= _size) throw std::out_of_range("Array index out of range!");
    return _array[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const {
    if (i >= _size) throw std::out_of_range("Array index out of range!");
    return _array[i];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

template<typename T>
std::ostream &operator<<(std::ostream &o, Array<T> const &rhs) {
    o << "[ ";
    for (unsigned int i = 0; i < rhs.size(); i++) {
        o << rhs[i];
        if (i + 1 < rhs.size()) std::cout << ", ";
    }
    o << " ]" << std::endl;
    return o;
}
