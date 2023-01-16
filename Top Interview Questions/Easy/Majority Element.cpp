class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int cnt = 0, mj = nums[0];
        for(int i : nums) if(i == mj) cnt++; else if(cnt == 0) {
            cnt++;
            mj = i;
        }else cnt--;
        return mj;
    }
};