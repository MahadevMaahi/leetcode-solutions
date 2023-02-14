class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int len = nums.size(), mLen = 0;
        if(len == 0) return mLen;
        vector<int> posDp(len + 1, 0), negDp(len + 1, 0);
        for(int i = 0; i < len; i++) {
            if(nums[i] == 0) {
                posDp[i+1] = 0;
                negDp[i+1] = 0;
            } else if(nums[i] > 0) {
                posDp[i+1] = posDp[i] + 1;
                negDp[i+1] = negDp[i] == 0 ? 0 : negDp[i] + 1;
            } else {
                posDp[i+1] = negDp[i] == 0 ? 0 : negDp[i] + 1;
                negDp[i+1] = posDp[i] + 1;
            }
            if(mLen < posDp[i+1]) mLen = posDp[i+1];
        }
        return mLen;
    }
};