//Problem link - https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

//Approach 1 -> Brute Force T(n) = O((m x n)^2)

class Solution 
{
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
    {
        int ans = INT_MIN,nRow = matrix.size(), nCol = matrix[0].size();
        for(int i=0;i<nRow;i++)
        {
            for(int j=1;j<nCol;j++)
            {
                matrix[i][j] += matrix[i][j-1];//Prefix Row Sum
            }
        }
        for(int j=0;j<nCol;j++)
        {
            for(int i=1;i<nRow;i++)
            {
                matrix[i][j] += matrix[i-1][j];//Prefix Column Sum
            }
        }
        for(int endRow = 0;endRow<nRow;endRow++)
        {
            for(int endCol = 0;endCol<nCol;endCol++)
            {
                for(int startRow = 0;startRow<=endRow;startRow++)
                {
                    for(int startCol = 0;startCol<=endCol;startCol++)
                    {
                        int rectSum = matrix[endRow][endCol],sub = 0,add = 0;
                        if(startRow>0)//For 1 -> Subtracting upper rectangle
                        {
                            sub += matrix[startRow-1][endCol];
                        }
                        if(startCol>0)//For 2 -> Subtracting left rectangle 
                        {
                            sub += matrix[endRow][startCol-1];
                        }
                        if(startRow>0 && startCol>0)//For 3 -> Adding two times subtracted top left corner rectangle
                        {
                            add = matrix[startRow-1][startCol-1];
                        }
                        rectSum = rectSum + add - sub;
                        if(rectSum<=k)
                            ans = max(ans,rectSum);
                        if(ans == k) return k;//if ans has reached k then no more optimisation possible
                    }
                }
            }
        }
        return ans;
    }
};

//Approach 2 - 
//See "Leetcode/Array/Subarray Sum Equals K" and "Leetcode/Misc/Number of Submatrices That Sum to Target"
//T(n) = O(n x m x n x log(m))

class Solution 
{
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
    {
        int ans = INT_MIN,nRow = matrix.size(), nCol = matrix[0].size();
        for(int i=0;i<nRow;i++)
        {
            for(int j=1;j<nCol;j++)
            {
                matrix[i][j] += matrix[i][j-1];//Prefix Row Sum
            }
        }
        
        for(int startCol = 0;startCol<nCol;startCol++)
        {
            for(int endCol = startCol;endCol<nCol;endCol++)
            {
                set<int> prefSum;
                prefSum.insert(0);//there is always empty submatrix having zero sum
                int thisSum = 0;
                for(int row=0;row<nRow;row++)
                {
                    thisSum += matrix[row][endCol];
                    if(startCol>0)//Whether we can remove the left part which is on left of startCol
                        thisSum -= matrix[row][startCol-1];
                    auto itr = lower_bound(prefSum.begin(),prefSum.end(),thisSum-k);
                    /*
                    	*itr >= thisSum - k
                    ==>	-*itr <= -(thisSum - k)
                    ==>	thisSum-*itr <= thisSum - (thisSum - k)
                    ==>	thisSum-*itr <= k
                    */
                    if(itr != prefSum.end())
                    {
                        ans = max(ans,thisSum - *itr);
                        if(ans == k) return ans;
                    }
                    prefSum.insert(thisSum);//Now insert this prefix sum in the set
                }
            }
        }
        return ans;
    }
};

