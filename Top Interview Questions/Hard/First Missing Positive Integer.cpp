class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool contains_one = false;
        for(int x: nums) if(x == 1) contains_one = true;
        if(!contains_one) return 1;
        int n = nums.size(); if(n == 1) return 2;
        for(int i = 0; i < n; i++) if(nums[i] <= 0 || nums[i] > n) nums[i] = 1;
        for(int i = 0; i < n; i++) 
            if (nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] = -1 * nums[abs(nums[i]) - 1];
        for(int i = 0; i < n; i++) if(nums[i] > 0) return i+1;
        return (n+1);
    }
};