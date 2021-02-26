#include <stdio.h>
#include "convertor.h"
#include <locale>
int main() {
  setlocale(LC_ALL, "Russian");
  printf("Какое число вы хотите конвертировать?\nВведите 1,если арабское\nВведите 2, если римское\nВведите любое значение для выхода из программы\n");
  int f;
  cin >> f;
  Convertor conv;
  int charb;
  string chro;
  switch (f)
  {
  case(1):
	  cout << "Введите арабское число=>";
	  cin >> charb;
	  conv.print(charb);
	  conv.ar.value = charb;
	  chro = conv.toRoman(conv.ar).value;
	  cout << endl << "Римское число:" << chro<<endl;
	  break;
  case(2):
	  cout << "Введите римское число=>";
	  cin >> chro;
	  conv.ro.value = chro;
	  if (conv.check(conv.ro) == 1)
	  {
		  cout << "Римское число введено неправильно. Попробуйте еще раз.";
		  break;
	  }
	  conv.print(chro);

	  charb = conv.toArabic(conv.ro).value;
	  cout << endl << "Арабское число:" << charb << endl;
	  break;
  default:
	  break;
  }
  return 0;
}