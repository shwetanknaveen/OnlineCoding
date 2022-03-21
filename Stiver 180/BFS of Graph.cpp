//Problem link - https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> visited(V,0);
        queue<int> qu;
        qu.push(0);
        visited[0] = true;
        while(!qu.empty())
        {
            int thisNode = qu.front();
            qu.pop();
            ans.push_back(thisNode);
            for(auto n : adj[thisNode])
            {
                if(!visited[n])
                {
                    qu.push(n);
                    visited[n] = 1;
                }
            }
        }
        return ans;
    }
};
