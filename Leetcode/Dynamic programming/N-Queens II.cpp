//Problem link - https://leetcode.com/problems/n-queens-ii/

class Solution {
public:
    //Queens are being filled in row major order hence once new queen gets its position, no need to check for validity on 
	//left,right, lower left diagonal, lower right diagonal and lower side as queen in each row is filled for the first time
    bool isValid(int i,int j,vector<vector<int>> &board)//is placing a queen at board[i][j] is valid?
    {
        for(int x=i-1;x>=0;x--)//checking upwards
        {
            if(board[x][j]!=-1) return false;
        }
        for(int x=i-1,y=j-1;x>=0 && y>=0;x--,y--)//checking upper left corner
        {
            if(board[x][y] != -1) return false;
        }
        for(int x=i-1,y=j+1;x>=0 && y<board.size();x--,y++)//checking upper right corner
        {
            if(board[x][y] != -1) return false;
        }
        
        return true;//default case
    }
    
    void solve(vector<vector<int>> &board,int &n,int row,int &count)
    {
        if(row==n)//it means we have successfully placed n queens in n rows withing given conditions so count this state
        			//of board into ans
        {
            count++;
            return;
        }
        for(int j=0;j<n;j++)//for each row,check in which column we can place the queen.Start checking from first column for each row
        {
            board[row][j] = 1;//occupy this cell
            if(isValid(row,j,board))//if occupying this cell is valid then check for next row
            	solve(board,n,row+1,count);
            board[row][j] = -1;//leave the occupied row so that next options can be explored when recursion call returns to this level
        }
    }
    int totalNQueens(int n) {
        int count = 0;
        vector<vector<int>> board(n,vector<int>(n,-1));//initially all cells are empty hence filled with -1
        solve(board,n,0,count);//start from 1st row i.e., ind =0
        return count;
    }
};
