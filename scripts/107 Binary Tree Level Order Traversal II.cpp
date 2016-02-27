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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        queue<TreeNode*> NodeQueue;
        vector<int> values;
        NodeQueue.push(root);
        int currentLevelCount = 1, nextLevelCount = 0;
        
        while(NodeQueue.size() != 0) {
            TreeNode* currentNode = NodeQueue.front();
            NodeQueue.pop();
            values.push_back(currentNode -> val);
            currentLevelCount--;
            
            if (currentNode -> left) {
                NodeQueue.push(currentNode -> left);
                nextLevelCount++;
            }
            
            if (currentNode -> right) {
                NodeQueue.push(currentNode -> right);
                nextLevelCount++;
            }
            
            if (currentLevelCount == 0) {
                result.push_back(values);
                values.clear();
                currentLevelCount = nextLevelCount;
                nextLevelCount = 0;
            }
        }
        
        int start = 0, end = result.size() - 1;
        while (end > start) {
            vector<int> temp = result[start];
            result[start] = result[end];
            result[end] = temp;
            start ++;
            end--;
        }
        
        return result;
    }
};