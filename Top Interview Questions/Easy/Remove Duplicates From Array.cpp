class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        int len = A.size(), i = 0, j = 0, temp;
        while(j < len) {
            if(A[i] != A[j]) {
                i++;
                A[i] = A[j];
            }
            j++;
        }
        return i + 1;
    }
};