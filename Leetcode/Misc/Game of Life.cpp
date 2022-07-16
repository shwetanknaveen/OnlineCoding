//Problem link - https://leetcode.com/problems/game-of-life/

class Solution {
public:
    //For each live neighbour, we count 2
    int getLiveNeighCount(int i,int j,vector<vector<int>> &board)
    {
        int neighI,neighJ,ans = 0;
        for(int x = -1;x <= 1;x++)
        {
            for(int y= -1;y <= 1;y++)
            {
                if(x==0 && y==0) continue;//in this case neighI,neighJ will give the same cell
                neighI = i+x;
                neighJ = j+y;
                if(neighI<0 || neighI>=board.size() || neighJ<0 || neighJ>=board[0].size()) continue;
                if(board[neighI][neighJ] & 1) ans = ans+2;//if this neighbour is live then even after changing its value for its own live neighbours, its value will remain odd
            }
        }
        return ans;
    }
    void gameOfLife(vector<vector<int>>& board) 
    {
        int row = board.size(), cols = board[0].size(),liveNeigh;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<cols;j++)
            {
                board[i][j] += getLiveNeighCount(i,j,board);//For each live neighbour, we add 2. Hence even
                                                            //after changing the values,a dead cell value
                                                            //always remains even and a live cell value 
                                                            //always remmains odd
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<cols;j++)
            {
                int neighLife = board[i][j]/2;//Because we counted 2 for each live neighbour and added in cell's value.So if a live cell has 1 live neighbour, it's value here will be 3 and hence actual live neigbhour = 3/2 = 1
                board[i][j] = board[i][j]&1 ? 1 : 0;//if final value is even hence cell was originaly dead and vice versa hence it is restored accordingly
                if(board[i][j] == 0)//this cell is dead
                {
                    if(neighLife==3) board[i][j] = 1;//live neighbours count is 3 hence this cell becomes alive
                }
                else//this cell is alive
                {
                    if(neighLife>3 || neighLife<2) board[i][j] = 0;
                }
            }
        }
        
    }
};
