//Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

//Approach 1 
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

//Approach 2 -> Dynamic programming

class Solution {
    int solve( bool buy, int i, int& n, vector<int>& prices,vector<vector<int>> &dp){
        if(i==n)//can't get any profit outside given days
            return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if( buy ){//if we can buy then we have option to buy on this day or not
            dp[i][buy] = max( solve( false, i+1, n, prices,dp) - prices[i],			solve( true, i+1, n, prices,dp) );
            			/*	If we buy, then we can only sell this further			We don't buy on this day and look to 
            				hence we pass buy=false and subtract this cost			buy sell on further days
            				as we are "buying" on this day
            			*/
        }
        else//if we can't buy then we decide that whether we can sell on the day or not
        	dp[i][buy] = max( solve( true, i+1, n, prices,dp) + prices[i],			solve( false, i+1, n, prices ,dp));
        				/*	We sell the bought stock on this day.Now we 			We don't sell on this day hence we can't
        					can buy again on further days hence we pass				buy on further days untill we sell this 
        					buy=true further and add this stock value				already bought stock.
        					as we are "selling" on this day
        				*/
        
        return dp[i][buy];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve( true, 0, n, prices,dp);
    }
};

