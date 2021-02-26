#include "convertor.h"
#include <locale>
int Convertor::Razryad(arabic t)
{
	int k=0;
	int t1 = t.value;
	while (t1 != 0)
	{
		t1 = t1 / 10;
		k++;
	}
	return k;
}

arabic Convertor::toArabic(roman t)
{
	int res=0;
	map<char, int> m;
	m = { {'I', 1}, {  'V',5 }, {  'X',10 }, {  'L',50 }, { 'C',100 },{  'D',500 },{  'M',1000 }};
	for (int i = 0; i < t.value.size()-1; i++)
	{
		if (m[t.value[i]] < m[t.value[i + 1]])
		{
	        res -= m[t.value[i]];
			continue;
		}
		
		res += m[t.value[i]];

	}
	res += m[t.value[t.value.size()-1]];
	ar.value = res;


	return ar;

}

roman Convertor::toRoman(arabic t)
{
	if (t.value >= 4000)
		throw logic_error("significant is too much");
	int n = Razryad(t);
	string res;
	int t1 = t.value;
	int t2=0;
	map<int, string> m;
	auto itm = m.begin();
	int k = n - 1;
	for (int i = n; i >= 1; i--)
	{
		t2 = t1 / pow(10,k);
		t1 = t1 % (int)pow(10, k);
	switch (i)
	{
	case(1):
	{
		if (t2 != 0)
		{
		m = { { 1, "I" },{ 2, "II" },{ 3, "III" },{ 4, "IV" },
			{ 5, "V" },{ 6, "VI" },{ 7, "VII" },{ 8, "VIII" },{ 9, "IX" } }; 
		itm = m.find(t2);
		res+= itm->second;
		m.erase(m.begin(), m.end());
		}
		break;
	}
	case(2):
	{
		if (t2 != 0)
		{
			m = { { 1, "X" },{ 2, "XX" },{ 3, "XXX" },{ 4, "XL" },
				{ 5, "L" },{ 6, "LX" },{ 7, "LXX" },{ 8, "LXXX" },{ 9, "XC" } };

			itm = m.find(t2);
			res+= itm->second;
			m.erase(m.begin(), m.end());
		}
		break;
	}
	case(3):
	{
		if (t2 != 0)
		{
			m = { { 1, "C" },{ 2, "CC" },{ 3, "CCC" },{ 4, "CD" },
				{ 5, "D" },{ 6, "DC" },{ 7, "DCC" },{ 8, "DCCC" },{ 9, "CM" } };

			itm = m.find(t2);
			res+= itm->second;
			m.erase(m.begin(), m.end());
		}
		break;
	}
	case(4):
	{
		if (t2 != 0)
		{

			m = { { 1, "M" },{ 2, "MM" },{ 3, "MMM" } };
			itm = m.find(t2);
			res+= itm->second;
			m.erase(m.begin(), m.end());
		}
		break;
	}
	default:
		break;
	}
	k--;
	}
	ro.value = res;
	return ro;
}

bool Convertor::check(roman& t)
{
	bool f = false;
	if (t.value.find("IIII") != string::npos || t.value.find("VV") != string::npos ||
		t.value.find("XXXX") != string::npos || t.value.find("LL") != string::npos ||
		t.value.find("CCCC") != string::npos || t.value.find("DD") != string::npos || t.value.find("MMMM") != string::npos)
	{
		f = true;
	}
	return f;
}
void Convertor::print(string t)
{
	setlocale(LC_ALL, "Russian");
	cout << "¬веденное римское число:" << t;
}

void Convertor::print(int t)
{
	setlocale(LC_ALL, "Russian");
	cout << "¬веденное арабское число:" << t;
}
