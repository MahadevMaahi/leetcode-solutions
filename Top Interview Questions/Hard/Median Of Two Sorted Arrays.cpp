class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int aLen = A.size(), bLen = B.size();
        if(aLen > bLen) {
            return findMedianSortedArrays(B, A);
        }

        int start = 0, end = aLen;
        while(start <= end) {
            int i1 = (start + end) / 2, i2 = ((aLen + bLen + 1)/2) - i1;
            int minA = (i1 == aLen) ? INT_MAX : A[i1];
            int maxA = (i1 == 0) ? INT_MIN : A[i1 - 1];
            int minB = (i2 == bLen) ? INT_MAX : B[i2];
            int maxB = (i2 == 0) ? INT_MIN : B[i2 - 1];

            if((maxA <= minB) && (maxB <= minA)) {
                if(((aLen + bLen) % 2) == 0) {
                    return ((double) (max(maxA, maxB) + min(minA, minB)) / 2);
                } else {
                    return (double) max(maxA, maxB);
                }
            } else if(maxA > minB) {
                end = i1 - 1;
            } else {
                start = i1 + 1;
            }
        }
        return -1;
    }
};