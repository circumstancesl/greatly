/*************************************************
* Автор:     Семенов М.В.                        *
* Дата:      25.09.2023                          *
* Название:  Третья программа на C++             *
*   https://onlinegdb.com/3OhJqt1dP вариант 17   *
**************************************************/

#include <iostream>

#include <math.h>

using namespace std;

int main() {
  double u1 = 0.9,
  u2 = 0.6,
  j = 1, // счётчик
  g = 9.8, Q1, Q2, A, h2, h1, h, d1;
  cout << "Введите высоту h1 (м) = ";
  cin >> h1;
  cout << "Введите высоту h (м) = ";
  cin >> h;
  cout << "Введите диаметр d1 (см) = ";
  cin >> d1;
  int size;
  cout << "Введите количество элементов d2 = ";
  cin >> size;
  int array[size], i = 0;
  cout << "Введите элементы: ";
  for (int i = 0; i < size; ++i) {
    cout << "Элемент d2 | " << i + 1 << " = ";
    cin >> array[i];
  } 
  
  // перевод значений в сантиметры
  h1 = 5 * 100;
  h = 1 * 100;
  g = 9.8 * 100;
  
  // вычисление основных значений
  while (j <= size) {
    Q1 = M_PI * u1 * pow(d1, 2) * sqrt(2 * g * (h1 - h)) / 4;
    Q2 = M_PI * u2 * pow(array[i], 2) * sqrt(2 * g * h) / 4;
    A = pow( ((u1 * pow(d1, 2)) / (u2 * pow(array[i], 2)) ), 2);
    
      if (Q1 < Q2) {
        h2 = A * (h1 - h);
        i = ++i;
        j = ++j;
      } else {
        h2 = (A * h1) / (1 + A);  
        i = ++i;
        j = ++j;
      }
      cout.precision(2);
      cout << "h2 = " << fixed << h2 << " | Q1 = " << Q1 << " | Q2 = " << Q2 << endl;
  } 
  
  return 0;
}
