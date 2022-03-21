//Problem link - https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1#

class Solution {
  public:
     void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
        storeDfs.push_back(node); 
        vis[node] = 1; 
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj, storeDfs); 
            }
        }
    }
public:
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    vector<int> storeDfs; 
	    vector<int> vis(V, 0); 
      for(int i = 0;i<V;i++) {//there can be more than one component hence launching dfs on all of them
        if(!vis[i]) dfs(i, vis, adj, storeDfs); 
      }
	    return storeDfs; 
	}
};
