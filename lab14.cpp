/*************************************************
* Автор:     Семенов М.В.                        *
* Дата:      25.09.2023                          *
* Название:  Первая программа на C++             *
*   https://onlinegdb.com/k8tivW6AG вариант 17   *
**************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double U, R, L, f, t, phase, X, Y, angle, cirfrequency, Ul;
  
  cout << "Введите значение напряжения (вольт) = ";
  cin >> U;
  cout << "Введите значение сопротивления (ом) = ";
  cin >> R;
  cout << "Введите значение индуктивности (генри) = ";
  cin >> L;
  cout << "Введите значение частоты (герц) = ";
  cin >> f;
  cout << "Введите значение времени (секунды) = ";
  cin >> t;
  cout << "Введите значение начальной фазы напряжения (градусы) = ";
  cin >> phase;

  // Преобразование углов из градусов в радианы
  cirfrequency = 2 * M_PI * f;
  angle = atan( (cirfrequency * L) / R) * 180 / M_PI;

  // Расчет Y и X
  Y = cos(angle * M_PI / 180) * sin(phase * M_PI / 180 - angle * M_PI / 180) * exp(-t * R / L);
  X = sin(angle * M_PI / 180) * sin(cirfrequency * t + phase * M_PI / 180 - angle * M_PI / 180 + M_PI / 2);

  // Вычисление напряжения на индуктивности
  Ul = U * (X + Y);

  cout.precision(8);
  cout << "Напряжение, возникающее на индуктивности = " << fixed << Ul << endl;

  return 0;
}
