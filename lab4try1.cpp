/*************************************************
* Автор: Семенов М.В.                            *
* Дата: 02.10.2023                               *
* Название: четвертая программа c++              *
*  https://onlinegdb.com/ejcTaEYsBc вариант 17   *
**************************************************/
#include <iostream>

using namespace std;

int main() {
  int rows, columns;
  cout << "Введите количество строк матрицы = ";
  cin >> rows;
  cout << "Введите количество столбцов матрицы = ";
  cin >> columns;
  
  // Создаем двумерный массив
  int array[rows][columns];
  
  // Вводим элементы матрицы
  cout << "Введите элементы матрицы:\n";
  for (int counter_rows = 0; counter_rows < rows; ++counter_rows) {
    for (int counter_columns = 0; counter_columns < columns; ++counter_columns) {
      cin >> array[counter_rows][counter_columns];
    }
  }
  
  // Вывод исходной матрицы
  cout << "Исходная матрица:\n";
  for (int counter_rows = 0; counter_rows < rows; ++counter_rows) {
    for (int counter_columns = 0; counter_columns < columns; ++counter_columns) {
      cout << array[counter_rows][counter_columns] << " ";
    }
    cout << endl;
  }
  
  // Цикл упорядочивания по убыванию
  for (int counter_columns = 0; counter_columns < columns; ++counter_columns) {
    for (int counter_rows = 0; counter_rows < rows - 1; ++counter_rows) {
      for (int keep = 0; keep < rows - counter_rows - 1; ++keep) {
        if (array[keep][counter_columns] < array[keep + 1][counter_columns]) {
          int temp = array[keep][counter_columns];
          array[keep][counter_columns] = array[keep + 1][counter_columns];
          array[keep + 1][counter_columns] = temp;
        }
      }
    }
  }
  
  // Вывод упорядоченной матрицы
  cout << "Упорядоченная матрица:\n";
  for (int counter_rows = 0; counter_rows < rows; ++counter_rows) {
    for (int counter_columns = 0; counter_columns < columns; ++counter_columns) {
      cout << array[counter_rows][counter_columns] << " ";
    }
    cout << endl;
  }  
  
  return 0;
}
