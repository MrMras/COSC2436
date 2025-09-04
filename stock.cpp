// Problem name: Best Time to Buy and Sell Stock
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int cu_min = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] >= cu_min) {
                if (prices[i] - cu_min > profit)
                    profit = prices[i] - cu_min;
            }
            else {
                cu_min = prices[i];
            }
        }
        return profit;
    }
};