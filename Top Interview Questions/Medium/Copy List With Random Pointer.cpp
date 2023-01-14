/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *p = head, *q, *nHead;
        if(head == nullptr) return p;
        while(p != nullptr) {
            q = new Node(p->val);
            q->next = p->next;
            p->next = q;
            p = p->next->next;
        }
        nHead = head->next;
        p = head;
        while(p != nullptr) {
            q = p->next;
            if(p->random != nullptr) q->random = p->random->next;
            p = q->next;
        }
        p = head;
        while(p != nullptr) {
            q = p->next;
            p->next = p->next->next;
            if(q->next != nullptr) q->next = q->next->next;
            p = p->next;
        }
        return nHead;
    }
};