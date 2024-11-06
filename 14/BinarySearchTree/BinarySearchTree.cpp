
#include "BinarySearchTree.h"
#include <limits>
#include <cmath>

BinaryTreeNode::BinaryTreeNode(int value) : left(nullptr), right(nullptr), val(value) {}

BinaryTreeNode::~BinaryTreeNode()
{
    delete right;
    delete left;
}

BinarySearchTree::BinarySearchTree() : root(nullptr), nodes_count(0) {}

BinarySearchTree::~BinarySearchTree() { delete root; }

void BinarySearchTree::insert(int value)
{
    auto node{root};

    while (node != nullptr)
    {
        node = (node->val > value) ? node->right : node->left;
    }

    node = new BinaryTreeNode{value};
    nodes_count++;
}

void BinarySearchTree::remove(int value) {}

bool BinarySearchTree::contains(int value)
{
    auto node{root};

    while (node != nullptr)
    {
        if (node->val == value)
        {
            return true;
        }

        node = (node->val > value) ? node->left : node->right;
    }

    return false;
}

int BinarySearchTree::max()
{
    auto node{root};
    auto max_value{std::numeric_limits<int>::quiet_NaN()};

    while (node != nullptr)
    {
        if (node->right != nullptr)
        {
            node = node->right;
        }
        else if (node->left != nullptr)
        {
            node = node->left;
        }
        else
        {
            max_value = node->val;
            break;
        }
    }

    return max_value;
}

int BinarySearchTree::min()
{
    auto node{root};
    auto min_value{std::numeric_limits<int>::quiet_NaN()};

    while (node != nullptr)
    {
        if (node->left != nullptr)
        {
            node = node->left;
        }
        else if (node->right != nullptr)
        {
            node = node->right;
        }
        else
        {
            min_value = node->val;
            break;
        }
    }

    return min_value;
}

int BinarySearchTree::size()
{
    return nodes_count;
}
