class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN || x == 0) return 0;
        bool isNeg = (x < 0);
        if(isNeg) x = -1 * x;
        int rev = 0;
        while(x > 0) {
            if(rev > (INT_MAX / 10) || (rev == (INT_MAX / 10) && ((x % 10) > 7))) {
                return 0;
            }
            rev = (rev * 10) + (x % 10);
            x = (x / 10);
        }
        return (isNeg) ? (-1 * rev) : rev;
    }
};