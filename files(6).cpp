/*************************************************
* Автор:     Семенов М.В.                        *
* Дата:      30.10.2023                          *
* Название:  Шестая программа на C++             *
*   https://onlinegdb.com/k8tivW6AG вариант 17   *
**************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct Route {
  string Number;
  string Endstations;
  int Duration;
  int NumBuses;
};

int main() {
  ifstream file("text.txt");
  if (file.is_open()) {
    cout << "Ошибка! Файл не найден" << endl;
    return 1;
  }
  
  vector<Route> routes; // создаем вектор для хранения инфы
  
  string line;
  while (getline(file, line)) {
    Route route;
    route.Number = line.substr(0, line.find(',')); // номер маршрута
    line = line.substr(line.find(',') + 1);
    route.Endstations = line.substr(0, line.find(',')); // названия конечных остановок
    line = line.substr(line.find(',') + 1);
    route.Duration = stoi(line.substr(0, line.find(','))); // продолжительность движения
    line = line.substr(line.find(',') + 1);
    route.NumBuses = stoi(line); // число автобусов
    routes.push_back(route); // добавление в вектор инфу
  }
  
  file.close();
  
  cout << "Сведения о маршрутах, число автобусов на которых менее задаваемой величины: " << endl;
  int maxBuses = 0;
  int maxBusesIndex = -1;
  int interval = 0;
  for (int ik = 0; ik < routes.size(); ++ik) { // цикл с каждым маршрутом
    Route route = routes[ik];
    if (route.NumBuses < 3) { // задал величину = 3
      cout << "Маршрут: " << route.Number << endl;
      cout << "Конечные остановки: " << route.Endstations << endl;
      cout << "Продолжительность движения: " << route.Duration << endl;
      cout << "Число автобусов: " << route.NumBuses << endl;
      cout << endl;
      interval = route.Duration / route.NumBuses;
      cout << "Средний интервал движения автобусов: " << interval << endl;
    }
  
    // нахожу маршрут с максимальным количеством автобусов
    if (route.NumBuses > maxBuses) {
      maxBuses = route.NumBuses;
      maxBusesIndex = ik;
    }
  }
  
  // вывод инфы о макс.маршрут
  if (maxBusesIndex != -1) {
    cout << "Маршрут с наибольшим числом автобусов: " << endl;
    Route maxBusesRoute = routes[maxBusesIndex];
    cout << "Маршрут: " << maxBusesRoute.Number << endl;
    cout << "Конечные остановки: " << maxBusesRoute.Endstations << endl;
    cout << "Продолжительность движения: " << maxBusesRoute.Duration << endl;
    cout << "Число автобусов: " << maxBusesRoute.NumBuses << endl;
  }

  return 0;
}
