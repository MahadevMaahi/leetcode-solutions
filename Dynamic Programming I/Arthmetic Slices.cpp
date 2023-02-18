class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int len = nums.size(), i = 0, j = 0, cnt = 0;
        if(len < 3) return 0;
        vector<int> diff;
        for(int i = 1; i < len; i++) {
            diff.push_back(nums[i] - nums[i-1]);
        }
        while(j < diff.size()) {
            while(j < diff.size() && diff[i] == diff[j]) j++;
            if(j - i >= 2) {
                cnt = cnt + (((j - i - 1) * (j - i)) / 2);
            }
            i = j;
        }
        return cnt;
    }
};