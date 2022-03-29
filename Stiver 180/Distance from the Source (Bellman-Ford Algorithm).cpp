//Problem link - https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0/?fbclid=IwAR2_lL0T84DnciLyzMTQuVTMBOi82nTWNLuXjUgahnrtBgkphKiYk6xcyJU#
//Video link - https://www.youtube.com/watch?v=75yC1vbS8S8&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=29

/*
You don't need to read input or print anything. Your task is to complete the function bellman_ford()  which takes number of 
vertices V and an E sized list of lists of three integers where the three integers are u,v, and w; denoting there's an edge 
from u to v, which has a weight of w as input parameters and returns a list of integers where the ith integer denotes the 
distance of ith node from source node. If some node isn't possible to visit, then it's distance should be 100000000(1e8)
*/
class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int> dist(V,1e8);
        dist[S] = 0;
        for(int i=0;i<V;i++)
        {
            for(auto edge : adj)//there is a edge between vertex edge[0] and vertex edge[1] having weight edge[2]
            {
                if(dist[edge[0]]+edge[2]<dist[edge[1]])//Relaxing
                {
                    dist[edge[1]] = dist[edge[0]]+edge[2];
                }
            }
        }
        return dist;
    }
};
