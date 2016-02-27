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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return head;
		ListNode* newNode = new ListNode(0);
		newNode -> next = head;
		ListNode *current = head, *small = newNode;
		
		//scan to find the first greater or equal to x node
		while (current) {
			if (current -> val < x) {
				current = current -> next;
				small = small -> next;
			}
			else {
				break;
			}
		}
		
		//move all the smaller nodes before the first searched node
		ListNode *pre = small;
		while (current) {
			if (current -> val >= x) {
				current = current -> next;
				pre = pre -> next;
			}
			else {
				ListNode* temp = small -> next;
				small -> next = current;
				pre -> next = current -> next;
				current -> next = temp;
				//remember to move forward the current
				small = small -> next;
				current = pre -> next;
			}
		}
		
		ListNode* result = newNode -> next;
		delete newNode;
		return result;
    }
};