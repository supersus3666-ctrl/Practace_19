#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

const int ROUNDS = 5;

int  ReadInt(const char* prompt, int minValue, int maxValue);
void WaitEnter();
int  RollDie();
void DrawDice(int first, int second);
int  MakeThrow(const char* who, bool isHuman);
int  Sum(int arr[], int size);
double Average(int arr[], int size);
void ShowResults(int human[], int computer[], int rounds);

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    if (argc > 1) srand(atoi(argv[1]));
    else          srand((unsigned)time(NULL));

    cout << "--- Задание 2: игра «кубики» (по " << ROUNDS << " бросков, 2 кубика за бросок) ---\n";
    cout << "Кто ходит первым?\n1 - Человек\n2 - Компьютер\n3 - Случайно\n";
    int first = ReadInt("Ваш выбор: ", 1, 3);
    if (first == 3) {
        first = rand() % 2 + 1;
        cout << "Жребий: " << (first == 1 ? "первым ходите вы" : "первым ходит компьютер") << endl;
    }

    int human[ROUNDS], computer[ROUNDS];
    for (int round = 0; round < ROUNDS; round++) {
        cout << "\n----- Раунд " << (round + 1) << " из " << ROUNDS << " -----";
        if (first == 1) {
            human[round]    = MakeThrow("Человек", true);
            computer[round] = MakeThrow("Компьютер", false);
        } else {
            computer[round] = MakeThrow("Компьютер", false);
            human[round]    = MakeThrow("Человек", true);
        }
    }
    ShowResults(human, computer, ROUNDS);
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

void WaitEnter()
{
    cout << "Нажмите Enter, чтобы бросить кубики...";
    cin.get();
}

int RollDie()
{
    return rand() % 6 + 1;
}

void DrawDice(int first, int second)
{
    const char* FACE[7][5] = {
        { "", "", "", "", "" },
        { "+-------+", "|       |", "|   o   |", "|       |", "+-------+" },
        { "+-------+", "| o     |", "|       |", "|     o |", "+-------+" },
        { "+-------+", "| o     |", "|   o   |", "|     o |", "+-------+" },
        { "+-------+", "| o   o |", "|       |", "| o   o |", "+-------+" },
        { "+-------+", "| o   o |", "|   o   |", "| o   o |", "+-------+" },
        { "+-------+", "| o   o |", "| o   o |", "| o   o |", "+-------+" }
    };
    for (int line = 0; line < 5; line++)
        cout << "  " << FACE[first][line] << "  " << FACE[second][line] << endl;
}

int MakeThrow(const char* who, bool isHuman)
{
    cout << "\n" << who << " бросает:\n";
    if (isHuman) WaitEnter();
    int a = RollDie();
    int b = RollDie();
    DrawDice(a, b);
    cout << "  Сумма: " << a << " + " << b << " = " << (a + b) << endl;
    return a + b;
}

int Sum(int arr[], int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
        s += arr[i];
    return s;
}

double Average(int arr[], int size)
{
    return (double)Sum(arr, size) / size;
}

void ShowResults(int human[], int computer[], int rounds)
{
    cout << "\n============ ИТОГИ ============\n";
    cout << "Бросок     ";
    for (int i = 0; i < rounds; i++) cout << setw(4) << (i + 1);
    cout << "   Всего  Среднее\n";

    cout << "Человек    ";
    for (int i = 0; i < rounds; i++) cout << setw(4) << human[i];
    cout << setw(8) << Sum(human, rounds)
         << setw(9) << fixed << setprecision(2) << Average(human, rounds) << endl;

    cout << "Компьютер  ";
    for (int i = 0; i < rounds; i++) cout << setw(4) << computer[i];
    cout << setw(8) << Sum(computer, rounds)
         << setw(9) << fixed << setprecision(2) << Average(computer, rounds) << endl;

    int h = Sum(human, rounds);
    int c = Sum(computer, rounds);
    if (h > c)      cout << "\nВы победили! (" << h << " : " << c << ")\n";
    else if (c > h) cout << "\nПобедил компьютер! (" << c << " : " << h << ")\n";
    else            cout << "\nНичья! (" << h << " : " << c << ")\n";
}
