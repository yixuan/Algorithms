//==========================================================================
// Name        : 1-3.cpp
// Author      : Yixuan Qiu
// Version     : 2012-02-22
// Source      : Data Structure and Algorithm Analysis in C
//               Mark Allen weiss and Yue Chen
//               Exercise 1.3
// Description : Assume that the only I/O routine available will take a
//               single-digit number and output it to the terminal,
//               calling this routine PrintDigit(digit). Write a procedure
//               PrintOut() to print an arbitrary integer or real number.
// Build       : g++ -Wall 1-3.cpp -o 1-3.out
//==========================================================================


#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <cstdlib>
using std::rand;
using std::srand;

#include <cassert>
#include <cmath>


// The only available I/O routine in hypothesis
void PrintDigit(int digit);
// Print out a decimal between 0 and 1
void PrintDecimal(double decimal, int digits);
// Print out integers
void PrintOut(int number);
// Print out real numbers
void PrintOut(double number, int digits = 10);



void PrintDigit(int digit)
{
	assert(digit >= 0 && digit < 10);
	cout << digit;
}

void PrintDecimal(double decimal, int digits)
{
	int i = 1;
	assert(decimal >= 0 && decimal < 1);
	while(i <= digits)
	{
		decimal *= 10;
		PrintDigit(static_cast<int>(floor(decimal)));
		decimal -= floor(decimal);
		i++;
	}
}

void PrintOut(int number)
{
	int head, tail;

	if(number < 0)
	{
		cout << "-";
		number = -number;
	}
	head = number / 10;
	// tail = number % 10
	tail = number - 10 * head;

	if(number >= 10)
		PrintOut(head);
	PrintDigit(tail);
}

void PrintOut(double number, int digits)
{
	int int_part;
	double decimal_part;
	if(number < 0)
	{
		cout << "-";
		number = -number;
	}
	int_part = static_cast<int>(floor(number));
	decimal_part = number - int_part;
	PrintOut(int_part);
	cout << ".";
	PrintDecimal(decimal_part, digits);
}

int main()
{
    PrintDigit(1);
	cout << endl;

	PrintDigit(9);
	cout << endl;

	PrintDecimal(M_PI - 3, 10);
	cout << endl;

	PrintOut(284501);
	cout << endl;

	PrintOut(-284501);
	cout << endl;

	PrintOut(M_PI, 10);
	cout << endl;

	PrintOut(-M_PI);
	cout << endl;

	PrintOut(0);
	cout << endl;

	PrintOut(0.0);
	cout << endl;
    
    return 0;
}
