#pragma once

class BinaryTreeNode;

class BinarySearchTree
{
private:
    BinaryTreeNode *root;
    int nodes_count;

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int);
    void remove(int);
    bool contains(int);
    int max();
    int min();
    int size();
};

class BinaryTreeNode
{
public:
    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int);
    ~BinaryTreeNode();
};
