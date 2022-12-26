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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        ListNode *p = list1, *q = list2, *head = new ListNode(), *curr = head;
        while(p != nullptr && q != nullptr) {
            if(p -> val < q -> val) {
                curr -> next = p;
                p =p -> next;
                curr = curr->next;
            } else {
                curr -> next = q;
                q = q -> next;
                curr = curr -> next;
            }
        }
        if(p != nullptr) curr->next = p;
        if(q != nullptr) curr->next = q;
        return head-> next;
    }
};