//Problem link - https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        
        //Creating adjacency list from given course dependencies
        vector<int> ans;
        for(auto p : prerequisites)
        {
            adjList[p[1]].push_back(p[0]);//p[0] is dependent on p[1]
        }
        int topoSortMembers = 0;
        queue<int> qu;
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            for(auto neigh : adjList[i])
            {
                indegree[neigh]++;//course having maximum dependency on other courses will have highest indegree.
            }
        }
        
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)//Push all the courses first which have no dependency
                qu.push(i);
        }
        while(!qu.empty())
        {
            int thisNode = qu.front();
            qu.pop();
            ans.push_back(thisNode);
            topoSortMembers++;//this node has been added in topoLogical sort
            for(auto neigh : adjList[thisNode])
            {
                indegree[neigh]--;
                if(indegree[neigh]==0)
                    qu.push(neigh);
            }
        }
        if(topoSortMembers==numCourses)//if all nodes were added in topological sort then it means that there was no cycle
            return ans;
        return {};//otherwise there is cycle
    }
};
