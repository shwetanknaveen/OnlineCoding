//Problem link - https://leetcode.com/problems/frog-position-after-t-seconds/

class Solution {
public:
    void dfs(int node,double childProd,vector<vector<int>> &adj,int &target,int t,double &ans,vector<bool> &vis)
    {
        if(vis[node]) return;
        vis[node] = true;
        if(t==0)//if there is no more time to jump further
        {
            if(node==target) ans = 1.0/childProd;//frog has reached the target then set the answer
            return;
        }
        if(node==target)//time>0
        {
            if(adj[node].size()==1 && node != 0)//it's a leaf node hence it will remain on target only ->If Root node (0) has one child then
                ans = 1.0/childProd;            //it doesn't mean that it is a leaf node. Also since we pushed undirectional edges hence 
            else                                //actual leaf nodes will have one neighbour which is its parent itself
                ans = 0;//it's not a leaf node and time>0 hence it won't be able to reach again to the target as it will jump to its child
            return;
        }
        for(int neigh:adj[node])
            dfs(neigh,childProd*(adj[node].size()-(node==0?0:1)),adj,target,t-1,ans,vis);
            //adj[node].size()-1 gives number of child of a node. We subtract 1 because one edge points to the parent. But for root node, there is no parent hence for root node, we don't subtract 1.
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(n==1) return 1.0;//There is only one node hence frog will always remain there
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        for(auto edge:edges)
        {
            adj[edge[0]-1].push_back(edge[1]-1);//We will take 0 based indexing
            adj[edge[1]-1].push_back(edge[0]-1);//and will push bidirectional edges
        }
        double childProd = 1.0,ans=0;
        target--;//Since we are taking vertices in 0 based indexing
        dfs(0,childProd,adj,target,t,ans,vis);
        return ans;
    }
};
