/*************************************************
* Автор:     Семенов М.В.                        *
* Дата:      23.10.2023                          *
* Название:  Пятая программа на C++              *
*   https://onlinegdb.com/gSLRp0iiQY вариант 17  *
**************************************************/

#include <iostream>

using namespace std;

int main() {
  int size_T, size_Y, crg,
  amountT = 0,
  amountY = 0;
  cout << "Введите значение C = ";
  cin >> crg;
  cout << "Введите количество элементов массива T = ";
  cin >> size_T;
  
  // Обработка массива T
  int arrayT[size_T];
  
  cout << "Введите элементы массива T:" << endl;
    for (int counterT = 0; counterT < size_T; ++counterT) {
      cout << "Элемент " << counterT + 1 << ": ";
      cin >> arrayT[counterT];
    }
    
  cout << "Введите количество элементов массива Y = ";
  cin >> size_Y;
  
  // Обработка массива Y
  int arrayY[size_Y];
  
  cout << "Введите элементы массива Y:" << endl;
    for (int counterY = 0; counterY < size_Y; ++counterY) {
      cout << "Элемент " << counterY + 1 << ": ";
      cin >> arrayY[counterY];
    }
    
  // Вычисление элементов > c
  for (int counter = 0; counter < size_T; ++counter) {
    if (arrayT[counter] > crg) {
      ++amountT;
    }
  }
    
  for (int counter = 0; counter < size_Y; ++counter) {
    if (arrayY[counter] > crg) {
      ++amountY;
    }
  }
  
  cout << "Количество элементов массива Т, больших " << crg << ": " << amountT << endl;
  cout << "Количество элементов массива Y, больших " << crg << ": " << amountY << endl;
  
  return 0;
}
