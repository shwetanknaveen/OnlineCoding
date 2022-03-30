//Problem link - https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1#
//Video link - https://www.youtube.com/watch?v=HnD676J56ak&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=21

class Solution
{
	public:
	int minKeyInd(vector<bool> mst,vector<int> key)//next key which can be included in the MST
	{
	    int minVal = INT_MAX,min_key;
	    for(int i=0;i<mst.size();i++)
	    {
	        if(!mst[i] && key[i]<minVal)//it shouldn't be included already and it should be minimum
	        {
	            minVal = key[i];
	            min_key = i;
	        }
	    }
	    return min_key;
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> parent(V),key(V,INT_MAX);
        vector<bool> mst(V,false);
        
        vector<vector<int>> graph(V,vector<int>(V,0));
        
		//Save the graph in adjacency form to matrix form
		for(int i=0;i<V;i++)
        {
            for(auto p : adj[i])
            {
                graph[i][p[0]] = p[1];//edge is from i to p[0] having weight p[1]
            }
        }
        
        key[0] = 0;//taking first vertex as root vertex for the MST
        parent[0] = -1;//Parent of the root vertex won't exist hence keeping it -1
        for(int i=0;i<V;i++)
        {
            int addNode = minKeyInd(mst,key);//get the next node to be added
            mst[addNode] = true;//node has been added
            for(auto p : adj[addNode])//look for the adjacent nodes of the recently added node
            {
                if(key[p[0]] > p[1] && !mst[p[0]])//if this adjecent node(p[0]) hasn't been added yet and its current cost
                								//cost of addition is more than cost of additon through vertex addNode (
												//this cost is p[1]) then update the current cost and parent of this
												//neighbour i.e., p[0]
                {
                    key[p[0]] = p[1];
                    parent[p[0]] = addNode;
                }
            }
        }
        int sum = 0;
        for(int i=1;i<V;i++)//start from 1st vertex because 0th vertex is root of MST and has no parent
        {
            sum += graph[i][parent[i]];
        }
        return sum;
    }
};
