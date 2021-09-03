//Problem link - https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1#
class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
        vector<vector<int>> ans;
        int bought,sell;
        for(int i=0;i<n-1;i++)
        {
            if(A[i+1]>=A[i])
            {
                bought = i;//if current stock has less value than later stock then buy it
                while(i<n-1 && A[i+1]>=A[i])//keep looking for the best price
                {
                    i++;
                }
                sell=i;//sell at best price day
                ans.push_back({bought,sell});//push this bought sell pair and look for next stock again
            }
        }
        return ans;
        
    }
};

