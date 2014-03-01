#ifndef FRACTION_H
#define FRACTION_H

#include <ostream>

class Fraction {
    friend std::ostream& operator<<(std::ostream& os, Fraction const& f);
    friend Fraction operator+(Fraction const& lhs, Fraction const& rhs);
    friend bool operator==(Fraction const& lhs, Fraction const& rhs);
public:
    Fraction() : Fraction(0, 1) {}
    Fraction(int num, int denom);

private:
    int numerator_;
    int denominator_;

    void toLowestTerms();
};

#endif
