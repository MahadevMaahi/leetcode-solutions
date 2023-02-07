class Solution {
public:

    void swap(vector<int> &A, int i, int j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    void moveZeroes(vector<int>& nums) {
        int len = nums.size(), i = 0, j = 0;
        while(j < len) {
            if(nums[j] != 0) {
                swap(nums, i, j);
                i++;
            }
            j++;
        }
    }
};