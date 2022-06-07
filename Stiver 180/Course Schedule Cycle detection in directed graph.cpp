//Problem link - https://leetcode.com/problems/course-schedule/

//Approach 1 - Using BFS ->Kahn's algo modificatin -> We will check whether we can find a topological sort or not
//Video link - https://www.youtube.com/watch?v=V6GxfKDyLBM&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=16

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        
        //Creating adjacency list from given course dependencies
        for(auto p : prerequisites)
        {
            adjList[p[0]].push_back(p[1]);
        }
        int topoSortMembers = 0;
        queue<int> qu;
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            for(auto neigh : adjList[i])
            {
                indegree[neigh]++;
            }
        }
        
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                qu.push(i);
        }
        while(!qu.empty())
        {
            int thisNode = qu.front();
            qu.pop();
            topoSortMembers++;//this node has been added in topoLogical sort
            for(auto neigh : adjList[thisNode])
            {
                indegree[neigh]--;
                if(indegree[neigh]==0)
                    qu.push(neigh);
            }
        }
        if(topoSortMembers==numCourses)//if all nodes were added in topological sort then it means that there was no cycle
            return true;
        return false;//otherwise there is cycle
        
    }
};


//Approach 2 - Using DFS and using additional dfsVis array
//Video link - https://www.youtube.com/watch?v=uzVUw90ZFIg&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=13

class Solution {
public:
    bool checkCycle(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &dfsVis) {
        vis[node] = 1; //mark this node visitied as usual which we do in simple DFS
        dfsVis[node] = 1; //mark this dfsVis additionaly as visited
        for(auto it : adj[node]) {
            if(!vis[it]) {//if this neighbor is not visited then start dfs from this neighbor
                if(checkCycle(it, adj, vis, dfsVis)) return true;//We can't simply return as there can be cycle with
                												//other neighbours
            } else if(dfsVis[it]) {//else if this neighbor has already been visited and it is also marked visited in dfsVis i.e., it is
                return true; 		//pointing back to one of the node in the path through which we came here then there is a cycle
                					//When dfsVis is not true -> Suppose some component's node is visited but when traversal of that
                					//component is completed, dfsVis of that node is set 0. Now if some node of other component points 
                					//to this node, then it won't form a cycle.
            }
        }
        dfsVis[node] = 0; //When all recursive calls at this node is over then set dfsVis back to 0
        return false;//if no cycle is found with all neighbor then there is no cycle
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        
        //Creating adjacency list from given course dependencies
        for(auto p : prerequisites)
        {
            adjList[p[0]].push_back(p[1]);
        }
        vector<int> vis(numCourses,0), dfsVis(numCourses,0);
        
        for(int i = 0;i<numCourses;i++) {
	       if(!vis[i]) {
	           if(checkCycle(i, adjList, vis, dfsVis)) {
	               return false; //if there is a cycle then all courses can't be completed
	           }
	       }
	   }
	   return true;//when then there is no cycle then default case is that all courses can be completed
        
    }
};


