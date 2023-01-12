class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0) return 0;
        int profit = 0;
        for(int i = 0; i < len; i++) {
            if((i-1) >= 0 && prices[i] > prices[i-1]) profit = profit + (prices[i] - prices[i-1]);
        }
        return profit;
    }
};