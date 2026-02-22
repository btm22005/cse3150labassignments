#ifndef _NODE_H
#define _NODE_H

struct Node {
    int data;
    Node* next;
    Node* jump;   // for pointer jumping

    Node() : data{0}, next{this}, jump{nullptr} {}
    Node(int _data) : data{_data}, next{this}, jump{nullptr} {}
};

#endif