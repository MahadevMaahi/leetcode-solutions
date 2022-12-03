/*
link :- https://leetcode.com/problems/two-sum/

Sample test Case 1 :- {
    Input :- [2, 7, 11, 15] target = 9
    output :- [0, 1] or [1, 0]
}
Sample test Case 2 :- {
    Input :- [3, 2, 4] target = 6
    output :- [2, 1] or [1, 1]
}
*/
class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> temp(2, 0);
        vector<vector<int>> A;
        for(int i = 0; i < len; i++) {
            temp[0] = A[i];
            temp[1] = i;
            A.push_back(temp)
        }
        sort(A.begin(), A.end());
        int i = 0, j = len - 1;
        while(i < j) {
            if((A[i][0] + A[j][0]) == target) {
                temp[0] = A[i][1];
                temp[1] = A[j][1];
            } else if((A[i][0] + A[j][0]) > target) {
                j--;
            } else {
                i++;
            }
        }
        return temp;
    }
};