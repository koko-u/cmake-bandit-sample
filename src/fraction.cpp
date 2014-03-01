#include <ostream>
using namespace std;

#include "fraction.h"
#include "mathlib.h"

Fraction::Fraction(int num, int denom)
    : numerator_(num), denominator_(denom) {
    if (denominator_ < 0) {
        numerator_ *= -1;
        denominator_ *= -1;
    }
    toLowestTerms();
}

void Fraction::toLowestTerms() {
    int gcd = Mathlib::gcd(numerator_, denominator_);
    numerator_ /= gcd;
    denominator_ /= gcd;
}

ostream& operator<<(ostream& os, Fraction const& f) {
    os << f.numerator_ << "/" << f.denominator_;
    return os;
}

Fraction operator+(Fraction const& lhs, Fraction const& rhs) {
    return Fraction(lhs.numerator_ * rhs.denominator_ + rhs.numerator_ * lhs.denominator_,
                    lhs.denominator_ * rhs.denominator_);
}

bool operator==(Fraction const& lhs, Fraction const& rhs) {
    return lhs.numerator_ * rhs.denominator_ == rhs.numerator_ * lhs.denominator_;
}
