/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:28:47 by caalbert          #+#    #+#             */
/*   Updated: 2024/02/09 16:03:08 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include "Fixed.hpp"
#include <iostream>

int main(void) {
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);
	std::cout << "---------- Conversion and Printing ----------" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "\n---------- Conversion to Integer ----------" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << "\n---------- Comparison Operators ----------" << std::endl;
	std::cout << "b: " << b << " | c: " << c << std::endl;
	std::cout << "b < c: " << (b < c) << std::endl;
	std::cout << "b > c: " << (b > c) << std::endl;
	std::cout << "b == c: " << (b == c) << std::endl;
	std::cout << "b != c: " << (b != c) << std::endl;

	std::cout << "\n---------- Arithmetic Operators ----------" << std::endl;
	std::cout << "b: " << b << " | c: " << c << std::endl;
	std::cout << "b + c: " << (b + c) << std::endl;
	std::cout << "b - c: " << (b - c) << std::endl;
	Fixed n3((float)-5.1);
	Fixed n4((float)-10.1);
	std::cout << "n3 = " << n3 << " | n4 = " << n4 << std::endl;
	std::cout << "n3 + n4: " << n3 + n4 << std::endl;
	std::cout << "n3 * n4: " << n3 * n4 << std::endl;
	std::cout << "n3 / n4: " << n3 / n4 << std::endl;

	std::cout << "\n---------- Increment and Decrement ----------" << std::endl;
	Fixed n5 = a;
	Fixed n6 = b;

	std::cout << "Original n5: " << n5 << std::endl;
	std::cout << "Original n6 (const): " << n6 << std::endl;

	std::cout << "++n5: " << ++n5 << std::endl;
	std::cout << "n5++: " << n5++ << std::endl;
	std::cout << "n5 after n5++: " << n5 << std::endl;
	
	std::cout << "--n5: " << --n5 << std::endl;
	std::cout << "n5--: " << n5-- << std::endl;
	std::cout << "n5 after n5--: " << n5 << std::endl;

	std::cout << "\n---------- Min and Max Functions ----------" << std::endl;
	Fixed n9(3.0f), n10(3.14f);
	std::cout << "n9: " << n9 << " | n10: " << n10 << std::endl;
	std::cout << "max(n10, n9): " << Fixed::max(n10, n9) << std::endl;
	std::cout << "min(n10, n9): " << Fixed::min(n10, n9) << std::endl << std::endl;

	std::cout << "const b: " << b << " | const c: " << c << std::endl;
	std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;
	std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;

	return 0;
}