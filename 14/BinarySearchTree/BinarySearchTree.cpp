
#include "BinarySearchTree.h"
#include <limits>
#include <cmath>
#include <stdexcept>

/** ----------------------------
 * Node inner class helper
 * ----------------------------- */

BinarySearchTree::Node::Node(int value) : value{value}, left{nullptr}, right{nullptr} {}

BinarySearchTree::Node::~Node()
{
    delete left;
    delete right;
}

/** ----------------------------
 * tree implementation
 * ----------------------------- */

BinarySearchTree::BinarySearchTree() : root{nullptr}, nodes_count{0} {}

BinarySearchTree::~BinarySearchTree() { delete root; }

void BinarySearchTree::insert(int value)
{
    if (root == nullptr)
    {
        root = new BinarySearchTree::Node{value};
    }
    else
    {
        auto node{root};
        BinarySearchTree::Node *parent{nullptr};

        while (node != nullptr)
        {
            parent = node;
            node = node->value > value ? node->left : node->right;
        }

        if (parent->value > value)
        {
            parent->left = new BinarySearchTree::Node{value};
        }
        else
        {
            parent->right = new BinarySearchTree::Node{value};
        }
    }
    nodes_count++;
}

bool BinarySearchTree::contains(int value)
{
    auto node{root};
    while (node != nullptr)
    {
        if (node->value == value)
        {
            return true;
        }
        node = node->value > value ? node->left : node->right;
    }
    return false;
}

void BinarySearchTree::remove(int value)
{
    Node *node = root;
    Node *parent = nullptr;

    while (node != nullptr && node->value != value)
    {
        parent = node;
        if (value < node->value)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }

    if (node == nullptr)
    {
        return; // Value not found
    }

    if (node->left == nullptr || node->right == nullptr)
    {
        Node *new_child = node->left ? node->left : node->right;

        if (parent == nullptr)
        {
            root = new_child;
        }
        else if (parent->left == node)
        {
            parent->left = new_child;
        }
        else
        {
            parent->right = new_child;
        }

        delete node;
    }
    else
    {
        Node *successor_parent = node;
        Node *successor = node->right;

        while (successor->left != nullptr)
        {
            successor_parent = successor;
            successor = successor->left;
        }

        node->value = successor->value;

        if (successor_parent->left == successor)
        {
            successor_parent->left = successor->right;
        }
        else
        {
            successor_parent->right = successor->right;
        }

        delete successor;
    }

    nodes_count--;
}

int BinarySearchTree::max() const
{
    if (root == nullptr)
    {
        throw std::runtime_error("Tree is empty");
    }

    Node *node = root;
    while (node->right != nullptr)
    {
        node = node->right;
    }
    return node->value;
}

int BinarySearchTree::min() const
{
    if (root == nullptr)
    {
        throw std::runtime_error("Tree is empty");
    }

    Node *node = root;
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node->value;
}

int BinarySearchTree::size() const
{
    return nodes_count;
}
