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
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum, bool is_root_tree = true)
    {
        if (root == NULL)
        {
            if (is_root_tree)
            {
                return false;
            }

            return targetSum == 0;
        }

        if (root->left == NULL)
        {
            return hasPathSum(root->right, targetSum - root->val, false);
        }

        if (root->right == NULL)
        {
            return hasPathSum(root->left, targetSum - root->val, false);
        }

        return hasPathSum(root->left, targetSum - root->val, false) ||
               hasPathSum(root->right, targetSum - root->val, false);
    }
};