/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {

        // we have to swap them only if the root exists
        if (root != nullptr)
        {

            // so post order = left right then visit, we need that here as we swap in that order.
            invertTree(root->left);
            invertTree(root->right);
            TreeNode *tmp = root->left;
            root->left = root->right;
            root->right = tmp;
        }

        return root;
    }
};