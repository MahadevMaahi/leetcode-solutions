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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;
        int cnt = 0;
        ListNode *prev, *curr = head;
        while(cnt < n && curr != nullptr) curr = curr->next, cnt++;
        if(cnt < n && curr == nullptr) return head;
        else if(cnt == n && curr == nullptr) return head->next;
        prev = head;
        while(curr->next != nullptr) prev = prev->next, curr = curr->next;
        prev->next = prev->next->next;
        return head;
    }
};