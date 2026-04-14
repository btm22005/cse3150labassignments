#include "cosine.h"
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>

std::vector<std::vector<double>> readVectors(const std::string& filename) {
    std::ifstream in(filename);
    std::vector<std::vector<double>> vecs;
    std::string line;

    while (std::getline(in, line)) {
        std::istringstream iss(line);
        std::vector<double> v;
        double x;
        while (iss >> x) v.push_back(x);
        if (!v.empty()) vecs.push_back(v);
    }
    return vecs;
}

double cosineDistance(const std::vector<double>& a, const std::vector<double>& b) {
    double dot = 0.0, magA = 0.0, magB = 0.0;

    for (size_t i = 0; i < a.size(); i++) {
        dot += a[i] * b[i];
        magA += a[i] * a[i];
        magB += b[i] * b[i];
    }

    double denom = std::sqrt(magA) * std::sqrt(magB);
    if (denom == 0.0) return 0.0;

    double val = dot / denom;
    if (val > 1.0) val = 1.0;
    if (val < -1.0) val = -1.0;

    return std::acos(val);
}

std::vector<PairDistance> allPairDistances(const std::vector<std::vector<double>>& vecs) {
    std::vector<PairDistance> pairs;

    for (int i = 0; i < (int)vecs.size(); i++) {
        for (int j = i + 1; j < (int)vecs.size(); j++) {
            pairs.push_back({i, j, cosineDistance(vecs[i], vecs[j])});
        }
    }

    std::sort(pairs.begin(), pairs.end(),
        [](const PairDistance& a, const PairDistance& b) {
            return a.dist < b.dist;
        });

    return pairs;
}