//Problem link - https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValid(vector<vector<char>> &board,int row,int col,char origVal)//see "Striver 180/Sudoku Solver" for the logic of this function
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i] == origVal)
                return false;
            if(board[i][col] == origVal)
                return false;
            
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == origVal)
                return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>> &board) 
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.') continue;//'.' won't violate any condition
                char origVal = board[i][j];
                board[i][j] = '$';//Change the original value and check that is original value valid at its position on the board
                if(!isValid(board,i,j,origVal)) return false;
                board[i][j] = origVal;//if this value is valid then store back the original value
            }
        }
        return true;
    }
};
