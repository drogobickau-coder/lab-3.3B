#pragma once
#include "Triad.h"

// Відкрите успадкування від Triad
class FuzzyNumber : public Triad {
public:
    FuzzyNumber();
    FuzzyNumber(double x, double l, double r);
    FuzzyNumber(const FuzzyNumber& other);

    FuzzyNumber& operator=(const FuzzyNumber& other);

    // Перевизначення методу приведення до рядка під специфіку нечітких чисел (x-l, x, x+r)
    operator string() const;

    // Специфічні операції з варіанту
    friend FuzzyNumber operator-(const FuzzyNumber& a, const FuzzyNumber& b);
    friend FuzzyNumber operator/(const FuzzyNumber& a, const FuzzyNumber& b);
    friend FuzzyNumber operator/(double numerator, const FuzzyNumber& a); // Обернене число

    // Функції вводу/виводу НЕ визначаються (успадковано від базового класу)
};