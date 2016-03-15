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
    vector<int> inorderTraversal(TreeNode* root) {
        //1. push current to stack, current = current -> left until NULL
        //2. if current == NULL and stack is not empty,
        //   stack pop, current = current -> right, go to 1.
        //until current == NULL and stack is empty
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* current = root;
        
        while(current || !s.empty()) {
            if (current) {
                s.push(current);
                current = current -> left;
            }
            else {
                current = s.top();
                s.pop();
                result.push_back(current -> val);
                current = current->right;
            }
            
        }
        
        return result;
    }
};