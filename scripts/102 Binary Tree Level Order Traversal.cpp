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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        queue<TreeNode*> NodeQueue;
        vector<int> values;
        NodeQueue.push(root);
        int CurrentLevelCount = 1, NextLevelCount = 0;
        
        while (NodeQueue.size() != 0) {
            TreeNode* currentNode = NodeQueue.front();
            NodeQueue.pop();
            values.push_back(currentNode -> val);
            
            if (currentNode -> left) {
                NodeQueue.push(currentNode -> left);
                NextLevelCount++;
            }
            
            if (currentNode -> right) {
                NodeQueue.push(currentNode -> right);
                NextLevelCount++;
            }
            
            CurrentLevelCount--;
            if (CurrentLevelCount == 0) {
                result.push_back(values);
                values.clear();
                CurrentLevelCount = NextLevelCount;
                NextLevelCount = 0;
            }
        }
        
        
        return result;
    }
};