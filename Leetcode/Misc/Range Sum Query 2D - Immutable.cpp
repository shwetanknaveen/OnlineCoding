//Problem link - https://leetcode.com/problems/range-sum-query-2d-immutable/
//Self explanation video - https://youtu.be/eEMqQsqrGFg

class NumMatrix {
public:
    vector<vector<int>> pref;
    int row,col;
    NumMatrix(vector<vector<int>>& matrix) {
        row = matrix.size();
        col = matrix[0].size();
        pref.resize(row,vector<int>(col));
        pref[0][0] = matrix[0][0];
        for(int i=1;i<row;i++)
            pref[i][0] = pref[i-1][0] + matrix[i][0];
        
        for(int j=1;j<col;j++)
            pref[0][j] = pref[0][j-1] + matrix[0][j];
        
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                pref[i][j] = pref[i-1][j] + pref[i][j-1] + matrix[i][j] - pref[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (pref[row2][col2] - (row1>0 ? pref[row1-1][col2] : 0) - (col1>0 ? pref[row2][col1-1] : 0)) + (row1>0 && col1>0 ? pref[row1-1][col1-1] : 0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
