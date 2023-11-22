/*************************************************
* Автор:     Семенов М.В.                        *
* Дата:      20.11.2023                          *
* Название:  Арабские числа                      *
*   https://onlinegdb.com/UNEA-m8LC              *
**************************************************/
#include <iostream>
#include <string>

using namespace std;

struct numbersArrays {
  int arabicNumbers[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  string romanNumbers[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
};

string convertArabicToRoman(int number) {
  string result = "";
  numbersArrays structNumbers;

  for (int arabicIndex = 0; arabicIndex < 13; ++arabicIndex) {
    while (number >= structNumbers.arabicNumbers[arabicIndex]) {
      result += structNumbers.romanNumbers[arabicIndex];
      number -= structNumbers.arabicNumbers[arabicIndex];
    }
  }

  return result;
}

int convertRomanToArabic(string roman) {
  int result = 0;
  int romanIndex = 0;
  while (romanIndex < roman.length()) {
    if (roman[romanIndex] == 'M') {
      result += 1000;
      ++romanIndex;

    } else if (roman[romanIndex] == 'D') {
      result += 500;
      ++romanIndex;

    } else if (roman[romanIndex] == 'C') {
      if (romanIndex + 1 < roman.length() && roman[romanIndex + 1] == 'M') {
        result += 900;
        romanIndex += 2;

      } else if (romanIndex + 1 < roman.length() && roman[romanIndex + 1] == 'D') {
        result += 400;
        romanIndex += 2;

      } else {
        result += 100;
        ++romanIndex;

      }
    } else if (roman[romanIndex] == 'L') {
      result += 50;
      ++romanIndex;

    } else if (roman[romanIndex] == 'X') {
      if (romanIndex + 1 < roman.length() && roman[romanIndex + 1] == 'C') {
        result += 90;
        romanIndex += 2;

      } else if (romanIndex + 1 < roman.length() && roman[romanIndex + 1] == 'L') {
        result += 40;
        romanIndex += 2;

      } else {
        result += 10;
        ++romanIndex;
      }

    } else if (roman[romanIndex] == 'V') {
      result += 5;
      ++romanIndex;

    } else if (roman[romanIndex] == 'I') {
      if (romanIndex + 1 < roman.length() && roman[romanIndex + 1] == 'X') {
        result += 9;
        romanIndex += 2;

      } else if (romanIndex + 1 < roman.length() && roman[romanIndex + 1] == 'V') {
        result += 4;
        romanIndex += 2;

      } else {
        result += 1;
        ++romanIndex;
      }
    }
  }

  return result;
}

int main() {
  int inputArabic;
  string inputRoman;

  cout << "Введите число арабскими цифрами: ";
  cin >> inputArabic;

  cout << "Римскими цифрами: " << convertArabicToRoman(inputArabic) << endl;

  cout << "Введите число римскими цифрами: ";
  cin >> inputRoman;

  cout << "Арабскими цифрами: " << convertRomanToArabic(inputRoman) << endl;
    
  return 0;
}
