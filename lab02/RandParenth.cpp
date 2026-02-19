#include "RandParenth.h"
#include <algorithm>
#include <random>

std::vector<int> generateList(int n) {
    std::vector<int> lst(2 * n);
    for (int i = 0; i < n; i++) lst[i] = 1;
    for (int i = n; i < 2 * n; i++) lst[i] = -1;
    return lst;
}

void shuffleList(std::vector<int>& lst) {
    static std::mt19937 rng(std::random_device{}());
    for (int i = lst.size() - 1; i > 0; i--) {
        std::uniform_int_distribution<int> dist(0, i);
        int j = dist(rng);
        std::swap(lst[i], lst[j]);
    }
}

bool nonNegativePrefix(const std::vector<int>& lst) {
    int sum = 0;
    for (int x : lst) {
        sum += x;
        if (sum < 0) return false;
    }
    return true;
}

int countValidSequences(int n, int trials) {
    int count = 0;
    for (int t = 0; t < trials; t++) {
        std::vector<int> lst = generateList(n);
        shuffleList(lst);
        if (nonNegativePrefix(lst))
            count++;
    }
    return count;
}
