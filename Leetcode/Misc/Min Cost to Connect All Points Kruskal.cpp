//Problem link - https://leetcode.com/problems/min-cost-to-connect-all-points/
//Time complexity = O(n^2 x log(n))
class Solution {
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<int> parent(V),rank(V);
        makeSet(parent,rank);
        vector<pair<int,pair<int,int>>> edges; //<weight of edge,<start point,end point>>
        
        //Push all the possible edges between two given points with their edge weight as defined in the question
        for(int i=0;i<V;i++)
        {
            for(int j=i+1;j<V;j++)
            {
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back(make_pair(dist,make_pair(i,j)));//edge is between point i to j
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
