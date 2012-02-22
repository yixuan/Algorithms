//==========================================================================
// Name        : 2-13a.cpp
// Author      : Yixuan Qiu
// Version     : 2012-02-22
// Source      : Data Structure and Algorithm Analysis in C
//               Mark Allen weiss and Yue Chen
//               Exercise 2.13 (a)
// Description : Write a program to determine if a positive integer, N,
//               is prime.
// Build       : g++ -Wall 2-13a.cpp -o 2-13a.out
//==========================================================================


#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <cstdlib>
using std::rand;
using std::srand;

#include <cmath>


// Determine whether a positive integer is prime
void IsPrime(unsigned int number);




void IsPrime(unsigned int number)
{
	unsigned int divisor = 2, max_divisor;

	// 0 and 1 are not prime
	if(number < 2)
	{
		cout << number << " is not prime" << endl;
		return;
	}

	max_divisor = static_cast<unsigned int>(floor(sqrt(number))) + 1;
	while(divisor <= max_divisor && number % divisor != 0)
	{
		divisor++;
	}
	if(divisor >= max_divisor)
		cout << number << " is prime" << endl;
	else
		cout << number << " is not prime" << endl;

}


int main()
{
    int N = 100, i;
	for(i = 0; i < N; i++)
	{
		IsPrime(i);
	}
    
    return 0;
}
