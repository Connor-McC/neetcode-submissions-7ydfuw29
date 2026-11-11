class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minbuy = INT_MAX;
        int maxprofit = 0;
        for (int price : prices){
            int curr = price - minbuy;
            maxprofit = max(maxprofit, curr);
            minbuy = min(minbuy, price);
        }
        return maxprofit;

    }
};
