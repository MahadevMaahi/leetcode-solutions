class Solution {
public:
    int climbStairs(int n) {
        int f0 = 1, f1 = 1, f2;
        if(n < 2) return 1;
        while(n-1 > 0) {
            f2 = f0 + f1;
            f0 = f1;
            f1 = f2;
            n--;
        }
        return f2;
    }
};