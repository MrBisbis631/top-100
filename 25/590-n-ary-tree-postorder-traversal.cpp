/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#include <algorithm>
#include <vector>

class Solution
{
    std::vector<int> res;

    void inner_postorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        std::for_each(root->children.begin(), root->children.end(),
                      [this](auto c)
                      { inner_postorder(c); });

        res.push_back(root->val);
    }

public:
    std::vector<int> postorder(Node *root)
    {
        res.clear();
        inner_postorder(root);
        return res;
    }
};