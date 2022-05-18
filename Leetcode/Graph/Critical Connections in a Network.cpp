//Problem link - https://leetcode.com/problems/critical-connections-in-a-network/
//Video link - Tarjan's algo - https://www.youtube.com/watch?v=Rhxs4k6DyMM

/*
If there is no back edge from a subgraph to its ancestor or parent then the edge will be a critical bridge.
*/

class Solution {
public:
    void dfs(int ver,vector<vector<int>> &adj,vector<int> &parent,vector<int> &discover,vector<int> &lowVal, vector<vector<int>> &ans,
	int &time)
    {
        discover[ver] = lowVal[ver] = time++;//for the first time, set discover and low value for this node as same = time
        for(int neigh:adj[ver])
        {
            if(discover[neigh] == -1)//this neighbour hasn't been visited yet
            {
                parent[neigh] = ver;
                dfs(neigh,adj,parent,discover,lowVal,ans,time);
                lowVal[ver] = min(lowVal[ver],lowVal[neigh]);//this neigh might have inherited a lower value in its lowVal from a common 
                											//ancestor in common strongly connected component, we take that value in this
                											//vertex lowVal. But for that neigh which is connected part of some other 
                											//strongly connected component, this value won't be updated
                if(lowVal[neigh]>discover[ver]) ans.push_back({ver,neigh});//after minimising the discover time of the neighbour , if it is
                													//still getting discovered after present vertex then it is linked throug
                													//critical edge
            }
            else if(parent[ver] != neigh)//if this already visited neighbour is not parent of present vertex i.e., there is a back edge from 
										//present vertex ver to this neighbour neigh
            {
                lowVal[ver] = min(lowVal[ver],lowVal[neigh]);//part of same strongly connected component
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int time = 0;
        vector<vector<int>> ans,adj(n);
        vector<int> parent(n,-1),discover(n,-1),lowVal(n,-1);
        for(auto v:connections)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        dfs(0,adj,parent,discover,lowVal,ans,time);
        return ans;
    }
};
