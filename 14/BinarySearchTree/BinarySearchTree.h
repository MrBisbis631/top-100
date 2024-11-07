#pragma once

class BinarySearchTree
{
    class Node
    {
    public:
        int value;
        Node *left{nullptr};
        Node *right{nullptr};

        Node(int);
        ~Node();
    };

    Node *root{nullptr};
    int nodes_count;

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int);
    bool contains(int);
    void remove(int);
    int max() const;
    int min() const;
    int size() const;
};
