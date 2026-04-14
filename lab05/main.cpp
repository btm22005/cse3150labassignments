#include <iostream>
#include <iomanip>
#include "cosine.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./lab05 vectors.txt\n";
        return 1;
    }

    std::vector<std::vector<double>> vecs = readVectors(argv[1]);
    std::vector<PairDistance> pairs = allPairDistances(vecs);

    for (const auto& p : pairs) {
        std::cout << p.i << " " << p.j
                  << " cos dist = "
                  << std::fixed << std::setprecision(6)
                  << p.dist << "\n";
    }

    return 0;
}