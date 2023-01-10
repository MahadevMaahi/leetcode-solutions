class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size(), low = 0, mid = 0, high = len - 1, temp;
        while(mid <= high) {
            if(nums[mid] == 0) {
                temp = nums[low];
                nums[low] = 0;
                nums[mid] = temp;
                low++; mid++;
            } else if(nums[mid] == 1) mid++;
            else {
                nums[mid] = nums[high];
                nums[high] = 2;
                high--;
            }
        }
    }
};