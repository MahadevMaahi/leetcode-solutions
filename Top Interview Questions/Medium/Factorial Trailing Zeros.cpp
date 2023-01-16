class Solution {
public:
    int trailingZeroes(int n) {
        if(n == 0) return 0;
        int cnt = 0, div = 5;
        while((n / div) != 0) {
            cnt = cnt + (n / div);
            div = div * 5;
        }
        return cnt;
    }
};