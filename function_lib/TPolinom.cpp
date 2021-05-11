#include "TPolinom.h"

TPolinom::TPolinom() : List<TData>()
{

}

TPolinom::TPolinom(const TPolinom& other) : List<TData>(other)
{
}

TPolinom::~TPolinom()
{
}

TPolinom& TPolinom::operator+=(const TMonom& other)
{
	if (this->GetSize() == 0)
	{
		this->push_back(other.data);
		return *this;
	}

	ListIterator<TData> i = this->begin();
	while (i.doNext())
	{
		if (*i == other.data) {
			(*i).K += other.data.K;
			return *this;
		}
		else
		{
			if (*i < other.data) {
				this->push_front(other.data);
				return *this;
			}
			else {
				this->push_back(other.data);
				return *this;
			}
		}
		i++;
	}
	return *this;
}

TPolinom TPolinom::operator*(const TPolinom& other)
{
	TPolinom result;
	ListIterator<TData> i = this->begin();
	if (this->GetSize() == 0 && (other.GetSize() == 0))
		throw - 1;
	while (i.doNext()) {
		ListIterator<TData> j = other.begin();
		while (j.doNext()) {
			result.push_back(*i * *j);
			j++;
		}
		i++;
	}
	return result;
}

TPolinom TPolinom::operator+(const TPolinom& other)
{
	if ((this->head == nullptr) || (other.head == nullptr))
		throw - 1;

	TPolinom result;
	ListIterator<TData> i = this->begin();
	ListIterator<TData> j = other.begin();
	TData temp;

	while (i.doNext() && j.doNext()) {
		if (*i == *j) {
			temp = (*i + *j)[0];
			i++;
			j++;
		}
		else if (*i > *j) {
			temp = *i;
			i++;
		}
		else if (*i < *j) {
			temp = *j;
			j++;
		}

		result.push_back(temp);
	}

	if (i.doNext())
		while (i.doNext()) {
			result.push_back(*i);
			i++;
		}

	if (j.doNext())
		while (j.doNext()) {
			result.push_back(*j);
			j++;
		}

	return result;
}

TPolinom TPolinom::operator-(const TPolinom& other)
{
	if ((this->head == nullptr) || (other.head == nullptr))
		throw - 1;

	TPolinom result;
	ListIterator<TData> i = this->begin();
	ListIterator<TData> j = other.begin();
	TData temp;

	while (i.doNext() && j.doNext()) {
		if (*i == *j) {
			temp = (*i - *j)[0];
			i++;
			j++;
		}
		else if (*i > *j) {
			temp = *i;
			i++;
		}
		else if (*i < *j) {
			temp = *j;
			temp.K *= -1;
			j++;
		}

		result.push_back(temp);
	}

	if (i.doNext())
		while (i.doNext()) {
			TData temp = *i;
			result.push_back(temp);
			i++;
		}

	if (j.doNext())
		while (j.doNext()) {
			TData temp = *j;
			temp.K *= -1;
			result.push_back(temp);
			j++;
		}

	return result;
}

ostream& operator<<(ostream& ostr, const TPolinom& p)
{
	ListIterator<TData> i = p.begin();
	while (i.doNext()) {
		if (*i == *p.begin())
			ostr << *i;
		else
			ostr << (((*i).K > 0) ? " + " : " ") << *i;
		i++;
	}
	return ostr;
}
