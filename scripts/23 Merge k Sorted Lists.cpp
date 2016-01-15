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
    //http://www.geeksforgeeks.org/merge-k-sorted-arrays/
    //http://bangbingsyb.blogspot.com/2014/11/leetcode-merge-k-sorted-lists.html
    //O(nk log(k)), O(1)
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty()) return NULL;
        int end = lists.size()-1;
        
        //similar to merge sort, sort two lists, avoid duplicate merge
        while(end>0) {
            int begin = 0;
            while(begin<end) {
                lists[begin] = mergeTwoLists(lists[begin], lists[end]);
                begin++;
                end--;
            }
        }
        return lists[0];
    }
    //https://leetcode.com/problems/merge-two-sorted-lists/
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //if one fo the list is NULL, just retrun another list
        if (l1 == NULL && l2 == NULL) return NULL;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode* head = new ListNode(-1);
        ListNode* node = head;
        int val1, val2;
        
        while(l1 != NULL || l2 != NULL) {
            if (l1 == NULL) {
                node->next = l2;
                break;
            }
            if (l2 == NULL) {
                node->next = l1;
                break;
            }
            
            val1 = l1->val;
            val2 = l2->val;
            if (val1 < val2) {
                node->next = l1;
                l1 = l1->next;
            }
            else {
                node->next = l2;
                l2 = l2->next;
            }
            
            node = node->next;
        }
        
        //use head to indicate the beginning of the list, delete it later
        node = head->next;
        delete head;
        return node;
    }
    /*
    //priority queue
    //O(nk log(k)), O(k)
    struct compNode {
        bool operator()(ListNode *p, ListNode *q) const {
            return p->val>q->val;
        }  
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compNode> pq;
        ListNode* result = new ListNode(0);
        ListNode* current = result;
        
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) pq.push(lists[i]);
        }
        
        while(!pq.empty()) {
            current->next = pq.top();
            current = current->next;
            pq.pop();
            if (current->next) pq.push(current->next);
        }
        
        return result->next;
        
    }
    */
};