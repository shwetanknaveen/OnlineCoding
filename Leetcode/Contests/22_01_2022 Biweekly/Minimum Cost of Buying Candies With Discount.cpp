//Question link - https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans=0;
        int n = cost.size();
        sort(cost.rbegin(),cost.rend());
        int i;
        for(i=0;i+1<n;i=i+3)
        {
            ans += cost[i]+cost[i+1];//pay for two items and get the third one free, obviously here the third one will be <=
            						//min(first two) as we have sorted in decreasing order
        }
        if(i<n)//last odd left out element
            ans += cost[i];
        
        return ans;
    }
};
