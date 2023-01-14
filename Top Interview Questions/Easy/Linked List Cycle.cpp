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
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        if(head->next == nullptr) return false;
        ListNode *p, *q;
        p = head, q = head->next;
        while(q != nullptr) {
            if(p == q) return true;
            p = p->next;
            q = q->next;
            if(q != nullptr) q = q->next;
        }
        return false;
    }
};