#ifndef RANDPARENTH_H
#define RANDPARENTH_H

#include <vector>

// Generate list: n ones followed by n minus ones
std::vector<int> generateList(int n);

// Fisher-Yates shuffle
void shuffleList(std::vector<int>& lst);

// Check that prefix sums never go negative
bool nonNegativePrefix(const std::vector<int>& lst);

// Run experiment for given trials
int countValidSequences(int n, int trials);

#endif
