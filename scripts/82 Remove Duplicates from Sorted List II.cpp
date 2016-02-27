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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        ListNode* newNode = new ListNode(0);
		newNode -> next = head;
		ListNode *current = head, *pre = newNode;
		
		//remeber to check both current and its next
		while(current && current -> next) {
			if (current -> val != current -> next -> val) {
				pre = current;
				current = current -> next;
			}
			else {
				while(current -> next && current -> next -> val == current -> val) {
					current = current -> next;
				}
				current = current -> next;
				pre -> next = current;
			}
		}
		
		ListNode* result = newNode -> next;
		delete newNode;
		return result;
    }
};