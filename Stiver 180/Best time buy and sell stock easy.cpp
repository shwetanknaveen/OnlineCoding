//Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

//NOT best soln as uses O(N) space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> min(n);//stores the index which if on left side of the value at which minimum value towards left exist
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
            if((prices[i]-prices[min[i]])>maxProfit)//profit can obviously be maximum when stock was bought at a previous day
            										//when its cost was minimum and sold at current day
            {
                maxProfit = prices[i]-prices[min[i]];//if this transaction can give better profit than current maxProfit then
                									//update maxProfit accordingly
            }
        }
        return maxProfit;        
    }
};

/*
STRIVER SOLUTION -> T(n) = O(n) , S(n) = O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuyPrice = INT_MAX, maxProfit = INT_MIN,n=prices.size();
        for(int i=0;i<n;i++)
        {
            minBuyPrice = min(minBuyPrice,prices[i]);
            maxProfit = max(maxProfit,prices[i]-minBuyPrice);
        }
        return maxProfit;
    }
};
*/
