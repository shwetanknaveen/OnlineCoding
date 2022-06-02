//Problem link - https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(),cols = matrix[0].size();
        for(int row = 0;row<rows;row++)//store the row-wise prefix sum in each cell
        {
            for(int col = 1;col<cols;col++)
            {
                matrix[row][col] += matrix[row][col-1];
            }
        }
        
        int ans = 0;
        //Now we have to count number of subsets in this column which has sum = target. Sum of all elements in each row
        //is stored at last cell of every row at rightBound
        
        //Using concept of ( https://leetcode.com/problems/subarray-sum-equals-k/ ) column wise
        for(int leftBound = 0;leftBound<cols;leftBound++)
        {
            for(int rightBound = leftBound;rightBound<cols;rightBound++)
            {
                unordered_map<int,int> mp;
                mp[0] = 1;
                int currSum=0;//Prefix sum of this colum at right end boundary
                for(int row = 0;row<rows;row++)
                {
                    currSum += matrix[row][rightBound] - (leftBound==0 ? 0 : matrix[row][leftBound-1]);
                    ans += mp[currSum-target];
                    mp[currSum]++;
                }
            }
        }
        return ans;
    }
};
