#include <iostream>
#include <vector>
#include "linked_list.h"

using namespace std;

LinkedList::LinkedList() : root{nullptr} {}

void LinkedList::insertInFront(int _data) {
    Node* insertNode = new Node(_data);
    if (root) insertNode->next = root;
    root = insertNode;
}

// copy constructor (deep copy, preserves order)
LinkedList::LinkedList(const LinkedList& other) : root{nullptr} {
    vector<int> vals;
    Node* cur = other.root;
    while (cur && cur->next != cur) {
        vals.push_back(cur->data);
        cur = cur->next;
    }
    if (cur && cur->next == cur) vals.push_back(cur->data);

    // insert in reverse to preserve original order
    for (int i = (int)vals.size() - 1; i >= 0; --i) {
        insertInFront(vals[i]);
    }
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this == &other) return *this;

    // clear current
    this->~LinkedList();
    root = nullptr;

    // deep copy
    vector<int> vals;
    Node* cur = other.root;
    while (cur && cur->next != cur) {
        vals.push_back(cur->data);
        cur = cur->next;
    }
    if (cur && cur->next == cur) vals.push_back(cur->data);

    for (int i = (int)vals.size() - 1; i >= 0; --i) {
        insertInFront(vals[i]);
    }
    return *this;
}

LinkedList::~LinkedList() {
    if (!root) return;

    Node* current = root;
    while (current && current->next != current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    if (current && current->next == current) {
        delete current;
    }
}

void LinkedList::traverseList() {
    Node* current = root;
    while (current && current->next != current) {
        cout << static_cast<void*>(current) << " next: " << static_cast<void*>(current->next) << endl;
        current = current->next;
    }
    if (current && current->next == current) {
        cout << static_cast<void*>(current) << " next: " << static_cast<void*>(current->next) << endl;
    }
}

ostream& operator<<(ostream& os, const Node& node) {
    os << node.data;
    return os;
}

ostream& operator<<(ostream& os, const LinkedList& linkelist) {
    Node* traversal = linkelist.root;

    while (traversal && traversal != traversal->next) {
        os << *traversal << " ";
        traversal = traversal->next;
    }
    if (traversal && traversal == traversal->next) {
        os << *traversal;
    }
    return os;
}

// 3) delete ith node (0-index). return false if out of range.
bool LinkedList::deleteIth(int i) {
    if (!root || i < 0) return false;

    // delete head
    if (i == 0) {
        Node* old = root;
        if (root->next == root) {
            root = nullptr;          // single node list
        } else {
            root = root->next;
        }
        delete old;
        return true;
    }

    Node* prev = root;
    int idx = 0;

    // move prev to node (i-1)
    while (prev && prev->next != prev && idx < i - 1) {
        prev = prev->next;
        idx++;
    }

    // if we hit end early
    if (!prev || prev->next == prev) return false;

    Node* victim = prev->next;

    // if victim is last node (self-loop)
    if (victim->next == victim) {
        prev->next = prev;   // prev becomes new last
    } else {
        prev->next = victim->next;
    }

    delete victim;
    return true;
}

// 5) prefix sum checks (assumes data is -1/+1)
bool LinkedList::nonNegativePrefixSum() const {
    int sum = 0;
    Node* cur = root;

    while (cur && cur->next != cur) {
        sum += cur->data;
        if (sum < 0) return false;
        cur = cur->next;
    }
    if (cur && cur->next == cur) {
        sum += cur->data;
        if (sum < 0) return false;
    }
    return true;
}

bool LinkedList::nonPositivePrefixSum() const {
    int sum = 0;
    Node* cur = root;

    while (cur && cur->next != cur) {
        sum += cur->data;
        if (sum > 0) return false;
        cur = cur->next;
    }
    if (cur && cur->next == cur) {
        sum += cur->data;
        if (sum > 0) return false;
    }
    return true;
}

// 6) pointer jumping on the given list (no copying)
void LinkedList::initJumpPointers() {
    Node* cur = root;
    while (cur && cur->next != cur) {
        cur->jump = cur->next;
        cur = cur->next;
    }
    if (cur && cur->next == cur) {
        cur->jump = nullptr; // last node
    }
}

void LinkedList::pointerJump(int rounds) {
    for (int r = 0; r < rounds; r++) {
        Node* cur = root;
        while (cur) {
            if (cur->jump && cur->jump->jump) cur->jump = cur->jump->jump;
            else cur->jump = nullptr;

            if (cur->next == cur) break;
            cur = cur->next;
        }
    }
}