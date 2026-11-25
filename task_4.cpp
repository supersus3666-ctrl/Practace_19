#include <iostream>
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

int ReadInt(const char* prompt, int minValue, int maxValue);
unsigned long long Factorial(int n);

int main()
{
    setlocale(LC_ALL, "Russian");
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    cout << "--- Задание 4: факториал ---\n";
    cout << "(n не больше 20: 21! не помещается в unsigned long long)\n";
    int n = ReadInt("n (0..20): ", 0, 20);
    cout << n << "! = " << Factorial(n) << endl;
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

unsigned long long Factorial(int n)
{
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}
