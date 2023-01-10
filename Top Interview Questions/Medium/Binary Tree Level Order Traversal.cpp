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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode *> q;
        q.push(root);
        vector<int> level, TreeNode *p, int size;
        while(!q.empty()) {
            level.clear();
            size = q.size();
            while(size--) {
                p = q.front();
                level.push_back(p->val);
                if(p -> left != nullptr) q.push(p->left);
                if(p -> right != nullptr) q.push(p->right);
                q.pop();
            }
            ans.push_back(level);
        }
        return ans;
    }
};