class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();
        if(len < 3) return false;
        int _min = INT_MAX, _max = INT_MAX;
        for(int i = 0; i < len; i++) {
            if(_min >= nums[i]) _min = nums[i];
            else if(_max >= nums[i]) _max = nums[i];
            else return true; 
        }
        return false;
    }
};