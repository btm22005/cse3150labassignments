#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>
#include "Node.h"

class LinkedList {
    friend std::ostream& operator<<(std::ostream& os, const LinkedList& linkelist);

    Node* root;

public:
    LinkedList();
    LinkedList(const LinkedList& other);     // copy constructor
    LinkedList& operator=(const LinkedList& other);
    ~LinkedList();

    void insertInFront(int _data);
    void traverseList();

    bool deleteIth(int i);                   // deletes 0-indexed ith node
    bool nonNegativePrefixSum() const;       // never goes below 0
    bool nonPositivePrefixSum() const;       // never goes above 0

    void initJumpPointers();                 // jump = next (or nullptr at end)
    void pointerJump(int rounds);            // jump = jump->jump for rounds
};

#endif