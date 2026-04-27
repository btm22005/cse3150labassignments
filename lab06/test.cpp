#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest.h"

#include <sstream>
#include "big_fraction.h"

std::string toString(bigint n) {
    std::ostringstream out;
    out << n;
    return out.str();
}

TEST_CASE("multiply small fractions") {
    BigFraction a = {bigint(1), bigint(2)};
    BigFraction b = {bigint(3), bigint(4)};

    BigFraction result = multiplyFractions(a, b);

    CHECK(toString(result.first) == "3");
    CHECK(toString(result.second) == "8");
}

TEST_CASE("add small fractions") {
    BigFraction a = {bigint(1), bigint(2)};
    BigFraction b = {bigint(1), bigint(3)};

    BigFraction result = addFractions(a, b);

    CHECK(toString(result.first) == "5");
    CHECK(toString(result.second) == "6");
}

TEST_CASE("big integer multiplication") {
    BigFraction a = {bigint("100000000000000000000"), bigint(1)};
    BigFraction b = {bigint("100000000000000000000"), bigint(1)};

    BigFraction result = multiplyFractions(a, b);

    CHECK(toString(result.first) == "10000000000000000000000000000000000000000");
    CHECK(toString(result.second) == "1");
}