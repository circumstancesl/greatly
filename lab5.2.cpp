/*************************************************
* Автор:     Семенов М.В.                        *
* Дата:      23.10.2023                          *
* Название:  Пятая программа на C++              *
* https://onlinegdb.com/T2R63mgdL вариант 17     *
**************************************************/

#include <iostream>

using namespace std;

void countElements(int arr[], int nvm, int cgo, int& count) {
  count = 0;
  for (int idota = 0; idota < nvm; ++idota) {
    if (arr[idota] > cgo) {
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

  countElements(arrayT, size_T, crg, countT);
  countElements(arrayY, size_Y, crg, countY);

  cout << "Количество элементов массива T, больших " << crg << ": " << countT << endl;
  cout << "Количество элементов массива Y, больших " << crg << ": " << countY << endl;

  return 0;
}
