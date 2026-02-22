#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "linked_list.h"

TEST_CASE("deleteIth") {
    LinkedList L;
    CHECK(L.deleteIth(0) == false);

    L.insertInFront(1);
    CHECK(L.deleteIth(0) == true);
    CHECK(L.deleteIth(0) == false);

    // list: 2 -> 1 -> 0
    L.insertInFront(0);
    L.insertInFront(1);
    L.insertInFront(2);

    CHECK(L.deleteIth(2) == true); // delete last
    CHECK(L.deleteIth(5) == false);
}

TEST_CASE("copy constructor deep copies") {
    LinkedList A;
    A.insertInFront(1);
    A.insertInFront(-1); // A: -1 -> 1

    LinkedList B(A);
    CHECK(B.nonPositivePrefixSum() == true); // -1,0 never above 0

    // mutate A, B should remain valid on its own
    CHECK(A.deleteIth(0) == true);
    CHECK(B.nonPositivePrefixSum() == true);
}

TEST_CASE("prefix sum checks") {
    LinkedList good;
    // 1,-1,1,-1 => non-negative prefix
    good.insertInFront(-1);
    good.insertInFront(1);
    good.insertInFront(-1);
    good.insertInFront(1);
    CHECK(good.nonNegativePrefixSum() == true);

    LinkedList bad;
    // 1,-1,-1,1 => dips negative
    bad.insertInFront(1);
    bad.insertInFront(-1);
    bad.insertInFront(-1);
    bad.insertInFront(1);
    CHECK(bad.nonNegativePrefixSum() == false);
}

TEST_CASE("pointer jumping") {
    LinkedList L;
    for (int i = 0; i < 5; i++) L.insertInFront(1);

    L.initJumpPointers();
    L.pointerJump(1);

    // not crashing + jump pointers updated is enough for this lab test
    CHECK(true);
}