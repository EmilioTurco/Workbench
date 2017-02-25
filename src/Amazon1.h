/*
 * Amazon1.h
 *
 *  Created on: 20 feb 2017
 *      Author: Emilio
 */

#ifndef AMAZON1_H_
#define AMAZON1_H_

#include <vector>
#include "utils.h"

/*
 * Amazon Interview Question for Software Developers
 * Consider the following series:
 *  A := 1
 *  B := A*2 + 2
 *  C := B*2 + 3 and so on...
 *
 *  Write a program that:
 *  - outputs the number corresponding to a given letter;
 *
 *	- given a string of letters like 'GREP', computes the sum of the numbers corresponding to
 *	  all the letters in the string (i.e., G + R + E + P), as given by the above series; and
 *
 *	- given a large number (that would fit into a standard 32-bit integer), finds the shortest string of letters corresponding to it.
 *	  You may use a greedy approach for the last part. Compute the values of the numbers corresponding
 *	  to letters as and when required and DO NOT pre-compute beforehand and store them in a data structure.
 *
*/

class Amazon1 {
  public:

	static int computeString( const char * target )
	{
		std::vector<int> results; 		results.resize(27);

		computeAndStore( 'Z', results);

		print( results.begin(), results.end());

		//for(  )

		return 1;

	}

	static int computeAndStore( char iTemp, std::vector<int> & results)
	{
		int oIter = charToOffset(iTemp) + 1;

		if( oIter == 1 ){
			results.at(oIter) = 1;
		}else{
			results.at(oIter) = 2 * computeAndStore( iTemp-1, results) + oIter;
		}

		return results.at(oIter);
	}

	static int computeNumber( char target )
	{
		return compute( target );
	}

	static int compute( char temp )
	{
		int iter = charToOffset(temp) + 1;

		if( iter <= 1 ) return 1;

		return 2 * compute( temp-1 ) + iter;
	}

	static int charToOffset( char c ){
		return c - 'A';
	}
};

#endif /* AMAZON1_H_ */
