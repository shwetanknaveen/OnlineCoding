//Problem link - https://leetcode.com/problems/path-with-minimum-effort/

class Solution {
public:
    void pushSurroundEdges(vector<vector<int>> adj[],int i,int j,vector<vector<int>> &heights)
    {
        int rows = heights.size(),cols = heights[0].size();
        int cellNumber = i*cols + j;//cell[i][j] is vertex[i*cols+j] (0 based indexing) in linear interpratation
        vector<vector<int>> neigh;
        if(i>0)//edge going up
        {
            vector<int> thisEdge;
            thisEdge.push_back((i-1)*cols+j);//cell number
            thisEdge.push_back(abs(heights[i][j]-heights[i-1][j]));
            neigh.push_back(thisEdge);
        }
        if(i<rows-1)//edge going down
        {
            vector<int> thisEdge;
            thisEdge.push_back((i+1)*cols+j);
            thisEdge.push_back(abs(heights[i][j]-heights[i+1][j]));
            neigh.push_back(thisEdge);
        }
        if(j>0)//edge going left
        {
            vector<int> thisEdge;
            thisEdge.push_back(i*cols+j-1);
            thisEdge.push_back(abs(heights[i][j]-heights[i][j-1]));
            neigh.push_back(thisEdge);
        }
        if(j<cols-1)//edge going right
        {
            vector<int> thisEdge;
            thisEdge.push_back(i*cols+j+1);
            thisEdge.push_back(abs(heights[i][j]-heights[i][j+1]));
            neigh.push_back(thisEdge);
        }
        adj[cellNumber] = neigh;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        int V = rows*cols;//Number of vertices is number of cells in the matrix
        vector<vector<int>> adj[V];
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                pushSurroundEdges(adj,i,j,heights);//add neighbours in the required format for each vertex
            }
        }
        
        int S = 0;//0th vertex is the source vertex.
        vector<int> dis(V,INT_MAX);
        dis[S] = 0;//set distance of source node as 0
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;//(dis from source)->(to which node)
        pq.push(make_pair(0,S));//initially source node is on the pq with its distance as 0
        
        while(!pq.empty())
        {
            int thisNode = pq.top().second;
            int distToThisNode = pq.top().first;
            pq.pop();
            for(auto edge : adj[thisNode])//adj[thisNode] is vector of vectors(of two number) where first number(edge[0]) is 
            							//vertex which can be reached from thisNode and second number(edge[1]) is weight
            							//with which that can be reached from thisNode
            {
                if(max(distToThisNode,edge[1]) < dis[edge[0]])//if current distance to reach edge[0] is more than distance
                											//to reach it using thisNode then we update that and we know that distance to
                											//reach edge[0] using thisNode here is max(distToThisNode,edge[1])
                {
                    dis[edge[0]] = max(distToThisNode,edge[1]);//update the distance
                    pq.push(make_pair(dis[edge[0]],edge[0]));//push the new pair as per the updated distance
                }
            }
        }
        return dis[V-1];//minimum distance to reach the destination cell
    }
};
