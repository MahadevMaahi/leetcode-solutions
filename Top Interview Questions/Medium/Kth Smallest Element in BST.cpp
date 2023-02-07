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

    void inOrderRecur(TreeNode *root, int k, int &cnt, int &ans) {
        if(root == nullptr) return;
        inOrderRecur(root->left, k, cnt, ans);
        if(k == cnt) return;
        cnt++;
        if(k == cnt) {
            ans = root->val;
            return;
        }
        inOrderRecur(root->right, k, cnt, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, ans;
        inOrderRecur(root, k, cnt, ans);
        return ans;
    }
};