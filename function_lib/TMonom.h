#pragma once
#include "List.h"
#include <initializer_list>

struct TData
{
	double K;
	int dim;
	double* data;

	TData(int t = 0);
	TData(const TData& other);
	~TData();

	TData& operator = (const TData& other);

	bool operator==(const TData& other);
	bool operator>(const TData& other);
	bool operator<(const TData& other);

	TData* operator+(const TData& other);
	TData* operator-(const TData& other);
	TData operator*(const TData& other);
	TData operator/(const TData& other);

	friend std::ostream& operator << (std::ostream& ostr, const TData& m);
};

class TMonom : public Node<TData>
{
protected:

public:
	TMonom();
	TMonom(double k, int size, double* x);
	TMonom(const TMonom& other);
	~TMonom();

	double GetK();
	void SetK(double k);
	int GetDim();
	void SetDim(int dim);

	double& operator [] (int i);
	TData& operator * ();

	TMonom& operator = (const TMonom& other);

	TMonom operator * (const TMonom& other);
	TMonom operator / (const TMonom& other);

	bool operator > (const TMonom& other);
	bool operator < (const TMonom& other);
	bool operator == (const TMonom& other);

	friend ostream& operator << (ostream& ostr, const TMonom& m);
	friend istream& operator >> (istream& ostr, TMonom& m);
};
