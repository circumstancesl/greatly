/*************************************************
* Автор:   Семенов М.В.                          *
* Дата:  27.11.2023                              *
* Название:  Календарь                           *
*   https://onlinegdb.com/OsGFZtOZc              *
**************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int year;

  cout << "Введите год: ";
  cin >> year;

  // Проверка на високосный год
  bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

  int daysInMonth[] = {31, (isLeapYear ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  string monthNames[] = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};

  cout << "Календарь на " << year << " год:" << endl;

  // Вывод каждого месяца
  for (int indexMonth = 0; indexMonth < 12; ++indexMonth) {
    cout << "--------------------" << endl;
    cout << monthNames[indexMonth] << endl;
    cout << "--------------------" << endl;
    cout << "Пн Вт Ср Чт Пт Сб Вс" << endl;

  // Определение дня недели для 1-го числа месяца
    int startDay = (year + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
    for (int indexDay = 0; indexDay < startDay; ++indexDay) {
      cout << "   ";
    }

  // Вывод чисел месяца
    for (int indexDay = 1; indexDay <= daysInMonth[indexMonth]; ++indexDay) {
      if (startDay % 7 == 6) {
        cout << setw(2) << indexDay << endl;
      } else {
        cout << setw(2) << indexDay << " ";
      }
      ++startDay;
    }
    cout << endl;
  }

  return 0;
}
