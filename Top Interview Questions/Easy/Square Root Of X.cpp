class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        long long int low = 1, high = x/2, mid, ans = -1;
        while(low <= high) {
            mid = (low + high)/2;
            if((mid * mid) == x) return mid;
            else if((mid * mid) < x) {
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return ans;
    }
};