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
        //http://bangbingsyb.blogspot.com/2014/11/leetcode-construct-binary-tree-from.html
        return generateTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    
    TreeNode* generateTree(vector<int>& preorder, vector<int>& inorder, int startPre, int endPre, int startIn, int endIn){
        if (startPre > endPre || startIn > endIn) return NULL;
        
        TreeNode* root = new TreeNode(preorder[startPre]);
        int i;
        for (i = startIn; i <= endIn; i++) {
            if (inorder[i] == root->val) {
                break;
            }
        }
        
        int leftSize = i - startIn;
        int rightSize = endIn - i;
        
        root->left = generateTree(preorder, inorder, startPre + 1, startPre + leftSize, startIn, i - 1);
        root->right = generateTree(preorder, inorder, endPre - rightSize + 1, endPre, i + 1, endIn);
    }
};