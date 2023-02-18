class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int len = values.size(), mVal = 0, mxj;
        if(len <= 1) return mVal;
        vector<int> vi(len, 0), vj(len, 0);
        for(int i = 0; i < len; i++) {
            vi[i] = values[i] + i;
            vj[i] = values[i] - i;
        }
        mxj = vj[len - 1];
        for(int i = len - 2; i >= 0; i--) {
            mVal = max(mVal, vi[i] + mxj);
            mxj = max(mxj, vj[i]);
        }
        return mVal;
    }
};