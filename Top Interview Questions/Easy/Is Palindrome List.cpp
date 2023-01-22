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

    bool isPalindromeRecur(ListNode *left, ListNode **right) {
        if(left == nullptr) return true;
        bool isPalindrome = isPalindromeRecur(left->next, right);
        if(!isPalindrome) return false;
        if(left->val != (*right)->val) return false;
        *right = (*right)->next;
        return true;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        ListNode **right, *left;
        left = head; right = &head;
        return isPalindromeRecur(left, right);
    }
};