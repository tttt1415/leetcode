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
        if (!head || !head->next) return head;
        
        ListNode* current = head;
        while (current->next) {
            if (current->val == current->next->val) {
                current->next = current->next->next;
            }
            else {
                //this else to avoid 1->1->1 becomes 1->1
                if (current->next){
                    current = current->next;
                }
            }
        }
        
        return head;
    }
};