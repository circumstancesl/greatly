/*************************************************
* Автор:     Семенов М.В.                        *
* Дата:      25.09.2023                          *
* Название:  Первая программа на C++             *
*   https://onlinegdb.com/fWwJpWU3y9 вариант 17  *
**************************************************/

#include <iostream>
#include <math.h>

using namespace std;

int main() {
  double u1 = 0.9,
  u2 = 0.6,
  counter = 1, // счётчик
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
  int array[size], scale = 0;
  cout << "Введите элементы: ";
  for (int scale = 0; scale < size; ++scale) {
    cout << "Элемент d2 | " << scale + 1 << " = ";
    cin >> array[scale];
  } 
  
  // перевод значений в сантиметры
  h1 = 5 * 100;
  h = 1 * 100;
  g = 9.8 * 100;
  
  // вычисление основных значений
  while (counter <= size) {
    Q1 = M_PI * u1 * pow(d1, 2) * sqrt(2 * g * (h1 - h)) / 4;
    Q2 = M_PI * u2 * pow(array[scale], 2) * sqrt(2 * g * h) / 4;
    A = pow( ((u1 * pow(d1, 2)) / (u2 * pow(array[scale], 2))), 2);
    
      if (Q1 < Q2) {
        h2 = A * (h1 - h);
      } else {
        h2 = (A * h1) / (1 + A);  
      }
      ++scale;
      ++counter;
      cout.precision(2);
      cout << "h2 = " << fixed << h2 << " | Q1 = " << Q1 << " | Q2 = " << Q2 << endl;
  } 
  
  return 0;
}
