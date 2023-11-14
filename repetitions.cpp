/*************************************************
* Автор: Семенов М.В.                            *
* Дата: 14.11.2023                               *
* Название: Частота повторений                   *
* https://onlinegdb.com/qP7_UZMIJ                *
**************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
  int counter_letter, counter_DualLett;
  char letter, ch_prev, ch_curr;
  string DualLett, DualLett2;
  string path = "UrFile.txt"; // сюда пишем название файла
  
  counter_letter = 0;
  counter_DualLett = 0;
  DualLett2 = "";
  
  cout << "Введите букву: ";
  cin >> letter;
  cout << "Введите двухбуквенное сочетание: ";
  cin >> DualLett;
  
  ifstream file(path);
  
  if (!file.is_open()) {
    cout << "Не удалось открыть файл";
    return 1;
  }
  
  file.get(ch_prev);
  
  if (ch_prev == letter) {
    ++counter_letter;
  }
  
  while (file.get(ch_curr)) {
    
    if (ch_curr == letter) {
      ++counter_letter;
    }
    
    DualLett2 += ch_prev;
    DualLett2 += ch_curr;

    if (DualLett == DualLett2) {
      ++counter_DualLett;
    }
    
    ch_prev = ch_curr;
    DualLett2 = "";
  }
  
  file.close();
  
  cout << "Количество однобуквенных повторений: " << counter_letter - 1 << " | Количество двухбуквенных повторений: " << counter_DualLett - 1;
  
  return 0;
  
}
