//Problem link - https://leetcode.com/problems/word-search/

class Solution {
public:
    bool dfs(int ind,int i,int j,vector<vector<bool>> &vis,string &word,vector<vector<char>> &board,int &rows,int &cols)
    {
        if(i<0 || i>=rows || j<0 || j>=cols || vis[i][j] || word[ind] != board[i][j]) return false;
        if(ind==word.size()-1) return true;//last character of word has been successfully matched
        
        vis[i][j] = true;
        bool left = dfs(ind+1,i-1,j,vis,word,board,rows,cols);
        bool right = dfs(ind+1,i+1,j,vis,word,board,rows,cols);
        bool up = dfs(ind+1,i,j-1,vis,word,board,rows,cols);
        bool down = dfs(ind+1,i,j+1,vis,word,board,rows,cols);
        vis[i][j] = false;
        
        return left || right || up || down;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> vis(rows,vector<bool>(cols,false));
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(dfs(0,i,j,vis,word,board,rows,cols)) return true;
            }
        }
        return false;
    }
};
