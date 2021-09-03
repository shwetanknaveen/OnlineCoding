//Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bought,sell;
        int n = prices.size();
        int profit = 0;
        for(int i=0;i<n-1;i++)
        {
            if(prices[i+1]>=prices[i])
            {
                bought = i;//if current stock has less value than later stock then buy it
                while(i<n-1 && prices[i+1]>=prices[i])//keep looking for the best price
                {
                    i++;
                }
                sell=i;//sell at best price day
                profit += prices[sell] - prices[bought];//corresponding transaction profit is added and then move ahead
                //to look for next buy and sell pair
            }
        }
        return profit;
    }
};

