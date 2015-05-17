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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        //the eaf node means to have a node, no node is not considered to be a leaf node
        if (left == 0 && right != 0) {
            left = INT_MAX;
            
        }
        if (right == 0 && left != 0) {
            right = INT_MAX;
            
        }
        
        
        return ((left > right) ? right:left) + 1;
    }
};