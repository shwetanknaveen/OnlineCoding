//Problem link - https://leetcode.com/problems/sort-the-matrix-diagonally/

//Approach 1 => Plain implementation
class Solution {
public:
    bool isValid(int &i,int &j,int &row,int &col)
    {
        return (i<row && j<col);//As we are just increasing row and col hence just upper bound is checked
    }
    void nextStart(int &startRow,int &startCol)
    {
        if(startCol-1<0)//if we can't reduce column number
        {
            startCol = 0;
            startRow++;
        }
        else
        {
            startCol--;//startRow must be already 0
        }
    }
    vector<int> getSortedDiagonal(int &startRow,int &startCol,int &row,int &col,vector<vector<int>> &mat)
    {
        vector<int> res;
        int i = startRow, j= startCol;
        while(isValid(i,j,row,col))
        {
            res.push_back(mat[i++][j++]);
        }
        sort(res.begin(),res.end());
        return res;
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        int row = mat.size(), col = mat[0].size();
        int startCol = mat[0].size()-1,startRow=0, filled = 0,count = row*col;
        while(filled<count)
        {
            vector<int> res = getSortedDiagonal(startRow,startCol,row,col,mat);
            int i=startRow,j=startCol;
            for(int num:res)
            {
                mat[i++][j++] = num;
                filled++;
            }
            nextStart(startRow,startCol);//initiate startRow and startCol for next diagonal
        }
        return mat;
    }
};

//Approach 2 -> Using map

class Solution 
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        int row = mat.size(),col = mat[0].size();
        vector<vector<int>> ans(row,vector<int>(col));//Allocating different space for ans, we can do it in mat itself also as in approach 1
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>> rowColNum;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                rowColNum[i-j].push(mat[i][j]);
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                ans[i][j] = rowColNum[i-j].top();
                rowColNum[i-j].pop();
            }
        }
        return ans;
    }
};
