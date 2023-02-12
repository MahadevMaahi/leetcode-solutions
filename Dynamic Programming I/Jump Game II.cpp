class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size(), steps, max_index, jumps;
        if(len <= 1) return 0;
        steps = nums[0]; max_index = nums[0], jumps = 1;
        if(max_index >= len - 1) return jumps;
        for(int i = 1; i < len - 1; i++) {
            steps--;
            if(i > max_index) return -1;
            if(i + nums[i] >= len - 1) return jumps + 1;
            max_index = max(max_index, i + nums[i]);
            if(steps == 0) {
                jumps++;
                if(i > max_index) return -1;
                steps = max_index - i;
            }
        }
        return -1;
    }
};