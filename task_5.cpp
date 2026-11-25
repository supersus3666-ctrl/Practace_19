#include <iostream>
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

int  ReadInt(const char* prompt, int minValue, int maxValue);
bool IsPrime(int n);

int main()
{
    setlocale(LC_ALL, "Russian");
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    cout << "--- Задание 5: проверка числа на простоту ---\n";
    int n = ReadInt("Целое число (0..2147483647): ", 0, 2147483647);
    if (IsPrime(n)) cout << n << " - простое число\n";
    else            cout << n << " - не простое число\n";
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

bool IsPrime(int n)
{
    if (n < 2) return false;
    for (int i = 2; i <= n / i; i++)
        if (n % i == 0) return false;
    return true;
}
