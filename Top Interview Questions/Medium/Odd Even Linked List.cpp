/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *odd = head, *even = head->next;
        ListNode *op = odd, *ep = even;
        while(op != nullptr && ep != nullptr) {
            if(op->next != nullptr) {
                op->next = op->next->next;
            }
            if(ep->next != nullptr) {
                ep->next = ep->next->next;
            }
            if(op->next == nullptr) op->next = even;
            else op = op->next;
            ep = ep->next;
        }
        if(op->next == nullptr) op->next = even;
        return odd;
    }
};