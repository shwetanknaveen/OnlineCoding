//Problem link - https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

//Disjoint set Data structure -> Rank, find parent and path compression- https://www.youtube.com/watch?v=3gbO7FDYNFQ&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=24
//Kruskal -> https://www.youtube.com/watch?v=1KRmCzBl_mQ&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=25

class Solution
{
	public:
	void makeSet(vector<int> &parent,vector<int> &rank)
	{
	    for(int i=0;i<parent.size();i++)
	    {
	        parent[i] = i;//initially every node is parent of itself
	        rank[i] = 0;//initially rank of every node is zero as no node is attached to it hence its height is 0
	    }
	}
	int findParent(int node,vector<int> &parent,vector<int> &rank)
	{
	    if(parent[node] == node) return node;//reched to the top
	    return parent[node] = findParent(parent[node],parent,rank);//if haven't reached to top then go to top and do compression
	    															//parallely
	}
	void unionNodes(int node1, int node2,vector<int> &parent,vector<int> &rank)
	{
	    node1 = findParent(node1,parent,rank);//now node1 contains its parent
	    node2 = findParent(node2,parent,rank);//now node2 contains its parent
	    
	    if(node1 != node2)//if two nodes have different parents then only their union has to be done
	    {
    	    if(rank[node1]<rank[node2])//set having lower rank has to be attached to set having heigher rank
    	    {
    	        parent[node1] = node2;
    	    }
    	    else if(rank[node1]>rank[node2])
    	    {
    	        parent[node2] = node1;//lower rank node2 is attached to higher rank node1    
    	    }
    	    else//both have equal rank
    	    {
    	        parent[node2] = node1;//attach node2 to node1 -> it can also be other way round
    	        rank[node1]++;//in this case, rank of node1 increases
    	    }
	    }
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> parent(V),rank(V);
        makeSet(parent,rank);
        
        vector<pair<int,pair<int,int>>> edges; //<weight of edge,<start point,end point>>
        for(int i=0;i<V;i++)
        {
            for(auto p : adj[i])
            {
                edges.push_back({p[1],{i,p[0]}});//edge is from node i to node p[0] having weight p[1]
            }
        }
        sort(edges.begin(),edges.end());//sort edges as per their weight
        int cost = 0;
        for(auto p:edges)
        {
            if(findParent(p.second.first,parent,rank) != findParent(p.second.second,parent,rank))//if adding this edge doesn't lead to cycle formation
            {
                cost += p.first;//add this edge cost
                unionNodes(p.second.first,p.second.second,parent,rank);//do union of nodes attached to this edge
            }
        }
        return cost;
    }
};
