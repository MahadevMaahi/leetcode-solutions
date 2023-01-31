class Solution {
public:

    int lb(vector<int> &lis, int target) {
        if(lis.size() == 0) return lis.size();
        int low = 0, high = lis.size() - 1;
        while(low < high) {
            int mid = (low + high) / 2;
            if(lis[mid] == target) return mid;
            else if(lis[mid] > target) high = mid;
            else low = mid + 1;
        }
        if(low < lis.size() && lis[low] < target) low++;
        return low;
    }

    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        vector<int> lis;
        for(int i = 0, j; i < len; i++) {
            j = lb(lis, nums[i]);
            if(j == lis.size()) lis.push_back(nums[i]);
            else lis[j] = nums[i];
        }
        return lis.size();
    }
};