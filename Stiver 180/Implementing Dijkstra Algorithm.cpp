//Problem link - https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1#
//Video link - https://www.youtube.com/watch?v=jbhuqIASjoM&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=19

/*
You don't need to read input or print anything. Your task is to complete the function dijkstra()  which takes number of 
vertices V and an adjacency list adj as input parameters and returns a list of integers, where ith integer denotes the 
shortest distance of the ith node from Source node. Here adj[i] contains a list of lists containing two integers where the 
first integer j denotes that there is an edge between i and j and second integer w denotes that the weight between edge i and 
j is w.
*/
class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
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
                if((distToThisNode + edge[1]) < dis[edge[0]])//if current distance to reach edge[0] is more than distance
                											//to reach it using thisNode then we update that
                {
                    dis[edge[0]] = distToThisNode + edge[1];//update the distance
                    pq.push(make_pair(dis[edge[0]],edge[0]));//push the new pair as per the updated distance
                }
            }
        }
        return dis;
    }
};
