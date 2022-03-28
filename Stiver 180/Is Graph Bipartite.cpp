//Problem link - https://leetcode.com/problems/is-graph-bipartite/
//Video link - https://www.youtube.com/watch?v=nbgaEu-pvkU&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=11

//Approach - 1 Using BFS

//We will try to make the graph bipartite by using two colors. We will assign one color to a node and then assign different 
//color to nodes around that node. If we can do this for all the nodes then it means that graph is bipartite otherwise the
//given graph is not bipartite
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v,0), 
                    clr(v,0);//there will be two colours-> 0 and 1
        
        for(int i=0;i<v;i++)
        {
            if(!vis[i])//start BFS for this component
            {
                queue<int> qu;
                qu.push(i);
                vis[i] = true;
                clr[i] = 1;//set color for root of this component as it is pushed to the queue
                while(!qu.empty())
                {
                    int siz = qu.size();
                    int parentClr = clr[qu.front()];//all the nodes at this level will have same color
                    while(siz--)//for one level in BFS
                    {
                        int thisNode = qu.front();
                        qu.pop();
                        for(int neigh:graph[thisNode])
                        {
                            if(vis[neigh])//if neighbor is already visited
                            {
                                if(clr[neigh]==parentClr)//and its color is same as parent's color then graph can't be bipartite
                                    return false;
                            }
                            else 
                            {
                                clr[neigh] = !parentClr;//if neighbour is not visited then assign it a color opposite to that of parent's color
                                qu.push(neigh);
                                vis[neigh] = 1;
                            }
                        }
                    }
                }
            }
        }
        return true;//if all coloring was possible such that no two adjacent node got same color then it means that graph is bipartite
    }
};

//Approach 2 -> Using DFS
class Solution {
public:
    bool dfs(int node,vector<vector<int>> &graph,vector<int> &vis,vector<int> &clr,int parClr)
    {
        vis[node] = true;//this node is now visited
        for(int neigh:graph[node])
        {
            if(vis[neigh])//is this neighbor is already visited
            {
                if(clr[neigh]==parClr)//and this neighbor has same color as that of its parent then graph is not bipartite
                {
                    return false;
                }
            }
            else//neighbor is not visited then we give it a color opposite to that of its parent
            {
                clr[neigh] = !parClr;
                if(!dfs(neigh,graph,vis,clr,!parClr)) return false;//after giving color opposite to that of its parent, if 
                													//graph is not bipartite then graph as whole is not bipartite
            }
        }
        return true;//default case is that graph is bipartite
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v,0),
                    clr(v,0);
        for(int i=0;i<v;i++)
        {
            if(!vis[i])//launch DFS for this component with root node having color as 0
            {
                if(!dfs(i,graph,vis,clr,0)) return false;//if this component wasn't bipartite then return false as graph is not bipartite
            }
        }
        return true;//all the components were bipartite hence graph is bipartite
    }
};
