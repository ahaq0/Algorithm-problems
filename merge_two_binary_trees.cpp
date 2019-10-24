/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 
 * Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.


 */
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {

        if (t2 == nullptr)
        {
            return t1;
        }

        if (t1 == nullptr)
        {
            return t2;
        }
        // we are doing this in preorder so add first then move on

        t1->val = t1->val + t2->val;

        // call left first then call right
        t1->left = mergeTrees(t1->left, t2->left);

        t1->right = mergeTrees(t1->right, t2->right);

        return t1;
    }
};

/*
    Runtime: 36 ms, faster than 86.27% of C++ online submissions for Merge Two Binary Trees.
    Memory Usage: 13.6 MB, less than 80.56% of C++ online submissions for Merge Two Binary Trees.
*/