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
    //recursive
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        
        return isSym(root->left, root->right);
    }
    bool isSym(TreeNode* leftTree, TreeNode* rightTree) {
        if (!leftTree && !rightTree) return true;
        if (!leftTree || !rightTree) return false;
        if (leftTree->val != rightTree->val) return false;
        if (!isSym(leftTree->left, rightTree->right)) return false;
        if (!isSym(leftTree->right, rightTree->left)) return false;
        
        return true;
        //return (leftTree->val == rightTree->val) && isSym(leftTree->left, rightTree->right) && isSym(leftTree->right, rightTree->left);
    }
    
    //iterative
    /*
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        
        q1.push(root->left);
        q2.push(root->right);
        
        while (!q1.empty() && !q2.empty()) {
            TreeNode* t1 = q1.front();
            TreeNode* t2 = q2.front();
            q1.pop();
            q2.pop();
            
            if (!t1 && t2) return false;
            if (t1 && !t2) return false;
            if (t1 && t2) {
                if (t1->val != t2->val) return false;
            
                q1.push(t1->left);
                q2.push(t2->right);
                q1.push(t1->right);
                q2.push(t2->left);
            }
            
        }
        
        return true;
    }
    */
};