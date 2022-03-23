//Problem link - https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> visited(V,0);
        queue<int> qu;
        qu.push(0);
        visited[0] = true;
        while(!qu.empty())
        {
            int thisNode = qu.front();
            qu.pop();
            ans.push_back(thisNode);
            for(auto n : adj[thisNode])
            {
                if(!visited[n])
                {
                    qu.push(n);
                    visited[n] = 1;
                }
            }
        }
        return ans;
    }
};


//BFS of a multi-component graph
//This solution won't get accepted at GFG link because there we have to start BFS from vertex 0 only and we need not explore
//other components there

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs; 
	    vector<int> vis(V, 0);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])//if this is a vertex in a component and haven't been covered yet then start BFS from here
	        {
        	    queue<int> q; 
        	    q.push(i); 
        	    vis[i] = 1; 
        	    while(!q.empty()) {
        	        int node = q.front();
        	        q.pop(); 
        	        bfs.push_back(node); 
        	        
        	        for(auto it : adj[node]) {
        	            if(!vis[it]) {
        	                q.push(it); 
        	                vis[it] = 1; 
        	            }
        	        }
        	    }
	        }
	    }
	    
	    return bfs;
    }
};
