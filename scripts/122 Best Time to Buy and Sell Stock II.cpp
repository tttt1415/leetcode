class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //greedy, get all the positive profits
        int profit = 0;
		for (int i = 1; i < prices.size(); i++) {
			profit += prices[i] > prices[i - 1] ? (prices[i] - prices[i - 1]) : 0;
		}
		return profit;
    }
};