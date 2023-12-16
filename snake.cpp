/*************************************************
* Автор:     Семенов М.В.                        *
* Дата:      16.12.2023                          *
* Название:  Змейка                              *
*   https://onlinegdb.com/NhtdO7tMm              *
**************************************************/

#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

bool gameOver;
const int height = 20;
const int width = 20;

int x, y, fruitX, fruitY, score;

int tailX[100], tailY[100], nTail;

enum eDirection {STOP = 0, UP, DOWN, LEFT, RIGHT};
eDirection dir;

void setup() {
  gameOver = false;
  dir = STOP;
  x = width / 2; // змейка появляется по центру
  y = height / 2;
  fruitX = rand() % width; // фрукты появляются рандомно
  fruitY = rand() % height;
}

void draw() {

  system("CLS");
  
  // вывод верхней горизонтальной стенки
  for (int matrixIndexX = 0; matrixIndexX < width; ++matrixIndexX) {
    cout << "#";
  } cout << endl;

  // вывод боковых стенок
  for (int matrixIndexY = 0; matrixIndexY < height; ++matrixIndexY) {
    for (int matrixIndexX = 0; matrixIndexX < width; ++matrixIndexX) {
      if (matrixIndexX == 0 || matrixIndexX == width - 1) {
        cout << "#";
      } else if (matrixIndexY == y && matrixIndexX == x) { // вывод начала змейки
          cout << "O";
      } else if (matrixIndexY == fruitY && matrixIndexX == fruitX) { // вывод фруктов
          cout << "F";
      } else {

          bool print = false;

          for (int k = 0; k < nTail; ++k) { // вывод хвоста
            if (matrixIndexY == tailY[k] && matrixIndexX == tailX[k]) {
              cout << "o";
              print = true;
            }
          } if (!print) {
            cout << " ";
            }
      }
    } cout << endl;
  }
  
  // вывод нижней стенки
  for (int matrixIndexX = 0; matrixIndexX < width; ++matrixIndexX) { 
    cout << "#";
  } cout << endl;
  cout << endl;
  cout << "Score: " << score << endl; // вывод счета
}

void input() {
  if (_kbhit()) { // управление (ввод)
    switch(_getch()) {
      case 'w':
        dir = UP;
        break;
      case 'a':
        dir = LEFT;
        break;
      case 's':
        dir = DOWN;
        break;
      case 'd':
        dir = RIGHT;
        break;
    default:
      break;
    }
  }
}

void logic() {

  int prevX = tailX[0];
  int prevY = tailY[0];
  tailX[0] = x;
  tailY[0] = y;
  int prev2X, prev2Y;

  for (int i = 1; i < nTail; ++i) {
    prev2X = tailX[i];
    prev2Y = tailY[i];
    tailX[i] = prevX;
    tailY[i] = prevY;
    prevX = prev2X;
    prevY = prev2Y;
  }

  switch(dir) {
    case UP: // управление (логика)
      --y;
      break;
    case DOWN:
      ++y;
      break;
    case LEFT:
      --x;
      break;
    case RIGHT:
      ++x;
      break;
    default:
      break;
  }

  if (x < 0 || x > width || y < 0 || y > width) {
    gameOver = true;
  }
  
  for (int i = 0; i < nTail; ++i) {
    if (x == tailX[i] && y == tailY[i]) {
      gameOver = true;
    }
  }

  if (x == fruitX && y == fruitY) {
    score += 10;
    fruitX = rand() % width;
    fruitY = rand() % height;
    ++nTail;
  }
}

int main() {
  setup();
  while(!gameOver) {
    draw();
    input();
    logic();
    Sleep(40); // задаю delay консоли 40 мс
  }

  return 0;
}
