class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size(), prod = 1;
        if(len == 0) return nums;
        vector<int> ans(len, 1);
        if(len == 1) {
            ans[0] = 0;
            return ans;
        }
        for(int i = 0; i < len; i++) {
            ans[i] = ans[i] * prod;
            prod = prod * nums[i];
        }
        prod = 1;
        for(int i = len - 1; i >= 0; i--) {
            ans[i] = ans[i] * prod;
            prod = prod * nums[i];
        }
        return ans;
    }
};