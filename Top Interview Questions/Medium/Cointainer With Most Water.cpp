class Solution {
public:
    int maxArea(vector<int>& A) {
        int len = A.size(), i = 0, j = len - 1, ans = 0;
        while(i < j) {
            ans = max(ans, ((j - i) * min(A[i], A[j])));
            if(A[i] < A[j]) i++;
            else j--;
        }
        return ans;
    }
};