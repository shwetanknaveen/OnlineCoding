//Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

//here we have only one transaction overall which gives maximum profit
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> min(n);//stores the minimum stock price upto current index from left
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
            if((prices[i]-prices[min[i]])>maxProfit)//max profit can be gained by selling at this index 
            										//is when stock was bought at minimum price which lies
            										//on the left of current index
            {
                maxProfit = prices[i]-prices[min[i]];
            }
        }
        return maxProfit;        
    }
};
