#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "RandParenth.h"

TEST_CASE("generateList produces correct counts") {
    auto lst = generateList(3);
    CHECK(lst.size() == 6);

    int ones = 0, negs = 0;
    for (int x : lst) {
        if (x == 1) ones++;
        if (x == -1) negs++;
    }
    CHECK(ones == 3);
    CHECK(negs == 3);
}

TEST_CASE("nonNegativePrefix basic cases") {
    std::vector<int> good = {1, -1, 1, -1};
    std::vector<int> bad  = {1, -1, -1, 1};

    CHECK(nonNegativePrefix(good) == true);
    CHECK(nonNegativePrefix(bad) == false);
}

TEST_CASE("countValidSequences runs") {
    int valid = countValidSequences(3, 100);
    CHECK(valid >= 0);
}
