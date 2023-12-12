/*************************************************
* Автор:   Семенов М.В.                          *
* Дата:  04.12.2023                              *
* Название:  Арифметика длинных чисел            *
*   https://onlinegdb.com/rCQ3BdFI4e             *
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
    for (int i = number.size() - 1; i >= 0; --i) {
      cout << number[i];
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
  for (int i = 0; i < min(a.number.size(), b.number.size()); ++i) {
    int cur_sum = carry + a.number[i] + b.number[i];
    result.push_back(cur_sum % 10);
    carry = cur_sum / 10;  
  }

  for (int i = min(a.number.size(), b.number.size()); i < max(a.number.size(), b.number.size()); ++i) {
    if (a.number.size() > b.number.size()) {
      int cur_sum = carry + a.number[i];
      result.push_back(cur_sum % 10);
      carry = cur_sum / 10;
    } else {
      int cur_sum = carry + b.number[i];
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
  for (int i = 0; i < b.number.size(); ++i) {
    int cur_diff = a.number[i] - b.number[i] - carry;
    if (cur_diff < 0) {
      cur_diff += 10;
      carry = 1;
    } else {
      carry = 0;
    }

    result.push_back(cur_diff);
  }

  for (int i = b.number.size(); i < a.number.size(); ++i) {
    if (a.number[i] < 0) {
      result.push_back(a.number[i] + 10 - carry);
      carry = 1;
    } else {
      result.push_back(a.number[i] - carry);
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
  for (int i = 0; i < a.number.size(); ++i) {
    int carry = 0;
    for (int j = 0; j < b.number.size(); ++j) {
      int cur = result[i + j] + a.number[i] * b.number[j] + carry;
      carry = cur / a.base;
      result[i + j] = cur / a.base;
    }
    int cur = b.number.size();
    while (carry) {
      result[i + cur] = carry % a.base;
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
  BigInt a("1000");
  BigInt b(1000);
  BigInt c = a + b;
  BigInt d = a - b;
  BigInt e = a * b;
  c.write();
  d.write();
  e.write();
  
  return 0;
}   
