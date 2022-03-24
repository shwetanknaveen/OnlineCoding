//Problem link - https://practice.geeksforgeeks.org/problems/topological-sort/1#
//Video link - https://www.youtube.com/watch?v=rZv_jHZva34&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=15

class Solution
{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto neigh:adj[i])
	        {
	            indegree[neigh]++;
	        }
	    }
	    queue<int> qu;
	    vector<int> ans;
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	            qu.push(i);
	    }
	    while(!qu.empty())
	    {
	        int thisNode = qu.front();
	        qu.pop();
	        ans.push_back(thisNode);
	        for(auto neigh:adj[thisNode])
	        {
	            indegree[neigh]--;//this node has been removed hence the node to which this was pointing will have now 1 less indegree
	            if(indegree[neigh]==0)
	                qu.push(neigh);
	        }
	    }
	    
	    return ans;
	}
};
