#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

int g_minValue, g_minIndex, g_maxValue, g_maxIndex;

int  ReadInt(const char* prompt, int minValue, int maxValue);
void InitArray(int arr[], int size);
void ShowArray(int arr[], int size);
void FindMinMax(int arr[], int size);

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    if (argc > 1) srand(atoi(argv[1]));
    else          srand((unsigned)time(NULL));

    cout << "--- Задание 6: минимум и максимум массива ---\n";
    int size = ReadInt("Размер массива (1..30): ", 1, 30);
    int arr[30];
    InitArray(arr, size);
    cout << "Массив:\n";
    ShowArray(arr, size);

    FindMinMax(arr, size);
    cout << "Минимум = " << g_minValue << ", индекс " << g_minIndex
         << " (позиция " << g_minIndex + 1 << ")\n";
    cout << "Максимум = " << g_maxValue << ", индекс " << g_maxIndex
         << " (позиция " << g_maxIndex + 1 << ")\n";
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

void InitArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 101 - 50;
}

void ShowArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << arr[i];
    cout << endl;
}

void FindMinMax(int arr[], int size)
{
    g_minValue = g_maxValue = arr[0];
    g_minIndex = g_maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < g_minValue) { g_minValue = arr[i]; g_minIndex = i; }
        if (arr[i] > g_maxValue) { g_maxValue = arr[i]; g_maxIndex = i; }
    }
}
