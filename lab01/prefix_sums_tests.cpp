#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "prefix_sums.h"

TEST_CASE("non_neg_prefix_sum") {
    int empty[] = {};
    CHECK(non_neg_prefix_sum(empty, 0) == true);

    int ok[]  = { 1, -1,  1, -1 };
    int bad[] = { 1, -1, -1,  1 };
    CHECK(non_neg_prefix_sum(ok, 4) == true);
    CHECK(non_neg_prefix_sum(bad, 4) == false);

    int starts_bad[] = { -1 };
    CHECK(non_neg_prefix_sum(starts_bad, 1) == false);
}

TEST_CASE("non_pos_prefix_sum") {
    int empty[] = {};
    CHECK(non_pos_prefix_sum(empty, 0) == true);

    int ok[]  = { -1,  1, -1,  1 };
    int bad[] = { -1,  1,  1, -1 };
    CHECK(non_pos_prefix_sum(ok, 4) == true);
    CHECK(non_pos_prefix_sum(bad, 4) == false);

    int starts_bad[] = { 1 };
    CHECK(non_pos_prefix_sum(starts_bad, 1) == false);
}
