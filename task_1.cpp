#include <iostream>
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

int  ReadInt(const char* prompt, int minValue, int maxValue);
void ConvertToBase(int number, int base);

int main()
{
    setlocale(LC_ALL, "Russian");
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    cout << "--- Задание 1: перевод числа в другую систему счисления ---\n";
    cout << "Примеры из задания:\n";
    ConvertToBase(27, 16);
    ConvertToBase(13, 5);
    ConvertToBase(35, 18);

    cout << "\nТеперь своё число:\n";
    int number = ReadInt("Целое положительное число: ", 1, 2147483647);
    int base   = ReadInt("Система счисления (2..36): ", 2, 36);
    ConvertToBase(number, base);
    return 0;
}

int ReadInt(const char* prompt, int minValue, int maxValue)
{
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(10000, '\n');
            if (value >= minValue && value <= maxValue) return value;
            cout << "Ошибка: введите число от " << minValue << " до " << maxValue << ".\n";
        } else {
            if (cin.eof()) { cout << "\nВвод завершён.\n"; exit(0); }
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка: введите целое число.\n";
        }
    }
}

void ConvertToBase(int number, int base)
{
    const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char buffer[40];
    int count = 0;
    int n = number;

    while (n > 0) {
        buffer[count] = digits[n % base];
        count++;
        n /= base;
    }

    cout << number << " в системе счисления " << base << " = ";
    for (int i = count - 1; i >= 0; i--)
        cout << buffer[i];
    cout << endl;
}
