//Problem link - https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/#

//Approach 1 -> Using BFS
//Video link - https://www.youtube.com/watch?v=A8ko93TyOns&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=9

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])//if this node is part of seperate component then launch BFS from this node
            {
                queue<pair<int,int>> qu;//node->its parent
                qu.push(make_pair(i,-1));//first node of every component won't have any parent
                visited[i] = true;
                while(!qu.empty())
                {
                    int thisNode = qu.front().first;
                    int parent = qu.front().second;
                    qu.pop();
                    for(auto neigh : adj[thisNode])
                    {
                        if(visited[neigh])//if this neighbour has already been visited
                        {
                            if(parent != neigh)//and this visted neighbour is not parent of this node then it means there
                                return true;	//exist a cycle which gave way to visit this node agai
                        }
                        else
                        {
                            visited[neigh] = true;
                            qu.push(make_pair(neigh,thisNode));//this neighbour is visited from thisNode hence thisNode will
                            									//be it's parent
                        }
                    }
                }
            }
        }
        return false;//default case is that we don't find any cycle
    }
};

//Approach 2 ->Using DFS
//Video link -> https://www.youtube.com/watch?v=Y9NFqI6Pzd4&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=10

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool modifiedDFS(int node,int parent,vector<int> adj[],vector<int> &visited)
    {
        visited[node] = 1;//this node has now been visited
        for(auto neigh:adj[node])
        {
            if(!visited[neigh])//if this neighbour hasn't been visited
            {
                if(modifiedDFS(neigh,node,adj,visited)) return true;//visiting that neighbour returns a cycle then there is
                												//a cycle. We can't simply return as there can be cycle with
                												//other neighbours
            }
            else if(neigh != parent)//if this neighbour has already been visited and it is some other node than parent then
            						//it means there must be a cycle which gave way to revisit the node
                return true;
        }
        return false;//all neighbours have been explored and cycle couldn't be found => there is no cycle
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])//if this node is part of seperate component then launch dfs to detect cycle from this component
            {
                if(modifiedDFS(i,-1,adj,visited)) return true;//first node of every component will have parent as -1
            }
        }
        return false;//if there were no cycle in any component then default case is that there were no cycle
    }
};


