//Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> min(n);
        int minInd = 0;
        int minVal = prices[0];
        for(int i=0;i<n;i++)
        {
            if(minVal>prices[i])
            {
                minVal = prices[i];
                minInd = i;
            }
            min[i] = minInd;
        }
        int maxProfit = 0;
        for(int i=0;i<n;i++)
        {
            if((prices[i]-prices[min[i]])>maxProfit)
            {
                maxProfit = prices[i]-prices[min[i]];
            }
        }
        return maxProfit;        
    }
};
