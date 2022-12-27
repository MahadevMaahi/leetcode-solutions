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

    struct CompareNode {
        bool operator()(ListNode const *p1, ListNode const *p2)
        {
            return p1->val > p2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, CompareNode> pq;
        ListNode *curr, *ptr, *head = new ListNode(); int len = lists.size();
        for(int i = 0; i < len; i++) if(lists[i] != nullptr) pq.push(lists[i]); ptr = head;
        while(!pq.empty()) {
            curr = pq.top();
            pq.pop();
            ptr->next = curr;
            ptr = ptr->next;
            if(curr->next != nullptr) pq.push(curr->next);
        }
        return head->next;
    }
};