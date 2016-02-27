/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	void connect(TreeLinkNode *root) {
		TreeLinkNode* first = root;
		
		while (root) {
		    //remeber to put this if/ else statement
			if (root -> left) {
				root -> left -> next = root -> right;
			}
			else {
			    break;
			}
			
			if (root -> next) {
			    //still in the same level
				root -> right -> next = root -> next -> left;
				root = root -> next;
			}
			else {
			    //go to next level
				root -> next = NULL;
				root = first -> left;
				first = root;
			}
		}
	}
};