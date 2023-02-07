class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len, 0);
        stack<int> stk;
        if(len == 0) return ans;
        for(int i = len - 1; i >= 0; i--) {
            while(!stk.empty() && nums[stk.top()] > nums[i]) stk.pop();
            if(!stk.empty()) ans[i] = ans[stk.top()] + 1;
            stk.push(i);
        }
        return ans;
    }
};