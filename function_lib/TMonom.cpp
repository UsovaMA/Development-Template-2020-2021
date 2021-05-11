#include "TMonom.h"
#include <iostream>

TMonom::TMonom()
{
	data.K = 0;
	data.dim = 0;
	data.data = nullptr;
}

TMonom::TMonom(double k, int size, double* x)
{
	data.K = k;
	data.dim = size;

	data.data = new double[data.dim];

	for (int i = 0; i < data.dim; i++)
		data.data[i] = x[i];
}

TMonom::TMonom(const TMonom& other)
{
	data.K = other.data.K;
	data.dim = other.data.dim;

	if (data.dim > 0)
	{
		data.data = new double[data.dim];
		for (int i = 0; i < data.dim; i++)
			data.data[i] = other.data.data[i];
	}
	else
		data.data = nullptr;
}

TMonom::~TMonom()
{
}

double TMonom::GetK()
{
	return data.K;
}

void TMonom::SetK(double k)
{
	data.K = k;
}

int TMonom::GetDim()
{
	return data.dim;
}

void TMonom::SetDim(int dim)
{
	if (data.dim == dim)
		return;
	else if (dim < 0)
		throw - 1;
	else if (dim == 0)
	{
		data.dim = 0;
		delete[] data.data;
		data.data = nullptr;
	}
	else
	{
		double* newData = new double[dim];

		if (dim < data.dim)
			memcpy(newData, data.data, dim * sizeof(double));
		else
			memcpy(newData, data.data, data.dim * sizeof(double));

		delete[] data.data;
		data.data = newData;

		if (dim > data.dim)
			for (int i = data.dim - 1; i < dim; i++)
				data.data[i] = 0;

		data.dim = dim;
	}
}

double& TMonom::operator[](int i)
{
	return data.data[i];
}

TData& TMonom::operator*()
{
	return data;
}

TMonom& TMonom::operator=(const TMonom& other)
{
	if (*this == other)
		return *this;
	data = other.data;
	return *this;
}

TMonom* TMonom::operator+(const TMonom& other)
{
	if (data.dim != other.data.dim)
		throw - 1;
	TMonom* result = nullptr;
	if (*this == other)
	{
		result = new TMonom(*this);
		result->data.K += other.data.K;
	}
	else
	{
		result = new TMonom[2];
		if (*this > other)
		{
			result[0] = *this;
			result[1] = other;
		}
		else
		{

			result[0] = other;
			result[1] = *this;
		}
	}
	return result;
}

TMonom* TMonom::operator-(const TMonom& other)
{
	if (data.dim != other.data.dim)
		throw - 1;
	TMonom* result = nullptr;
	if (*this == other)
	{
		result = new TMonom(*this);
		result->data.K -= other.data.K;
	}
	else
	{
		result = new TMonom[2];
		result[0] = *this;
		result[1] = other;
		result[1].data.K *= -1;
	}
	return result;
}

TMonom TMonom::operator*(const TMonom& other)
{
	TMonom result(*this);
	result.data = data * other.data;
	return result;
}

TMonom TMonom::operator/(const TMonom& other)
{
	TMonom result(*this);
	result.data = data / other.data;
	return result;
}

bool TMonom::operator>(const TMonom& other)
{
	return data > other.data;
}

bool TMonom::operator<(const TMonom& other)
{
	return data < other.data;
}

bool TMonom::operator==(const TMonom& other)
{
	return data == other.data;
}

ostream& operator<<(ostream& ostr, const TMonom& m)
{
	ostr << m.data.K;
	char num = '1';
	for (int i = 0; i < m.data.dim; i++)
		ostr << "x" << num++ << "^" << m.data.data[i];
	return ostr;
}

istream& operator>>(istream& istr, TMonom& m)
{
	int dim = 0;
	if (m.data.dim != 0)
		dim = m.data.dim;
	else
	{
		istr >> dim;
		m.SetDim(dim);
	}

	istr >> m.data.K;
	for (int i = 0; i < dim; i++)
		istr >> m[i];
	return istr;
}

