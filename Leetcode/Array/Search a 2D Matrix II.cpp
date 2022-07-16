//Problem link - https://leetcode.com/problems/search-a-2d-matrix-ii/

//Start form top right
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row = matrix.size(), cols = matrix[0].size(), i = 0, j = cols-1;
        while(i<row && j>=0)
        {
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
                j--;
            else i++;
        }
        return false;
    }
};
