//Problem link - https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    void dfs(int i,int j,vector<vector<char>> &board,vector<vector<bool>> &safe)
    {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='X' || safe[i][j])
            return;//if already marked safe then return, it's acting like visited here
        safe[i][j] = true;//mark all attached 'O' cells as unsafe
        
        dfs(i,j-1,board,safe);
        dfs(i,j+1,board,safe);
        dfs(i-1,j,board,safe);
        dfs(i+1,j,board,safe);
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();
        vector<vector<bool>> safe(row,vector<bool>(col,false));
        
        //All those cells which are attached to a cell 'O' which is at boundary won't change to 'X'
        for(int i=0;i<row;i++)//marking all those cells safe which are attached to left or right boundary 'O'
        {
            if(board[i][0] == 'O') dfs(i,0,board,safe);
            if(board[i][col-1] == 'O') dfs(i,col-1,board,safe);
        }
        for(int i=0;i<col;i++)//marking all those cells safe which are attached to top or right bottom 'O'
        {
            if(board[0][i] == 'O') dfs(0,i,board,safe);
            if(board[row-1][i] == 'O') dfs(row-1,i,board,safe);
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
               if(!safe[i][j]) board[i][j] = 'X';//Now make all unsafe cells to 'X'
            }
        }
    }
};
