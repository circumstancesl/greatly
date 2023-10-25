/*************************************************
* Автор: Семенов М.В.                            *
* Дата: 02.10.2023                               *
* Название: Вторая программа c++                 *
*  https://onlinegdb.com/Cs2B_JpnS вариант 17    *
**************************************************/

#include <iostream>
#include <math.h>

using namespace std;

int main() {
  double G, n, S, d, counter, P;
  cout << "Введите вес аппарата (кг) = ";
  cin >> G;
  cout << "Введите число воздушных сопел = ";
  cin >> n;
  cout << "Введите значение расстояния между соплами (см) = ";
  cin >> S;
  cout << "Введите диаметр сопел (см) = ";
  cin >> d;
  counter = 1; // Счётчик 
  cout.precision(3);
  
  // Находим значения по каждому диаметру
  while (counter < 5) {
    ++counter;
    d = d + 0.1;
    P = 2.55 * (G / n) * (log(S / d) / (pow(S, 2) - pow(d, 2)));
    cout << "Диаметр сопел = " << fixed << d << " | Давление воздуха = " << P << endl;
  }
  
  do {
    P = 2.55 * (G / n) * (log(S / d) / (pow(S, 2) - pow(d, 2)));
    cout << "Диаметр сопел = " << fixed << d << " | Давление воздуха = " << P << endl;
    d = d + 0.25;
    ++counter; } while (counter < 20);
  
  return 0;
}
