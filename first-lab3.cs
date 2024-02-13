using System;

class Program {
  static void Main() {
    Console.WriteLine("Введите число");
    int Number = Convert.ToInt32(Console.ReadLine());

    Console.WriteLine("Введите степень числа");
    int Pow = Convert.ToInt32(Console.ReadLine());

    Console.WriteLine("Введите число x, больше или равно 100");
    string NumberX = Console.ReadLine();

    int Result = Number;
    string NumberN;

    for (int NumberIndex = 1; NumberIndex < Pow; ++NumberIndex) {
      Result *= Number;
    }

    char SecondDigit = NumberX[1];
    NumberN = NumberX.Remove(1, 1) + SecondDigit;

    Console.WriteLine($"{Number} в степени {Pow} = {Result}");
    Console.WriteLine($"Число N: {NumberN}");
  }
}
