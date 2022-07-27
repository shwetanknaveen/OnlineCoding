//Problem link - https://leetcode.com/problems/lucky-numbers-in-a-matrix/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> minInRow,maxInCol,ans;
        for(int i=0;i<matrix.size();i++)
        {
            int mini = INT_MAX;
            for(int j=0;j<matrix[0].size();j++)
            {
                mini = min(mini,matrix[i][j]);
            }
            minInRow.push_back(mini);
        }
        
        for(int j=0;j<matrix[0].size();j++)
        {
            int maxi = INT_MIN;
            for(int i=0;i<matrix.size();i++)
            {
                maxi = max(maxi,matrix[i][j]);
            }
            maxInCol.push_back(maxi);
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == minInRow[i] && matrix[i][j] == maxInCol[j])
                    ans.push_back(matrix[i][j]);
            }
        }
        return ans;
        
    }
};

