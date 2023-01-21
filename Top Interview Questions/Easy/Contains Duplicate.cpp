class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return true;
        unordered_set<int> uSet;
        for(int i : nums) if(uSet.count(i)) return true; else uSet.insert(i);
        return false;
    }
};