/*************************************************
* Автор:   Семенов М.В.                          *
* Дата:  12.12.2023                              *
* Название:  Длинные числа                       *
*   https://onlinegdb.com/8MQuEaWj7              *
**************************************************/
#include <bits/stdc++.h>

using namespace std;

struct BigInt {
public:
  BigInt() {
    number.resize(1);
    number[0] = 0;
  }

  BigInt(string s) {
    for (auto digit : s) {
      number.push_back(digit - '0');
    }

    reverse(number.begin(), number.end());
  }

  BigInt(vector<int> number) {
    this->number = number;
  }

  BigInt (long long number) { // берем по числу и идем пока оно не ноль, каждый раз вставляя новый разряд
    this->number.clear();
    while (number) {
      this->number.push_back(number % base);
      number /= base;
    }
  }
  
  void write_reversed() const {
    for (auto digit : number) {
      cout << digit;
    }

    cout << "\n";
  }

  void write() const {
    for (int indexNumber = number.size() - 1; indexNumber >= 0; --indexNumber) {
      cout << number[indexNumber];
    }

    cout << "\n";
  }

  friend BigInt operator + (const BigInt &a, const BigInt &b);
  friend BigInt operator - (const BigInt &a, const BigInt &b);
  friend BigInt operator * (const BigInt &a, const BigInt &b);

private:
  int base = 10;
  vector<int> number;  
};

BigInt operator + (const BigInt &a, const BigInt &b) {
  vector<int> result;
  int carry = 0;
  for (int indexNumber = 0; indexNumber < min(a.number.size(), b.number.size()); ++indexNumber) {
    int cur_sum = carry + a.number[indexNumber] + b.number[indexNumber];
    result.push_back(cur_sum % 10);
    carry = cur_sum / 10;  
  }

  for (int indexNumber = min(a.number.size(), b.number.size()); indexNumber < max(a.number.size(), b.number.size()); ++indexNumber) {
    if (a.number.size() > b.number.size()) {
      int cur_sum = carry + a.number[indexNumber];
      result.push_back(cur_sum % 10);
      carry = cur_sum / 10;
    } else {
      int cur_sum = carry + b.number[indexNumber];
      result.push_back(cur_sum % 10);
      carry = cur_sum / 10;
    } 
  }

  if (carry != 0) {
    result.push_back(carry);
  }

  BigInt c(result);
  return c;
}

BigInt operator - (const BigInt &a, const BigInt &b) {
  vector<int> result;
  int carry = 0;
  for (int indexNumber = 0; indexNumber < b.number.size(); ++indexNumber) {
    int cur_diff = a.number[indexNumber] - b.number[indexNumber] - carry;
    if (cur_diff < 0) {
      cur_diff += 10;
      carry = 1;
    } else {
      carry = 0;
    }

    result.push_back(cur_diff);
  }

  for (int indexNumber = b.number.size(); indexNumber < a.number.size(); ++indexNumber) {
    if (a.number[indexNumber] < 0) {
      result.push_back(a.number[indexNumber] + 10 - carry);
      carry = 1;
    } else {
      result.push_back(a.number[indexNumber] - carry);
      carry = 0;
    }
  }

  while (result.size() > 1 && !result.back()) { // пока ведущий 0 -> я его удаляю
    result.pop_back();
  }
  
  BigInt c(result);
  return c;
}

BigInt operator * (const BigInt &a, const BigInt &b) {
  vector<int> result(a.number.size() * b.number.size(), 0);
  for (int indexNumberA = 0; indexNumberA < a.number.size(); ++indexNumberA) {
    int carry = 0;
    for (int indexNumberB = 0; indexNumberB < b.number.size(); ++indexNumberB) {
      int cur = result[indexNumberA + indexNumberB] + a.number[indexNumberA] * b.number[indexNumberB] + carry;
      carry = cur / a.base;
      result[indexNumberA + indexNumberB] = cur / a.base;
    }
    int cur = b.number.size();
    while (carry) {
      result[indexNumberA + cur] = carry % a.base;
      ++cur;
      carry /= a.base;  
    }
  }
  while (result.size() > 1 && !result.back()) {
    result.pop_back();
  }

  BigInt c(result);
  return c;
}

int main() {
  BigInt a("1000"); // вводим первое число
  BigInt b(1000); // вводим второе число
  BigInt c = a + b;
  BigInt d = a - b;
  BigInt e = a * b;
  c.write();
  d.write();
  e.write();
  
  return 0;
}   
