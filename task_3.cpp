#include <iostream>
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

int  ReadInt(const char* prompt, int minValue, int maxValue);
void PrintRectangle(int height, int width, char symbol = '*', bool filled = true);

int main()
{
    setlocale(LC_ALL, "Russian");
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    cout << "--- Задание 3: прямоугольник ---\n";
    int n = ReadInt("Высота N (1..30): ", 1, 30);
    int k = ReadInt("Ширина K (1..70): ", 1, 70);
    cout << "\nЗаполненный прямоугольник (символ по умолчанию):\n";
    PrintRectangle(n, k);
    cout << "\nТолько рамка, символ '#':\n";
    PrintRectangle(n, k, '#', false);
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

void PrintRectangle(int height, int width, char symbol, bool filled)
{
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            bool border = (row == 0 || row == height - 1 || col == 0 || col == width - 1);
            if (filled || border) cout << symbol;
            else                  cout << ' ';
        }
        cout << endl;
    }
}
