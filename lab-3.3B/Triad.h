#pragma once
#include <iostream>
#include <string>

using namespace std;

class Triad {
protected:
    double first;  // Для FuzzyNumber це буде x
    double second; // Для FuzzyNumber це буде l
    double third;  // Для FuzzyNumber це буде r

public:
    Triad();
    Triad(double f, double s, double t);
    Triad(const Triad& other);

    double getFirst() const { return first; }
    double getSecond() const { return second; }
    double getThird() const { return third; }

    void setFirst(double f) { first = f; }
    void setSecond(double s) { second = s; }
    void setThird(double t) { third = t; }

    Triad& operator=(const Triad& other);

    // Перетворення до літерного рядка
    operator string() const;

    // Операції порівняння
    friend bool operator>(const Triad& t1, const Triad& t2);
    friend bool operator<(const Triad& t1, const Triad& t2);
    friend bool operator==(const Triad& t1, const Triad& t2);
    friend bool operator!=(const Triad& t1, const Triad& t2);
    friend bool operator>=(const Triad& t1, const Triad& t2);
    friend bool operator<=(const Triad& t1, const Triad& t2);

    // Інкремент і декремент
    Triad& operator++();    // Префіксний
    Triad operator++(int);  // Постфіксний
    Triad& operator--();    // Префіксний
    Triad operator--(int);  // Постфіксний

    // Введення/виведення (тільки у базовому класі!)
    friend ostream& operator<<(ostream& out, const Triad& t);
    friend istream& operator>>(istream& in, Triad& t);
};