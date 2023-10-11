/*************************************************
* Автор: Семенов М.В.                            *
* Дата: 02.10.2023                               *
* Название: Вторая программа                     *
*  https://onlinegdb.com/k-sShiXVv вариант 17    *
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
  
  // Находим значения по каждому диаметру
  while (counter < 10) {
    P = 2.55 * (G / n) * (log(S / d) / (pow(S, 2) - pow(d, 2)));
    cout.precision(3);
    cout << "Диаметр сопел = " << fixed << d << " | Давление воздуха = " << P << endl;
    
    if (counter < 6) {
      d = d + 0.25;
      ++counter;
    } else {
      d = d + 1;
      ++counter;
    }
  }
  
  return 0;
}
