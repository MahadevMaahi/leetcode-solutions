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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        deque<TreeNode *> dq; vector<int> level; int size;
        TreeNode *p;
        dq.push_front(root); bool leftToRight = false;
        while(!dq.empty()) {
            level.clear();
            size = dq.size();
            while(size--) {
                if(leftToRight) {
                    p = dq.back();
                    level.push_back(p->val);
                    if(p->right) dq.push_front(p->right);
                    if(p->left) dq.push_front(p->left);
                    dq.pop_back();
                } else {
                    p = dq.front();
                    level.push_back(p->val);
                    if(p->left) dq.push_back(p->left);
                    if(p->right) dq.push_back(p->right);
                    dq.pop_front();
                }
            }
            ans.push_back(level);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};