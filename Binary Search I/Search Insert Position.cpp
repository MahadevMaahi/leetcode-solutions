class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size(), low = 0, high = len - 1, mid;
        while(low <= high) {
            mid = (low + high) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};