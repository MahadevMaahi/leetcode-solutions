class Solution {
public:

    int squaredSum(int n) {
        int val = 0;
        while (n != 0) {
            val = val + ((n % 10) * (n % 10));
            n = n / 10;
        }
        return val;
    }

    bool isHappy(int n) {
        unordered_set<int> uSet;
        while(n != 1 && uSet.count(n) == 0) {
            uSet.insert(n);
            n = squaredSum(n);
        }
        return n == 1;
    }
};