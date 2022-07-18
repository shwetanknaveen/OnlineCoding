//Problem link - https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int low = matrix[0][0], high = matrix[matrix.size()-1][matrix[0].size()-1], mid;
        while(low<=high)
        {
            mid = low + (high-low)/2;
            int count = countLessOrEqual(matrix,mid);
            
            if(count<k) low = mid+1;//Search on the larger number sides
            else high = mid-1;
        }
        return low;
    }
    //Start from bottom left
    int countLessOrEqual(vector<vector<int>> &matrix,int num)
    {
        int i = matrix.size()-1, j = 0, count = 0;
        while(i>=0 && j<matrix[0].size())
        {
            if(matrix[i][j] > num) i--;//Go for smaller elements
            else
            {
                count = count + i + 1;//All the elements in this cloumn above this row including this are <=num
                j++;//Go for larger elements
            }
        }
        return count;
    }
};
