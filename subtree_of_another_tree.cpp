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
    // so i iterate through each subtree here calling the checkSameTree method to figure out whether there
    // exists a portion where they are the same
    bool isSubtree(TreeNode *s, TreeNode *t)
    {

        // if it does not exist
        if (!s)
        {
            return false;
        }
        //first if they're the exact same
        if (checkSameTree(s, t))
        {
            return true;
        }

        // same for the left and right

        return (isSubtree(s->left, t) || isSubtree(s->right, t));
    }

    // so this method will go through each subtree passed to it to determine if they are the same
    bool checkSameTree(TreeNode *s, TreeNode *t)
    {

        // both empty means that they are the same
        if (s == nullptr && t == nullptr)
        {
            return true;
        }

        // but one being not empty when other is = nto same
        if (s == nullptr || t == nullptr) // alteratively s = null but t != null || t== null but s != null
        {
            return false;
        }
        if (s->val != t->val)
        {
            return false;
        }
        return checkSameTree(s->left, t->left) && checkSameTree(s->right, t->right);
    }
};