#include "FuzzyNumber.h"
#include <sstream>
#pragma execution_character_set("utf-8")

// Виклик базових конструкторів
FuzzyNumber::FuzzyNumber() : Triad() {}

FuzzyNumber::FuzzyNumber(double x, double l, double r) : Triad(x, l, r) {
    if (l < 0) second = 0;
    if (r < 0) third = 0;
}

FuzzyNumber::FuzzyNumber(const FuzzyNumber& other) : Triad(other) {}

FuzzyNumber& FuzzyNumber::operator=(const FuzzyNumber& other) {
    Triad::operator=(other); // Виклик присвоєння базового класу
    return *this;
}

FuzzyNumber::operator string() const {
    stringstream ss;
    // Вивід у форматі (x-l, x, x+r)
    ss << "(" << (first - second) << ", " << first << ", " << (first + third) << ")";
    return ss.str();
}

FuzzyNumber operator-(const FuzzyNumber& a, const FuzzyNumber& b) {
    FuzzyNumber t;
    t.first = a.first - b.first;
    t.second = a.second + b.second;
    t.third = a.third + b.third;
    return t;
}

FuzzyNumber operator/(const FuzzyNumber& a, const FuzzyNumber& b) {
    FuzzyNumber t;
    if (b.first > 0) {
        t.first = a.first / b.first;
        t.second = t.first - ((a.first - a.second) / (b.first + b.third));
        t.third = ((a.first + a.third) / (b.first - b.second)) - t.first;
    }
    else {
        cout << "Помилка: Ділення неможливе, x_B <= 0." << endl;
    }
    return t;
}

FuzzyNumber operator/(double numerator, const FuzzyNumber& a) {
    FuzzyNumber t;
    if (numerator == 1.0 && a.first > 0) {
        t.first = 1.0 / a.first;
        t.second = t.first - (1.0 / (a.first + a.third));
        t.third = (1.0 / (a.first - a.second)) - t.first;
    }
    else {
        cout << "Помилка: x_A має бути > 0 для обчислення оберненого числа." << endl;
    }
    return t;
}