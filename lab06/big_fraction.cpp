#include "big_fraction.h"

BigFraction multiplyFractions(BigFraction a, BigFraction b) {
    return {a.first * b.first, a.second * b.second};
}

BigFraction addFractions(BigFraction a, BigFraction b) {
    bigint numerator = (a.first * b.second) + (b.first * a.second);
    bigint denominator = a.second * b.second;

    return {numerator, denominator};
}