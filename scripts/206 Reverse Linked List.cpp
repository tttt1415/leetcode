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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        ListNode *newNode = new ListNode(0);
		newNode -> next = head;
		ListNode *temp, *current = head;
		
		while(current && current -> next) {
			temp = current -> next;
			current -> next = temp -> next;
			temp -> next = newNode -> next;
			newNode -> next = temp;
		}
		
		ListNode *result = newNode -> next;
		delete newNode;
		return result;
    }
};