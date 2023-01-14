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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while(fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        fast = slow;
        slow = head;
        slow = sortList(slow);
        fast = sortList(fast);
        ListNode *dummy = new ListNode(0), *curr = dummy;
        while(slow != nullptr && fast != nullptr) {
            if(slow->val < fast->val) {
                curr->next = slow;
                slow = slow->next;
            } else {
                curr->next = fast;
                fast = fast->next;
            }
            curr = curr->next;
        }
        if(slow != nullptr) curr->next = slow;
        if(fast != nullptr) curr->next = fast;
        head = dummy->next;
        return head;
    }
};