#ifndef PREFIX_SUMS_H
#define PREFIX_SUMS_H

// Returns true if ALL prefix sums (including the initial 0) never go below 0.
bool non_neg_prefix_sum(const int* lst, int n);

// Returns true if ALL prefix sums (including the initial 0) never go above 0..
bool non_pos_prefix_sum(const int* lst, int n);

#endif