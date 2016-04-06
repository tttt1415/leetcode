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
    void recoverTree(TreeNode* root) {
        TreeNode *first = NULL;
        TreeNode *second = NULL;
        TreeNode *lastElement = new TreeNode(INT_MIN);
        
        traverse(root, &first, &second, &lastElement);
        
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    
    void traverse(TreeNode* root, TreeNode** first, TreeNode** second, TreeNode** lastElement) {
        if (root == NULL) return;
        traverse(root->left, first, second, lastElement);
        
        //maintain the last element
        if (*first == NULL && root->val < (*lastElement)->val) {
            *first = *lastElement;
        }
        if (*first != NULL && root->val < (*lastElement)->val) {
            *second = root;
        }
        *lastElement = root;
        traverse(root->right, first, second, lastElement);
    }
};