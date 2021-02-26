#include <stdio.h>
#include "convertor.h"
#include <locale>
int main() {
  setlocale(LC_ALL, "Russian");
  printf("����� ����� �� ������ ��������������?\n������� 1,���� ��������\n������� 2, ���� �������\n������� ����� �������� ��� ������ �� ���������\n");
  int f;
  cin >> f;
  Convertor conv;
  int charb;
  string chro;
  switch (f)
  {
  case(1):
	  cout << "������� �������� �����=>";
	  cin >> charb;
	  conv.print(charb);
	  conv.ar.value = charb;
	  chro = conv.toRoman(conv.ar).value;
	  cout << endl << "������� �����:" << chro<<endl;
	  break;
  case(2):
	  cout << "������� ������� �����=>";
	  cin >> chro;
	  conv.ro.value = chro;
	  if (conv.check(conv.ro) == 1)
	  {
		  cout << "������� ����� ������� �����������. ���������� ��� ���.";
		  break;
	  }
	  conv.print(chro);

	  charb = conv.toArabic(conv.ro).value;
	  cout << endl << "�������� �����:" << charb << endl;
	  break;
  default:
	  break;
  }
  return 0;
}