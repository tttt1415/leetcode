/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) return head;
        ListNode* node = head;
        int length = 1;
        
        while (node->next) {
            node = node->next;
            length++;
        }
        
        //connect tail and head
        node->next = head;
        
        //move length - k elements
        int move = length - k % length;
        for (int i = 0; i < move; i++) {
            node = node->next;
        }
        
        head = node->next;
        node->next = NULL;
        
        return head;
    }
};