#ifndef BIG_FRACTION_H
#define BIG_FRACTION_H

#include <utility>
#include "bigint class.h"

using BigFraction = std::pair<bigint, bigint>;

inline BigFraction multiplyFractions(BigFraction a, BigFraction b) {
    return {a.first * b.first, a.second * b.second};
}

inline BigFraction addFractions(BigFraction a, BigFraction b) {
    bigint numerator = (a.first * b.second) + (b.first * a.second);
    bigint denominator = a.second * b.second;
    return {numerator, denominator};
}

#endif