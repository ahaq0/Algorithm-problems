/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            
        
        
        int preStart = 0;;
        return buildTree(preorder, inorder, preStart, 0, inorder.size() -1);
        
    }
    
    // So this recursive function will find where the current value in order ( via preorder is )
    // Then it will recursively add what is to it's left and right in the in order array based on that
    TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder, int & preStart, int inStart, int inEnd)
    {
        // If we have nothing in either array, we return null
        if(preStart >= preorder.size() || inStart > inEnd)
        {
            return nullptr;
        }
        
        // We make our tree based on the value in order ( preoder ).
        TreeNode * node = new TreeNode(preorder[preStart]);
        
        // Once we've made that, we need to find where it lies in order depending on our direction
        int orderedIndex;
        for (int i = inStart; i <= inEnd; i++)
        {
            if(inorder[i] == node->val)
            {
                orderedIndex = i;
                // Nothing else to see.
                break;
            }
        }
        // Since we've found the corresponding index for this preordered value, we can move to the next
        preStart++;
        
        // Here we will recursively call this function for the left & right hand side ( based on index)
        node->left = buildTree(preorder, inorder, preStart, inStart, orderedIndex-1);
        node->right = buildTree(preorder, inorder, preStart, orderedIndex +1, inEnd);
        return node;
    }
};