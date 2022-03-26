
//Approach 1 -> Using BFS ->Kahn's algo
//Problem link - https://practice.geeksforgeeks.org/problems/topological-sort/1#
//Video link - https://www.youtube.com/watch?v=rZv_jHZva34&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=15

//This algorithm is better as we can also verify here that - is topological sort possbile(Acyclic) or not (cyclic)
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
	    
	    return ans;//We can check here that is topological sort possible (ans.size()==V)
	}
};

//Approach 2 -> Using DFS
//Video link - youtube.com/watch?v=Yh6EFazXipA&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=14
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void modifiedDFS(int node,vector<int> &vis,vector<int> adj[],stack<int> &stac)
	{
	    vis[node] = 1;
	    for(int neigh: adj[node])
	    {
	        if(!vis[neigh])
	        {
	            modifiedDFS(neigh,vis,adj,stac);
	        }
	    }
	    stac.push(node);//push the node on stack when all its neighbours have been explored in this way when pushing nodes in
	    				//ans vector, that node will come first which is not neighbour of anyone
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V,0);
	    stack<int> stac;
	    vector<int> ans;
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            modifiedDFS(i,vis,adj,stac);
	        }
	    }
	    while(!stac.empty())
	    {
	        ans.push_back(stac.top());
	        stac.pop();
	    }
	    return ans;
	}
	
};
/*
Example ->    3 points to 0
			  4 points to 0
			  0 points to 1
			  0 points to 2
			  
In this graph stack will contain 1 2 0 3 4 and hence ans will contain 4 3 0 2 1
*/
