#include "prefix_sums.h"

bool non_neg_prefix_sum(const int* lst, int n) {
    // Edge case: empty list -> prefix sums are just {0}, which is not below 0
    if (n <= 0) return true;

    int sum = 0; // prefix sum starts at 0 (as shown in the example)
    for (int i = 0; i < n; i++) {
        sum += lst[i];
        if (sum < 0) return false;
    }
    return true;
}

bool non_pos_prefix_sum(const int* lst, int n) {
    if (n <= 0) return true;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += lst[i];
        if (sum > 0) return false;
    }
    return true;
}