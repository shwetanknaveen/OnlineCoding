//Problem link - https://leetcode.com/problems/paint-house-iii/

//Approach - 1 
/*
ind -> Judging house at index ind in houses to color
prevHouseColor -> Color of the house at index (ind-1)
nNeigh -> How many neighbourhood have we seen upto here while coloring the required number of houses


We should note that there is increase in number of neighbourhood whenever there is change in color of present
house from the color of last house that is whenever (houses[ind] != prevHouseColor) is true, nNeigh increases by 1.
*/

class Solution {
public:
    long getCost(vector<int>& houses, vector<vector<int>> &cost, int &m, int &n, int &target,int ind,int prevHouseColor,int nNeigh,vector<vector<vector<int>>> &dp)
    {
        if(ind==houses.size())//We have colored all the houses
        {
            if(nNeigh==target)//required number of neighbourhood has been attained hence no more cost is required
                return 0;
            else return INT_MAX;//not possible this way to color houses in such a way that there is target number of neighbourhood
        }
        if(dp[ind][prevHouseColor][nNeigh] != -1) return dp[ind][prevHouseColor][nNeigh];
        if(houses[ind] != 0)//if this house is already colored then we need not color this house
            return dp[ind][prevHouseColor][nNeigh] = getCost(houses,cost,m,n,target,ind+1,houses[ind],nNeigh+(houses[ind] != prevHouseColor),dp);
        long costToColorThis = INT_MAX;
        for(int i=0;i<n;i++)
        {
            houses[ind] = i+1;//this house is given (i+1)th color and cost for it is cost[ind][i]
            costToColorThis = min(costToColorThis,cost[ind][i] + getCost(houses,cost,m,n,target,ind+1,i+1,nNeigh+(i+1 != prevHouseColor),dp));
                                                                //                              previous color for next house will be i+1
        }
        houses[ind] = 0;//reset this house color back to 0 for next recursive call
        return dp[ind][prevHouseColor][nNeigh] = costToColorThis;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) 
    {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n+2,vector<int>(m,-1)));//there can be at max m neighbourhood
        long ans = getCost(houses,cost,m,n,target,0,0,0,dp);//initially there is no neighbourhood and previous house color at index = 0 can be taken as 0
        if(ans>=INT_MAX) return -1;//There is no possibility to color house with required condition of target neighbourhood
        return ans;
        
    }
};

//Approach -2 -> Here it's hard to apply DP hence it's better to write in way of above approach

class Solution {
public:
    int getNeighCount(vector<int> &houses)
    {
        int neighCount = 0,lastHouseColor = 0;
        for(int &houseColor:houses)
        {
            if(houseColor!= lastHouseColor)
            {
                neighCount++;
                lastHouseColor = houseColor;
            }
        }
        return neighCount;
    }
    long getCost(vector<int>& houses, vector<vector<int>> &cost, int &m, int &n, int &target,int ind)
    {
        if(ind==houses.size())
        {
            if(getNeighCount(houses)==target)
                return 0;
            else return INT_MAX;
        }
        if(houses[ind] != 0)
            return getCost(houses,cost,m,n,target,ind+1);
        long costToColorThis = INT_MAX;
        for(int i=0;i<n;i++)
        {
            houses[ind] = i+1;
            costToColorThis = min(costToColorThis,cost[ind][i] + getCost(houses,cost,m,n,target,ind+1));
        }
        houses[ind] = 0;
        return costToColorThis;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) 
    {
        long ans = getCost(houses,cost,m,n,target,0);
        if(ans>=INT_MAX) return -1;
        return ans;
        
    }
};
