class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size(), i = 0, max_area = 0, tp;
        stack<int> stk;
        while(i < len) {
            if(stk.empty() || heights[i] > heights[stk.top()]) {
                stk.push(i);
                i++;
            } else {
                tp = stk.top();
                stk.pop();
                int width = (stk.empty()) ? i : i - stk.top() - 1;
                if(max_area < (width * heights[tp])) max_area = (width * heights[tp]);
            }
        }
        while(!stk.empty()) {
                tp = stk.top();
                stk.pop();
                int width = (stk.empty()) ? i : i - stk.top() - 1;
                if(max_area < (width * heights[tp])) max_area = (width * heights[tp]);
        }
        return max_area;
    }
};