TData::TData(int t)
{
	if (t < 0)
		throw - 1;
	K = 0;
	dim = t;
	if (t == 0)
		data = nullptr;
	else
	{
		data = new double[dim];
		for (int i = 0; i < dim; i++)
			data[i] = 0;
	}
}

TData::TData(const TData& other)
{
	K = other.K;
	dim = other.dim;
	if (dim == 0)
	{
		data = nullptr;
	}
	else
	{
		data = new double[dim];
		for (int i = 0; i < dim; i++)
			data[i] = other.data[i];
	}
}

TData::~TData()
{
	if (data != nullptr)
	{
		delete[] data;
		data = 0;
		dim = 0;
		K = 0;
	}
}

TData& TData::operator=(const TData& other)
{
	if (*this == other)
		return *this;
	K = other.K;

	if (dim == other.dim)
	{
		for (int i = 0; i < dim; i++)
			data[i] = other.data[i];
	}
	else
	{
		if (data != nullptr)
			delete[] data;
		dim = other.dim;
		if (dim > 0)
		{
			data = new double[dim];
			for (int i = 0; i < dim; i++)
				data[i] = other.data[i];
		}
		else if (dim == 0)
			data = nullptr;
	}
	return *this;
}

bool TData::operator==(const TData& other)
{
	if ((dim != other.dim))
		return false;
	bool f = true;
	for (int i = 0; i < dim; i++)
	{
		if (data[i] != other.data[i])
		{
			f = false;
			break;
		}
	}
	return f;
}

bool TData::operator>(const TData& other)
{
	if (this->dim > other.dim)
		return true;
	else if (this->dim < other.dim)
		return false;
	else
		for (int i = 0; i < dim; i++)
		{
			if (data[i] > other.data[i])
			{
				return true;
			}
			else if (data[i] < other.data[i])
			{
				return false;
			}
		}

	return false;
}

bool TData::operator<(const TData& other)
{
	if (this->dim < other.dim)
		return true;
	else if (this->dim > other.dim)
		return false;
	else
		for (int i = 0; i < dim; i++)
		{
			if (data[i] < other.data[i])
			{
				return true;
			}
			else if (data[i] > other.data[i])
			{
				return false;
			}
		}
	return false;
}

TData* TData::operator+(const TData& other)
{
	if (dim != other.dim)
		throw - 1;
	TData* result = nullptr;
	if (*this == other)
	{
		result = new TData(*this);
		result->K += other.K;
	}
	else
	{
		result = new TData[2];
		if (*this > other)
		{
			result[0] = *this;
			result[1] = other;
		}
		else
		{

			result[0] = other;
			result[1] = *this;
		}
	}
	return result;
}

TData* TData::operator-(const TData& other)
{
	if (dim != other.dim)
		throw - 1;
	TData* result = nullptr;
	if (*this == other)
	{
		result = new TData(*this);
		result->K -= other.K;
	}
	else
	{
		result = new TData[2];
		result[0] = *this;
		result[1] = other;
		result[1].K *= -1;
	}
	return result;
}

TData TData::operator*(const TData& other)
{
	TData result(*this);
	if (dim != other.dim)
		throw - 1;
	result.K = K * other.K;
	for (int i = 0; i < dim; i++)
		result.data[i] = this->data[i] + other.data[i];
	return result;
}

TData TData::operator/(const TData& other)
{
	TData result(*this);
	if (dim != other.dim)
		throw - 1;
	result.K = K / other.K;
	for (int i = 0; i < dim; i++)
		result.data[i] = this->data[i] - other.data[i];
	return result;
}

std::ostream& operator<<(std::ostream& ostr, const TData& m)
{
	ostr << m.K;
	char num = '1';
	for (int i = 0; i < m.dim; i++)
		ostr << "x" << num++ << "^" << m.data[i];
	return ostr;
}
