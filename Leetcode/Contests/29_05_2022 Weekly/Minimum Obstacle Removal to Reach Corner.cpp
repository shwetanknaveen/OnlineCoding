//Problem link - https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/

//Approach 1 -> Using Dijikstra's algorithm

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



//Approach 2 -> Using 0-1 BFS -> Same as Dijikstra implementation
/*
0-1 BFS is applicable when there are just two weights in the graph x and y and x<y.
We can count number of inversions in edges required to reach destination.
We push reverse of each edge with weight 1 and do 0-1 BFS and in that case cost to reach destination will
give minimum number of inversions.

We push minimum weight edge in front of deque and larger weight edge at the back but always take out from front for processing.
*/
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) 
    {
        int row = grid.size(),col = grid[0].size();
        deque<tuple<int,int,int>> deq;
        vector<vector<int>> dist(row,vector<int>(col,1e5));
        dist[0][0] = 0;
        deq.push_front({0,0,0});
        int dir[4][2] = {{0, 1},{-1, 0},{1, 0},{0, -1}};
        int adjI,adjJ;
        while(!deq.empty())
        {
            auto [cost,i,j] = deq.front();
            deq.pop_front();
            for(int k=0;k<4;k++)
            {
                adjI = i+dir[k][0];
                adjJ = j+dir[k][1];
                
                if(adjI<0 || adjI>=row || adjJ<0 || adjJ>=col) continue;
                
                if(dist[adjI][adjJ]>cost+grid[adjI][adjJ])
                {
                    dist[adjI][adjJ] = cost+grid[adjI][adjJ];//here grid[adjI][adjJ] is edge weight
                    if(grid[adjI][adjJ]==0)
                        deq.push_front({dist[adjI][adjJ],adjI,adjJ});
                    else
                        deq.push_back({dist[adjI][adjJ],adjI,adjJ});
                }
            }
        }
        return dist[row-1][col-1];
    }
};


