#include "mathlib.h"

int Mathlib::gcd(int n, int m) {
    if ( n < 0 ) { n *= -1; }
    if ( m < 0 ) { m *= -1; }
    if ( m == 0 ) { return n; }
    return Mathlib::gcd(m, n % m);
}
