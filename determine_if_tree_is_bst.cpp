/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// So this is my first solution, although it is O(N), memory is O(N as well which is not good)
#include <vector>
class Solution
{
public:
    vector<int> values;
    bool isValidBST(TreeNode *root)
    {

        inOrderTraversal(root);

        // now if the values are sorted, it has to be a BST
        for (int i = 1; i < values.size(); i++)
        {
            // have to recall, a BST can't have duplicate values so I need the >= there.
            if (values[i - 1] >= values[i])
            {

                //cout  << values[i-1] << " next " << values [i] << endl;
                return false;
            }
        }

        return true;
    }

    // so the idea is to put all of the values in order into a vector then check if the vector is sorted.
    void inOrderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inOrderTraversal(root->left);

        values.push_back(root->val);

        return inOrderTraversal(root->right);
    }
};

// A little better solution using another pointer instead of a vector .5 less mb but better than 98% of solutions

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
class Solution
{
public:
    // so we keep a pointer to keep track of the previous element to compare
    TreeNode *prev = nullptr;
    bool isValidBST(TreeNode *root)
    {

        // base case, if null we know we're at the end / it's empty aka true
        if (root == nullptr)
        {
            return true;
        }

        // we do this in order so left side first
        bool leftSide = isValidBST(root->left);

        // if there is a previous and it's bigger or = to root, then not a bst
        if (prev != nullptr && root->val <= prev->val)
        {
            return false;
        }
        // now we set prev to equal root as root changes

        prev = root;
        bool rightSide = isValidBST(root->right);

        return leftSide && rightSide;
    }
};