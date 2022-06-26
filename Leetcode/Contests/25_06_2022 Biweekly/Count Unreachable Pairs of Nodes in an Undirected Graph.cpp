//Problem link - https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

class Solution {
public:
    long getNC2(long n)
    {
        if(n&1)//n is odd then (n-1) will be even hence (n-1)/2 will remove chance of overflow
            return ((n-1)/2)*n;
        else return (n/2)*(n-1);
    }
    void dfs(vector<vector<int>> &adj,vector<bool> &vis,long &thisCompCount,int v)
    {
        vis[v] = true;
        thisCompCount++;//In this component number of vertices will be counted in thisCompCount
        for(auto neigh:adj[v])
        {
            if(!vis[neigh]) dfs(adj,vis,thisCompCount,neigh);
        }
        
    }
    
    //All the vertices in one component will be reachable from each other in one component
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        long totalPairs = getNC2(long(n));
        long thisCompCount,subtract = 0;
        vector<vector<int>> adj(n);
        for(auto &e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                thisCompCount = 0;
                dfs(adj,vis,thisCompCount,i);
                subtract += getNC2(thisCompCount);//We have to remove all those pairs which are reachable
            }
        }
        return totalPairs - subtract;
    }
};
