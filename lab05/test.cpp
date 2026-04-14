#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "cosine.h"

TEST_CASE("cosine distance simple 3D example") {
    std::vector<double> a = {1, 1, 1};
    std::vector<double> b = {1, 1, 0};

    CHECK(cosineDistance(a, b) == doctest::Approx(0.61548).epsilon(0.001));
}

TEST_CASE("pair distances sorted smallest first") {
    std::vector<std::vector<double>> vecs = {
        {1, 1, 1},
        {1, 1, 0},
        {0, 1, 0}
    };

    std::vector<PairDistance> pairs = allPairDistances(vecs);

    CHECK(pairs.size() == 3);
    CHECK(pairs[0].dist <= pairs[1].dist);
    CHECK(pairs[1].dist <= pairs[2].dist);
}