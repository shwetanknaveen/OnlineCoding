//Problem link - https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)//Normal Dijsktra code
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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> adj[n];
        for(vector<int> v:times)
        {
            vector<int> edge = {v[1]-1,v[2]};
            adj[v[0]-1].push_back(edge);//given numbering is from 1 to n but we are following 0 based indexing hence subtracting 1 from 
										//vertex number
        }
        vector<int> ans = dijkstra(n,adj,k-1);//kth vertex is source and it is k-1 in 0 based indexing
        int retVal = INT_MIN;
        for(int i:ans)
        {
            if(i==INT_MAX) return -1;//if any node is unreachable from kth vertex
            retVal = max(retVal,i);//we find maximum time taken to reach a vertex among all vertices. In this time, all other vertices will 
									//also receive the signal parallely
        }
        return retVal;
    }
};
