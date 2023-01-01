class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size(), meh = 0, msf = 0;
        if(len == 0) return nums[0];
        meh = nums[0]; msf = nums[0];
        for(int i = 1; i < len; i++) {
            if(nums[i] > meh + nums[i]) meh = nums[i]; else meh = meh + nums[i];
            if(msf < meh) msf = meh;
        }
        return msf;
    }
};