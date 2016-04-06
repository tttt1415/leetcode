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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        stack<TreeNode*> curStack;
        stack<TreeNode*> nextStack;
        curStack.push(root);
        int level = 0;
        
        while (!curStack.empty()) {
            vector<int> sol;
            
            while (!curStack.empty()) {
                TreeNode* current = curStack.top();
                curStack.pop();
                sol.push_back(current -> val);
                
                if (level % 2 == 0) {
                    if (current -> left) {
                        nextStack.push(current -> left);
                    }
                    if (current -> right) {
                        nextStack.push(current -> right);
                    }
                }
                else {
                    if (current -> right) {
                        nextStack.push(current -> right);
                    }
                    if (current -> left) {
                        nextStack.push(current -> left);
                    }
                }
            }
            
            stack<TreeNode*> temp = curStack;
            curStack = nextStack;
            nextStack = temp;
            
            
            level++;
            result.push_back(sol);
        }
        
        return result;
    }
};