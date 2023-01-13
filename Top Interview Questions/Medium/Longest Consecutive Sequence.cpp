class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size(), cnt = 0, maxCnt = 0;
        if(len == 0) return 0;
        unordered_set<int> uSet;
        for(int i : nums) {
            uSet.insert(i);
        }
        for(int i : nums) {
            if(uSet.count(i - 1) == 0) {
                int j = i;
                cnt = 0;
                while(uSet.count(j)) {
                    cnt++;
                    j++;
                }
                if(maxCnt < cnt) maxCnt = cnt;
            }
        }
        return maxCnt;
    }
};