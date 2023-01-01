class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size(), index = 0;
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < len; i++) {
            if(intervals[index][1] >= intervals[i][0]) {
                intervals[index][1] = max(intervals[i][1], intervals[index][0]);
            } else {
                index++;
                intervals[index] = intervals[i];
            }
        }
        intervals.resize(index + 1);
        return intervals;
    }
};