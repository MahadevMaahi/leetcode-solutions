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

    void recTree(TreeNode *root, TreeNode **first, TreeNode **middle, TreeNode **last, TreeNode **prev) {
        if(root == nullptr) return;
        recTree(root->left, first, middle, last, prev);
        if(*prev != nullptr && (*prev) -> val > root-> val) {
            if((*first) == nullptr) {
                *first = *prev;
                *middle = root;
            } else *last = root;
        }
        *prev = root;
        recTree(root->right, first, middle, last, prev);
    }

    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *middle = nullptr, *last = nullptr, *prev = nullptr;
        recTree(root, &first, &middle, &last, &prev);
        int temp;
        if(first != nullptr && last != nullptr) {
            temp = first -> val;
            first -> val = last ->val;
            last->val = temp;
        } else if (first != nullptr && middle != nullptr) {
            temp = first ->val;
            first -> val = middle -> val;
            middle -> val = temp;
        }
    }
};