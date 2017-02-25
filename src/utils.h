/*
 * utils.h
 *
 *  Created on: 11 feb 2017
 *      Author: Emilio
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>


template <class InputIt >
void print( InputIt first, InputIt last, char sep = ' ' )
{
	InputIt it = first;
	if( it < last ) std::cout << *it++;

	while( it < last ) {
		std::cout << sep << *it;
		++it;
	}
	std::cout << '\n';
}


template<class C>
void fillContainer( C & c, const unsigned nOfInput )
{
	int n = nOfInput;
	typename C::value_type input;
	while( n-- && std::cin >> input ){
		c.emplace_back(input);
	}
}

bool palindrome( const std::string & input )
{
	if( input.empty() ) return false;

	auto i1 = input.begin();
	auto i2 = --input.end();
	while( i1 <= i2){
		if( *i1 != *i2 ){
			return false;
		}
		++i1; --i2;
	}
	return true;
}



#endif /* UTILS_H_ */
