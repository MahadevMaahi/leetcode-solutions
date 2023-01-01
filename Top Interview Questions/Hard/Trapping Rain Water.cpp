class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size(), i = 0, j = len - 1, ans = 0, left = INT_MIN, right = INT_MIN;
        while(i < j) {
            if(left < height[i]) {
                left = height[i];
            }
            if(right < height[j]) {
                right = height[j];
            }
            if(height[i] < height[j]) {
                if(height[i] < min(left, right)) {
                    ans = ans + (min(left, right) - height[i]);
                }
                i++;
            } else {
                if(height[j] < min(left, right)) {
                    ans = ans + (min(left, right) - height[j]);
                }
                j--;
            }
        }
    }
};