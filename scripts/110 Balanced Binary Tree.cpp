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
    //O(n^2), check geeks for O(n) 
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        
        int lh = height(root->left) ;
        int rh = height(root->right);
        
        if (abs(lh-rh) <= 1) {
            return isBalanced(root->left) && isBalanced(root->right);
        }
        else {
            return false;
        }
    }
    
    //same as Maximum Depth of Binary Tree
    int height(TreeNode* root) {
        if (!root) return 0;
        int lh = height(root->left) + 1;
        int rh = height(root->right) + 1;
        
        return (lh > rh) ? lh:rh;
    }
};