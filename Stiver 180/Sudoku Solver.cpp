class Solution {
public:
    bool isValid(int row,int col,vector<vector<char>> &board,char c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==c)
                return false;
            
            if(board[row][i]==c)
                return false;
            
            /*
            Talking about cell (row,col) in the board, since grids are of size 3, hence top left cell of that grid will have 
            index = (3*(row/3),3*(col/3)),now we are traversing the 3x3 grid in row major order hence we should add 1
            to row index which is changes after 3 values and 1 to column index after every iteration
            We could use the following OPTIONAL LOOP instead of this condition below
            */
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
                return false;
        }
        
		/*
		//	OPTIONAL LOOP to replace the last 3x3 grid checking condition in the above loop
		int topLeftRow = 3*(row/3), topLeftCol=3*(col/3);
		for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[topLeftRow+i][topLeftCol+j]==c)
                    return false;
            }
        }
		*/
		
		return true;//We have to return true in default case when none of the condition fails
    }
    bool solve(vector<vector<char>> &board)
    {
    	//there is no base condition. In each call it check's for the vaccan't postion to fill and returns in the end 
    	//if there is no vaccant position at all
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')//this position is vaccant
                {
                    for(char c='1';c<='9';c++)//with which number we can fill
                    {
                        if(isValid(i,j,board,c))//if we can fill this cell with this number
                        {
                            board[i][j] = c;//fill the cell
                            if(solve(board))//if we can solve further after filling this cell with above number
                            return true;		//then return true
                            
                            else board[i][j] = '.';//otherwise store back the vacant symbol so that next recursive calls can
                            						//explore other options
                        }
                    }
                    return false;//since in the above loop we were trying filling different values in the vacant cell 
                    //hence we have to return a default value in case if none of the value worked for the solution
					//crossed all possible values from 1 to 9 and hasn't returned true for any possible value
                }
            }
            
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
