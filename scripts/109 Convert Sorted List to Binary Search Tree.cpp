/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        //http://bangbingsyb.blogspot.com/2014/11/leetcode-convert-sorted-list-to-binary.html
        if (!head) return NULL;
        ListNode* current = head;
        int count = 0;
        
        //caculate the length of the list
        while (current) {
            current = current->next;
            count++;
        }
        
        return buildTree(head, 1, count);
    }
    
    TreeNode* buildTree(ListNode* &head, int start, int end) {
        if (start > end) return NULL;
        //find the mid point
        int mid = start + (end - start) / 2;
        
        TreeNode* left = buildTree(head, start, mid - 1);
        TreeNode* parent = new TreeNode(head->val);
        
        head = head->next;
        TreeNode* right = buildTree(head, mid + 1, end);
        
        parent -> left = left;
        parent -> right = right;
        
        return parent;
    }
};