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

    search(vector<int> &inorder, int x, int low, int high) {
        for(int i = low; i <= high; i++) if(inorder[i] == x) return i;
        return -1;
    }

    TreeNode* recurTree(vector<int> &preorder, vector<int> &inorder, int &rootIndex, int low, int high) {
        if(low > high) return nullptr;
        int i = search(inorder, preorder[rootIndex], low, high);
        TreeNode *p = TreeNode(preorder[rootIndex]);
        rootIndex++;
        p->left = recurTree(preorder, inorder, rootIndex, low, i - 1);
        p->right = recurTree(preorder, inorder, rootIndex, i + 1, high);
        return p;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size(), low = 0, high = len - 1,index = 0;
        return recurTree(preorder, inorder, index, low, high);
    }
};