/*************************************************
* Автор:     Семенов М.В.                        *
* Дата:      23.10.2023                          *
* Название:  Пятая программа на C++              *
* https://onlinegdb.com/3uOKCIBry вариант 17     *
**************************************************/

#include <iostream>

using namespace std;

void countElements(int arr[], int size_array, int c, int& count) {
  count = 0;
  for (int numberIndex = 0; numberIndex < size_array; ++numberIndex) {
    if (arr[numberIndex] > c) {
      ++count;
    }
  }
}

int main() {
  int crg, size_T, size_Y, countT, countY;

  cout << "Введите значение C = ";
  cin >> crg;
  cout << "Введите количество элементов массива T = ";
  cin >> size_T;

  // Обработка массива T
  int arrayT[size_T];

  cout << "Введите элементы массива T:" << endl;
  for (int elementTIndex = 0; elementTIndex < size_T; ++elementTIndex) {
    cout << "Элемент " << elementTIndex + 1 << ": ";
    cin >> arrayT[elementTIndex];
  }

  cout << "Введите количество элементов массива Y = ";
  cin >> size_Y;

  // Обработка массива Y
  int arrayY[size_Y];

  cout << "Введите элементы массива Y:" << endl;
  for (int elementYIndex = 0; elementYIndex < size_Y; ++elementYIndex) {
    cout << "Элемент " << elementYIndex + 1 << ": ";
    cin >> arrayY[elementYIndex];
  }

  countElements(arrayT, size_T, crg, countT);
  countElements(arrayY, size_Y, crg, countY);

  cout << "Количество элементов массивов T и Y, больших " << crg << ": " << countT << "; " << countY << endl;

  return 0;
}
