class Solution {
public:
    
    double pow(double x, long n)
    {
        if(n == 0) return (double) 1;
        else if(x == 1 || n == 1) return x;
        else if(n < 0) return pow(1/x, -n);
        else return (n&1) ? pow(x * x, n/2) *x : pow(x * x, n/2);
    }
    
    double myPow(double x, int n) {
        return pow(x, n);
    }
};