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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL) return head;
		ListNode *newNode = new ListNode(0);
		newNode -> next = head;
		ListNode *start = newNode, *current = head, *temp;
		int count = 0;
		int numNodes = n - m;
		
		while (current) {
			if (count == m - 1) {
				break;
			}
			current = current -> next;
			start = start -> next;
			count++;
		}
		
		for (int i = 0; i < numNodes; i++) {
			temp = current -> next;
			current -> next = temp -> next;
			temp -> next = start -> next;
			start -> next = temp;
		}
		
		ListNode* result = newNode -> next;
		delete newNode;
		return result;		
    }
};