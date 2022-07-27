//Problem link - https://leetcode.com/problems/time-needed-to-inform-all-employees/

class Solution {
public:
    void dfs(int emp,int time,vector<vector<int>> &adj,int &ans,vector<int> &informTime)
    {   
        if(adj[emp].size()==0) ans = max(ans,time);//This employee is leaf node hence time needed for info to reach here can be ans
        for(int subordinate:adj[emp])
        {
            dfs(subordinate,time+informTime[emp],adj,ans,informTime);//This employee sends information to it's subordinates after time informTime[vert]
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i] != -1)//There is no manager of head
                adj[manager[i]].push_back(i);//adj[emp] will point to its subordinates
        }
        int ans = 0;
        dfs(headID,0,adj,ans,informTime);//head has info at time = 0
        return ans;
    }
};
