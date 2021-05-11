#pragma once
#include "TMonom.h"

class TPolinom : public List<TData>
{
public:
	TPolinom();
	TPolinom(const TPolinom& other);
	~TPolinom();

	TPolinom& operator += (const TMonom& other);
	TPolinom operator * (const TPolinom& other);
	TPolinom operator + (const TPolinom& other);
	TPolinom operator - (const TPolinom& other);

	friend ostream& operator << (ostream& ostr, const TPolinom& p);
};
