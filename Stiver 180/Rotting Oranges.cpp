//Problem link - https://leetcode.com/problems/rotting-oranges/
//Video link - https://www.youtube.com/watch?v=pUAPcVlHLKA

//Approach 1 -> My approach
//A rotten orange will rot its surrounding oranges first
class Solution {
public:
    void BFS(queue<pair<int,int>> &qu,int &ans,vector<vector<int>> &grid,int &m,int &n)
    {
        while(!qu.empty())
        {
            bool flagPropogate = false;
            int quSize = qu.size();
            while(quSize--)//at one stage whatever oranges are rotten are on queue and they will simultaneously rot their
            {				//surrounding oranges
            
            pair<int,int> rotten = qu.front();//orange indices which will rot others
            int i = rotten.first, j = rotten.second;
            //Check if there are fresh orange on its surrounding which will get rotten and will propogate rotting further
            //and hence will consume 1 min
            if(j-1>=0 && grid[i][j-1] == 1)//left check
            {
                flagPropogate = true;
                grid[i][j-1] = 2;//Now that orange is also rotten
                qu.push(make_pair(i,j-1));
            }
            if(j+1<n && grid[i][j+1] == 1)//right check
            {
                flagPropogate = true;
                grid[i][j+1] = 2;
                qu.push(make_pair(i,j+1));
            }
            if(i-1>=0 && grid[i-1][j] == 1)//up check
            {
                flagPropogate = true;
                grid[i-1][j] = 2;
                qu.push(make_pair(i-1,j));
            }
            if(i+1<m && grid[i+1][j] == 1)//down check
            {
                flagPropogate = true;
                grid[i+1][j] = 2;
                qu.push(make_pair(i+1,j));
            }
            qu.pop();//remove this orange after checking its surrounding
            }
            if(flagPropogate) ans++;//if after exploring all rotten oranges at certain stage, if atleast one of them rot any
            						//other orange then 1 min has been elapsed
        }
        
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size(); //grid is (m x n)
        
        queue<pair<int,int>> qu;// pair<int,int> = pair<i,j>

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 2)
                {
                    qu.push(make_pair(i,j));//Initially all rotten oranges are on queue
                }
            }
        
        //all initial rotten oranges on the queue
        int ans = 0;
        BFS(qu,ans,grid,m,n);
        
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]==1)
                   return -1;//if after all possible propagation of rotting, there is still fresh orange on grid then 
                   			//it means it can't be rotten
            }
        }
            
        return ans;
    }
};
