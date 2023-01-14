class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size(), xr = 0;
        if(len == 0) return 0;
        for(int i : nums) xr = xr ^ i;
        return xr;
    }
};