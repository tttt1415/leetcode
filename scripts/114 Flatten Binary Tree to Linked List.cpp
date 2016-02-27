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
  void flatten(TreeNode* root) {
    while (root) {
      if (root -> left) {
        TreeNode* current = root -> left;
        while(current -> right) {
          current = current -> right;
        }
        current -> right = root -> right;
        root -> right = root -> left;
        root -> left = NULL;
      }
      root = root -> right;
    }
  }
};