class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size(), xr = 0;
        for(int i = 0; i < len; i++) xr = xr ^ (nums[i] ^ i);
        return xr ^ len;
    }
};