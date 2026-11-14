#include "FuzzyNumber.h"
#include <iostream>
#include <windows.h>
#pragma execution_character_set("utf-8")

using namespace std;

// Структура для демонстрації розміру з #pragma pack(1)
#pragma pack(push, 1)
struct FuzzyNumberPacked {
    double x;
    double l;
    double r;
};
#pragma pack(pop)

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    cout << "--- Демонстрація розміру класу ---" << endl;
    cout << "Розмір базового класу Triad: " << sizeof(Triad) << " байт" << endl;
    cout << "Розмір похідного класу FuzzyNumber: " << sizeof(FuzzyNumber) << " байт" << endl;
    cout << "Розмір з #pragma pack(1): " << sizeof(FuzzyNumberPacked) << " байт\n" << endl;

    // --- Робота з базовим класом ---
    Triad t1(10, 2, 3), t2;
    cout << "Базовий клас Triad (t1): " << t1 << endl;
    t2 = ++t1;
    cout << "Після префіксного інкременту (t2 = ++t1): " << t2 << endl;

    // --- Робота з похідним класом (Принцип підстановки та успадкований ввід) ---
    FuzzyNumber a, b(20, 4, 6);

    cout << "\nІніціалізація числа A (FuzzyNumber через успадкований cin >>):" << endl;
    cin >> a;

    // Виклик перевизначеного приведення до рядка
    cout << "\nЧисло A: " << string(a) << endl;
    cout << "Число B: " << string(b) << endl;

    // Порівняння (успадковано від Triad)
    if (a > b) cout << "A більше ніж B" << endl;
    else cout << "A не більше ніж B" << endl;

    // Математичні операції (FuzzyNumber)
    cout << "\n--- Арифметичні операції ---" << endl;
    FuzzyNumber c = a - b;
    cout << "A - B = " << string(c) << endl;

    FuzzyNumber d = a / b;
    cout << "A / B = " << string(d) << endl;

    FuzzyNumber inv = 1.0 / a;
    cout << "1 / A = " << string(inv) << endl;

    // Демонстрація масиву об'єктів
    cout << "\n--- Масив об'єктів FuzzyNumber ---" << endl;
    FuzzyNumber* arr = new FuzzyNumber[2];
    arr[0] = a;
    arr[1] = b;
    for (int i = 0; i < 2; i++) {
        cout << "arr[" << i << "] = " << string(arr[i]) << endl;
    }
    delete[] arr;

    return 0;
}