#pragma once
#ifndef INCLUDE_CONVERTOR_H_
#define INCLUDE_CONVERTOR_H_
#include <iostream>
#include <string>
#include <map>
#include<math.h>
#include <typeinfo>
using namespace std;
struct roman {
	string value;
};

struct arabic {
	int value;
};

class Convertor {
public:
	arabic ar;
	roman ro;

	int Razryad(arabic t);
	arabic toArabic(roman t);
	roman toRoman(arabic t);

	bool check(roman& t);      // IIII - IV
	void print(string t);
	void print(int t);
	// оператор ввода-вывода, либо print

};


#endif  // INCLUDE_CONVERTOR_H_