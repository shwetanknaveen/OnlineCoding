//Problem link - https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) 
    {
        int row = grid.size(),col = grid[0].size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        //i,j,cost to reach here
        vector<vector<int>> dist(row,vector<int>(col,1e5));
        dist[0][0] = 0;
        pq.push({0,0,0});
        int dir[4][2] = {{0, 1},{-1, 0},{1, 0},{0, -1}};
        int adjI,adjJ;
        while(!pq.empty())
        {
            auto [cost,i,j] = pq.top();
            pq.pop();     
            for(int k=0;k<4;k++)
            {
                adjI = i+dir[k][0];
                adjJ = j+dir[k][1];
                
                if(adjI<0 || adjI>=row || adjJ<0 || adjJ>=col) continue;
                
                if(dist[adjI][adjJ]>cost+grid[adjI][adjJ])
                {
                    dist[adjI][adjJ] = cost+grid[adjI][adjJ];//here grid[adjI][adjJ] is edge weight
                    pq.push({dist[adjI][adjJ],adjI,adjJ});
                }
            }
        }
        return dist[row-1][col-1];
    }
};
