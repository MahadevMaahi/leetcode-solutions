class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        if(len == 1) return gas[0] >= cost[0] ? 0 : -1;
        int start = 0, end = 1, curPrice = 0;
        curPrice = gas[start] - cost[start];
        while(start != end || curPrice < 0) {
            while(start != end && curPrice < 0) {
                curPrice -= gas[start] - cost[start];
                start = (start + 1) % len;
                if(start == 0) return -1;
            }
            curPrice += gas[end] - cost[end];
            end = (end + 1) % len;
        }
        return start;
    }
};