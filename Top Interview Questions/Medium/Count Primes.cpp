class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1) return 0;
        int cnt = 0; vector<bool> pr(n, true);
        for(int i = 2; i < n; i++) if(pr[i]) {
            cnt++;
            for(int j = 2; (i * j) < n; j++) pr[i*j] = false;
        }
        return cnt;
    }
};