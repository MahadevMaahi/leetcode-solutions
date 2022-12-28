class Solution {
public:

    int findStart(vector<int> &nums, int low, int high, int target) {
        int mid;
        while(low < high) {
            mid = (low + high) / 2;
            if(nums[mid] == target) high = mid;
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }

    int findEnd(vector<int> &nums, int low, int high, int target) {
        int mid;
        while(low < high) {
            mid = (low + high) / 2;
            if(nums[mid] == target) {
                if(low == mid) {
                    if(nums[high] == target) return high;
                    else return mid;
                } else low = mid;
            }
            else if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size(), low = 0, high = len - 1, mid;
        vector<int> ans(2, -1);
        while(low <= high) {
            mid = (low + high) / 2;
            if(nums[mid] == target) {
                ans[0] = findStart(nums, low, mid, target);
                ans[1] = findEnd(nums, mid, high, target);
                return ans;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};