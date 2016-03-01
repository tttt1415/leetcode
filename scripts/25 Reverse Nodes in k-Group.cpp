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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k < 2) return head;
        if (head == NULL) return head;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *current = head, *first = dummy, *pre = current;
        int length = 0;
        
        while (current) {
            length++;
            current = current -> next;
        }
        
        current = head -> next;
        int numReverse = length / k;
        for (int i = 0; i < numReverse; i++) {
            for (int j = 0; j < k - 1; j++) {
                pre -> next = current -> next;
                current -> next = first -> next;
                first -> next = current;
                current = pre -> next;
            }
            first = pre;
            pre = pre -> next;
            //if already reach the end ([1, 2] 2)
            if (current) {
                current = current -> next;
            }
        }
        
        head = dummy -> next;
        delete dummy;
        return head;
    }
};