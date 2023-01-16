class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size(), msf, mxeh, mneh, pmeh;
        if(len == 0) return 0;
        msf = nums[0]; mxeh = nums[0]; mneh = nums[0];
        for(int i = 1; i < len; i++) {
            pmeh = meh;
            mxeh = max({nums[i], mxeh * nums[i], mneh * nums[i]});
            mneh = min({nums[i], mneh * nums[i], pmeh * nums[i]});
            if(msf < mxeh) msf = mxeh;
        }
        return msf;
    }
};