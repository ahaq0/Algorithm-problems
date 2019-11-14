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
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        vector<vector<int>> output;
        // Will hold treeNodes to process
        queue<TreeNode *> level;
        if (root == nullptr)
        {
            return output;
        }

        // add in the start
        level.push(root);

        while (!level.empty())
        {
            // how many nodes are in the current level?
            int size = level.size();

            // go through each level and add em to a current list
            vector<int> currentLevel;
            for (int i = 0; i < size; i++)
            {

                // we check the left and right of current Node
                TreeNode *next = level.front();
                level.pop();

                currentLevel.push_back(next->val);

                // now just add the neighbhors
                if (next->left != nullptr)
                {
                    level.push(next->left);
                }

                if (next->right != nullptr)
                {
                    level.push(next->right);
                }
            }
            output.push_back(currentLevel);
            // reset vector, it makes my runtime 4ms faster
            currentLevel.clear();
        }

        return output;
    }
};