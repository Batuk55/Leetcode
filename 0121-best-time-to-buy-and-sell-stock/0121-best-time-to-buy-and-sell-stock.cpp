class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_val = INT_MAX;
        int MaxProfit = 0;

        for (int price : prices) {
            if (price < min_val) {
                min_val = price;
            }

            int profit = price - min_val;
            if (profit > MaxProfit) {
                MaxProfit = profit;
            }
        }
            return MaxProfit;
    }
};

// brute force
/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int MaxProfit = 0;
        //auto max_it = max_element(prices.begin(), prices.end());
        //auto min_it = min_element(prices.begin(), prices.end());
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                int profit = prices[j]- prices[i];
                if (profit>0){
                    MaxProfit = max(profit, MaxProfit);
                }
            }
            }
    return MaxProfit;
        }
};

*/
