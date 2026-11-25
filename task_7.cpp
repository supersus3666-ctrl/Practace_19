#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

int  ReadInt(const char* prompt, int minValue, int maxValue);
void InitArray(int arr[], int size);
void ShowArray(int arr[], int size);
void ReverseArray(int arr[], int size);

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    if (argc > 1) srand(atoi(argv[1]));
    else          srand((unsigned)time(NULL));

    cout << "--- Задание 7: обращение порядка элементов массива ---\n";
    int size = ReadInt("Размер массива (1..30): ", 1, 30);
    int arr[30];
    InitArray(arr, size);
    cout << "До:\n";
    ShowArray(arr, size);

    ReverseArray(arr, size);
    cout << "После:\n";
    ShowArray(arr, size);
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

void ReverseArray(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}
