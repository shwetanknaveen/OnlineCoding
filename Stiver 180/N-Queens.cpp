//Problem link - https://leetcode.com/problems/n-queens/
//Video link - https://www.youtube.com/watch?v=i05Ju7AftcM&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=58


class Solution {
public:
    bool isValid(int i,int j,vector<vector<int>> &board)//is placing a queen at board[i][j] is valid?
    {
        for(int x=i-1;x>=0;x--)//checking upwards
        {
            if(board[x][j]!=-1) return false;
        }
        for(int x=i+1;x<board.size();x++)//checking downwards
        {
            if(board[x][j]!=-1) return false;
        }
        for(int x=j-1;x>=0;x--)//checking left
        {
            if(board[i][x]!=-1) return false;
        }
        for(int x=j+1;x<board.size();x++)//checking right
        {
            if(board[i][x]!=-1) return false;
        }
        
        for(int x=i-1,y=j-1;x>=0 && y>=0;x--,y--)//checking upper left corner
        {
            if(board[x][y] != -1) return false;
        }
        for(int x=i-1,y=j+1;x>=0 && y<board.size();x--,y++)//checking upper right corner
        {
            if(board[x][y] != -1) return false;
        }
        
        for(int x=i+1,y=j-1;x<board.size() && y>=0;x++,y--)//checking lower left corner
        {
            if(board[x][y] != -1) return false;
        }
        for(int x=i+1,y=j+1;x<board.size() && y<board.size();x++,y++)//checking lower right corner
        {
            if(board[x][y] != -1) return false;
        }
        
        return true;//default case
    }
    
    void solve(vector<vector<string>> &ans,vector<vector<int>> &board,int &n,int ind)
    {
        if(ind==n)//it means we have successfully placed n queens in n rows withing given conditions so push this state
        			//of board into ans
        {
            vector<string> tempStrings;
            for(int i=0;i<n;i++)
            {
                string temp;
                for(int j=0;j<n;j++)
                {
                    if(board[i][j] != -1)//this cell has queen
                        temp.push_back('Q');
                    else
                        temp.push_back('.');
                }
                tempStrings.push_back(temp);
            }
            ans.push_back(tempStrings);
            return;
        }
        for(int j=0;j<n;j++)//for each row,check in which column we can place the queen.Start checking from first column for each row
        {
            if(board[ind][j]==-1)//this cell is vacant and has no queen
            {
                board[ind][j] = 1;//occupy this cell
                if(isValid(ind,j,board))//if occupying this cell is valid then check for next row
                    solve(ans,board,n,ind+1);
                board[ind][j] = -1;//leave the occupied row so that next options can be explored when recursion call returns to this level
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>> ans; 
         vector<vector<int>> board(n,vector<int>(n,-1));//initially all cells are empty hence filled with -1
         solve(ans,board,n,0);//start from 1st row i.e., ind =0
         return ans;
    }
};
