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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return generateTree(postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }
	
	TreeNode* generateTree(vector<int>& postorder, vector<int>& inorder, int startPost, int endPost, int startIn, int endIn) {
		if (startPost > endPost || startIn > endIn) return NULL;
		TreeNode* root = new TreeNode(postorder[endPost]);
		int i = -1;
		for (i = startIn; i <= endIn; i++) {
		    //using root->val instead of postorder[endPost] will be faster
			if (inorder[i] == root -> val) {
				break;
			}
		}
        
		int leftSize = i - startIn;
		int rightSize = endIn - i;
		
		root -> left = generateTree(postorder, inorder, startPost, startPost + leftSize - 1, startIn, i - 1);
		root -> right = generateTree(postorder, inorder, endPost - rightSize, endPost - 1, i + 1, endIn);
	}
};