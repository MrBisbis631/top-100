#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    std::vector<int> result;

    void innerInorderTraversal(TreeNode* node) {
        if (node == NULL) {
            return;
        }

        innerInorderTraversal(node->left);
        result.push_back(node->val);
        innerInorderTraversal(node->right);
    }

public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        result = {};
        innerInorderTraversal(root);
        return result;
    }
};
