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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode *prev = nullptr, *mid = nullptr, *end = nullptr;
        mid = end = head;
        while(end != nullptr && end->next != nullptr) {
            prev = mid;
            mid = mid -> next;
            end = end -> next -> next;
        }
        TreeNode *root = new TreeNode();
        root->val = mid -> val;
        if(prev) prev ->next = nullptr;
        mid -> next == nullptr;
        if(head != mid) root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
};