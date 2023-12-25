/***************************************
* Автор:     Семенов М.В.              *
* Дата:      25.12.2023                *
* Название:  Тетрис                    *
*  https://onlinegdb.com/19lPnfnKr     *
****************************************/
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;

const int fld_width = 20; // размер игрового поля (клетки)
const int fld_height = 30;
const int scr_width = fld_width * 2; // размер консольного окна в символах (одна клетка два символа по горизонтали)
const int scr_height = fld_height;

const char c_fig = 219; // символ для отображения фигуры

typedef char TScreenMap[scr_height][scr_width]; // хранит символы для вывода на экран
typedef char TFieldMap[fld_height][fld_width];

const int shp_width = 4; // максимальные размеры фигуры
const int shp_height = 4;
typedef char TShape[shp_height][shp_width]; // хранит форму фигуры в виде матрицы 4x4

int score;

char *shpArr[] = {
  (char*)".....**..**.....", // квадрат
  (char*)"....****........", // линия
  (char*)"....***..*......", // буква т
  (char*)".....***.*......", // буква л
  (char*)".....**.**......" }; // буква s

const int shpArrCnt = sizeof(shpArr) / sizeof(shpArr[0]); // количество форм объектов

void setCurPos(int x, int y) { // функция помещает курсор в заданную точку экрана
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class TScreen { // класс для вывода в консольное окно
  void setEnd() { scr[scr_height - 1][scr_width - 1] = '\0'; } 
public:
  TScreenMap scr;
  TScreen() {Clear(); }
  void Clear() { memset(scr, '.', sizeof(scr)); } // заполнение массива точками
  void ShowScore () { 
    string str = "Score:";
    string str_score =  to_string(score);
    string sumStr = str + str_score;
    for (int elementIndex = 0; elementIndex < sumStr.length(); ++elementIndex) {
      scr[0][elementIndex] = sumStr[elementIndex];
    }
  }
  void Show() { setCurPos(0,0); setEnd(); cout << scr[0]; } // вывод массива на экран
};

class TField {
public:
  TFieldMap fld; // fld хранит игровое поле
  TField() { Clear(); }
  void Clear() { memset(fld, ' ', sizeof(fld)); } // заполнение игрового поля пустыми клетками
  void Put(TScreenMap &scr); // рисует игровое поле на экранном буфере
  void Burning();
};

class TFigure {
  int x, y; // положение фигуры
  TShape vid; // форма фигуры
  char turn;
  COORD coord[shp_width * shp_height]; // координаты для каждой клеточки объекта
  int coordCnt;
  TField *field = 0;
public:
  TFigure() { memset(this, 0, sizeof(*this)); } // заполнение памяти объекта нулями
  void FieldSet(TField *_field) { field = _field; }
  void Shape (char* _vid) { memcpy(vid, _vid, sizeof(vid)); } // загружает символы для формы фигуры
  void Pos(int _x, int _y) { x = _x; y = _y; CalcCoord(); } // установление позиции для фигуры
  char TurnGet() { return turn; }
  void TurnSet( char _turn );
  void Put(TScreenMap &scr); // помещение в буфер
  void Put(TFieldMap &fld);
  bool Move(int dx, int dy);
  int Check();
private:
  void CalcCoord();
};

class TGame {
  TScreen screen;
  TField field;
  TFigure figure;
public:
  TGame();
  void PlayerControl();
  void Move();
  void Show();
};

TGame::TGame() {
  figure.FieldSet(&field);
  figure.Shape(shpArr[rand() % shpArrCnt]);
  figure.Pos(fld_width / 2 - shp_width / 2, 0);
}

void TGame::PlayerControl() {
  static int trn = 0;
  if (GetKeyState('W') < 0) trn += 1;
  if (trn == 1) figure.TurnSet(figure.TurnGet() + 1), ++trn;
  if (GetKeyState('W') >= 0) trn = 0;

  if (GetKeyState('S') < 0) figure.Move(0, 1);
  if (GetKeyState('A') < 0) figure.Move(-1, 0);
  if (GetKeyState('D') < 0) figure.Move(1, 0);
}

void TGame::Show() {
  screen.Clear(); // чистим буфер
  field.Put(screen.scr);
  figure.Put(screen.scr);
  screen.ShowScore();
  screen.Show(); // показываем буфер на экране
}

void TGame::Move() { // автоматическое движение вниз
  static int tick = 0;
  char* currentFigure;
  char* nextFigure;
  ++tick;
  if (tick >= 5) {
    if (!figure.Move(0, 1)) { // новая фигура
      currentFigure = shpArr[rand() % shpArrCnt];
      nextFigure = shpArr[rand() % shpArrCnt];
      figure.Put(field.fld); // накопление объектов
      figure.Shape(currentFigure);
      figure.Pos(fld_width / 2 - shp_width / 2, 0);
      if (figure.Check() > 0) // новая игра
        field.Clear();
    }
    field.Burning();
    tick = 0;
  } 
}

void TFigure::Put(TScreenMap &scr) {
  for (int elementCord = 0; elementCord < coordCnt; ++elementCord) 
    scr[coord[elementCord].Y][coord[elementCord].X*2] = scr[coord[elementCord].Y][coord[elementCord].X*2+1] = c_fig; // вычисление позиции для фигуры и заполнение символов экранного буфера символами фигуры
}

void TFigure::Put(TFieldMap &fld) {
  for (int elementCord = 0; elementCord < coordCnt; ++elementCord)
    fld[coord[elementCord].Y][coord[elementCord].X] = c_fig; // вычисление позиции для фигуры и заполнение символами экранного буфера приземлившимися симфолами фигуры
}

void TFigure::TurnSet(char _turn) {
  int oldTurn = turn;
  turn = (_turn > 3 ? 0 : (_turn < 0 ? 3 : _turn)); // поворот на один из четырех углов
  int chk = Check(); // проверка на столкновение
  if (chk == 0) return;
  if (chk == 1) { // если вышли за границы
    int xx = x; // то пробуем три раза подвинуть объект от границ
    int k = (x > (fld_width / 2) ? -1 : +1);
    for (int turnIndex = 1; turnIndex < 3; ++turnIndex) {
      x += k;
      if (Check() == 0) return;
    }
    x = xx;
  }
  turn = oldTurn;
  CalcCoord();
}

bool TFigure::Move(int dx, int dy) {
  int oldX = x, oldY = y;
  Pos(x + dx, y + dy);
  int chk = Check();
  if (chk >= 1) {
    Pos(oldX, oldY);
    if (chk == 2)
      return false; // приземляем объект и создаем новый
  }
  return true;
}

int TFigure::Check() { // вышла ли фигура за границы экрана
  CalcCoord();
  for (int elementCord = 0; elementCord < coordCnt; ++elementCord) // не даем выйти за вертикальные поля
    if (coord[elementCord].X < 0 || coord[elementCord].X >= fld_width)
      return 1;
  for (int elementCord = 0; elementCord < coordCnt; ++elementCord) // оставляем внизу горизонтального поля
    if (coord[elementCord].Y >= fld_height || field ->fld[coord[elementCord].Y][coord[elementCord].X] == c_fig) // накапливаем 
      return 2;
  return 0;
}

void TFigure::CalcCoord() { // ограничение перемещения
  int xx, yy;
  coordCnt = 0;
  for (int elementCordX = 0; elementCordX < shp_width; ++elementCordX) // проходим по всей фигуре
    for (int elementCordY = 0; elementCordY < shp_height; ++elementCordY)
      if (vid[elementCordY][elementCordX] == '*') {
        if (turn == 0) xx = x + elementCordX, yy = y + elementCordY; 
        if (turn == 1) xx = x + (shp_height - elementCordY - 1), yy = y + elementCordX; // (1 - поворот на 90 градусов по часовой)
        if (turn == 2) xx = x + (shp_width - elementCordX - 1), yy = y + (shp_height - elementCordY - 1);
        if (turn == 3) xx = x + elementCordY, yy = y + (shp_height - elementCordX - 1) + (shp_width - shp_height);
        coord[coordCnt] = COORD({(short)xx, (short)yy}); // записываем в массив координаты
        ++coordCnt;
      }
}

void TField::Put(TScreenMap &scr) {
  for (int elementCordX = 0; elementCordX < fld_width; ++elementCordX)
    for (int elementCordY = 0; elementCordY < fld_height; ++elementCordY)
      scr[elementCordY][elementCordX*2] = scr[elementCordY][elementCordX*2+1] = fld[elementCordY][elementCordX]; // каждую клетку поля отображаем на двух символах подряд
}

void TField::Burning() {
  for (int elementCordY = fld_height - 1; elementCordY >= 0; --elementCordY) { // проходим по всему игровому полю снизу вверх
    static bool fillLine;
    fillLine = true;
    for (int elementCordX = 0; elementCordX < fld_width; ++elementCordX) // ищем целую строку
      if (fld[elementCordY][elementCordX] != c_fig)
        fillLine = false;
    if (fillLine) {
      for (int y = elementCordY; y >= 1; --y) // двигаем всё, что выше на одну строчку вниз
        memcpy(fld[y], fld[y - 1], sizeof(fld[y]));
        score += 10;
      return;
    }
  }
}

int main() {
  int speedGame = 50;
  char command[1000]; // приводим консоль к заданным размерам
  sprintf_s(command, "mode con cols=%d lines=%d", scr_width, scr_height);
  system(command);

  srand(time(0)); // инициализация рандомайзера
  TGame game;
  TScreen screen;
  while (1) {
    game.PlayerControl();
    game.Move();
    game.Show();
    if (GetKeyState(VK_ESCAPE) < 0) break; // закрытие игры по ESC
    speedGame - score;
    Sleep(speedGame);
  }

  return 0;
}
