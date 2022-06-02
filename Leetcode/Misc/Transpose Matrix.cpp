//Problem link - https://leetcode.com/problems/transpose-matrix/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> trans(cols,vector<int>(row));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<cols;j++)
            {
                trans[j][i] = matrix[i][j];
            }
        }
        return trans;
    }
};
