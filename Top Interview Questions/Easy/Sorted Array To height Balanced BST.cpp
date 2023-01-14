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

    TreeNode *recurBST(vector<int> &nums, int low, int high) {
        if(low > high) return nullptr;
        int mid = (low + high) / 2;
        TreeNode *p = new TreeNode(nums[mid]);
        p->left = recurBST(nums, low, mid - 1);
        p->right = recurBST(nums, mid + 1, high);
        return p;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size(), low = 0, high = len - 1;
        if(len == 0) return nullptr;
        return recurBST(nums, low, high);
    }
};