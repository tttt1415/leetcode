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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> dummy;
        if (n == 0) return dummy;
        return genTree(1, n);
    }
    
    vector<TreeNode*> genTree(int min, int max) {
        vector<TreeNode*> result;
        
        if (max < min) {
            result.push_back(NULL);
            return result;
        }
        
        for (int i = min; i <= max; i++) {
            vector<TreeNode*> left = genTree(min, i - 1);
            vector<TreeNode*> right = genTree(i + 1, max);
            
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root -> left = left[j];
                    root -> right = right[k];
                    result.push_back(root);
                }
            }
        }
        
        return result;
    }
    
};