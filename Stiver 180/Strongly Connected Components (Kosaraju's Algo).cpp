//Problem link - https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1/#
//Video link - https://www.youtube.com/watch?v=V8qIqJxCioo&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=28
//Why this algo works - https://www.youtube.com/watch?v=Rs6DXyWpWrI

//Step 1 -> Do DFS and store toposort on the stack
//Step 2 -> Take transpose of the given graph
//Step 3 -> Again do DFS on transpose of the graph starting from node at the top of the stack(i.e., in topological order)
class Solution
{
	public:
	void dfs(int node,vector<int> &vis,vector<int> adj[],stack<int> &stac)
	{
	    vis[node] = true;
	    for(int neigh : adj[node])
	    {
	        if(!vis[neigh])
	        {
	            dfs(neigh,vis,adj,stac);
	        }
	    }
	    stac.push(node);//store in the vertices in topological sort. Nodes from top to bottom in the end is toposort
	    				//It doesn't matter for nodes which are part of a cycle that in what order they are in toposort
	    				//because they will be anyway covered in one dfs traversal when DFS launched at any node from cycle
	    				//in the graph or in transpose of the graph
	}
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V,0);
        stack<int> stac,stac2;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj,stac);
            }
            
        }
        vector<int> adjRev[V];//taking transpose of given graph so that while performing DFS on this graph, it get stuck
        for(int i=0;i<V;i++)		//in one SCC itself
        {
            vis[i] = 0;
            for(int neigh:adj[i])
            {
                adjRev[neigh].push_back(i);
            }
        }
        int ans = 0;
        //Now stac has topological order of nodes from top to bottom and we will start DFS first from node at top of stack
        //and then it will get stuck in one SCC and we will do DFS again and again so that we cover all the vertices
        //and we count number of strongly connected components in each traversal
        while(!stac.empty())
        {
            if(!vis[stac.top()])
            {
                ans++;
                dfs(stac.top(),vis,adjRev,stac2);//We are passing a dummy stack stac2 so that we can reuse the same DFS function
                								//which we used for topological sort
            }
            stac.pop();
        }
        return ans;
    }
};
