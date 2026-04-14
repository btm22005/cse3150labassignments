#ifndef COSINE_H
#define COSINE_H

#include <vector>
#include <string>

struct PairDistance {
    int i;
    int j;
    double dist;
};

std::vector<std::vector<double>> readVectors(const std::string& filename);
double cosineDistance(const std::vector<double>& a, const std::vector<double>& b);
std::vector<PairDistance> allPairDistances(const std::vector<std::vector<double>>& vecs);

#endif