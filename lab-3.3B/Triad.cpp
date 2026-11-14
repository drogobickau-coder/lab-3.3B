#include "Triad.h"
#include <sstream>
#pragma execution_character_set("utf-8")


Triad::Triad() : first(0), second(0), third(0) {}

Triad::Triad(double f, double s, double t) : first(f), second(s), third(t) {}

Triad::Triad(const Triad& other) : first(other.first), second(other.second), third(other.third) {}

Triad& Triad::operator=(const Triad& other) {
    if (this != &other) {
        first = other.first;
        second = other.second;
        third = other.third;
    }
    return *this;
}

Triad::operator string() const {
    stringstream ss;
    ss << "[" << first << ", " << second << ", " << third << "]";
    return ss.str();
}

// Реалізація логіки порівняння за умовою завдання
bool operator>(const Triad& t1, const Triad& t2) {
    return (t1.first > t2.first) ||
        (t1.first == t2.first && t1.second > t2.second) ||
        (t1.first == t2.first && t1.second == t2.second && t1.third > t2.third);
}

bool operator==(const Triad& t1, const Triad& t2) {
    return (t1.first == t2.first && t1.second == t2.second && t1.third == t2.third);
}

bool operator<(const Triad& t1, const Triad& t2) {
    return !(t1 > t2) && !(t1 == t2);
}

bool operator!=(const Triad& t1, const Triad& t2) {
    return !(t1 == t2);
}

bool operator>=(const Triad& t1, const Triad& t2) {
    return (t1 > t2) || (t1 == t2);
}

bool operator<=(const Triad& t1, const Triad& t2) {
    return (t1 < t2) || (t1 == t2);
}

// Збільшуємо/зменшуємо перше поле (як варіант логіки інкременту)
Triad& Triad::operator++() {
    ++first;
    return *this;
}

Triad Triad::operator++(int) {
    Triad temp(*this);
    ++first;
    return temp;
}

Triad& Triad::operator--() {
    --first;
    return *this;
}

Triad Triad::operator--(int) {
    Triad temp(*this);
    --first;
    return temp;
}

ostream& operator<<(ostream& out, const Triad& t) {
    out << string(t);
    return out;
}

istream& operator>>(istream& in, Triad& t) {
    cout << "Введіть first (x): "; in >> t.first;
    cout << "Введіть second (l >= 0): "; in >> t.second;
    cout << "Введіть third (r >= 0): "; in >> t.third;
    return in;
}