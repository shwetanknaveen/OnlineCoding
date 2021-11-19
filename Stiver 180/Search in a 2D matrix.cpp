//Problem link - https://leetcode.com/problems/search-a-2d-matrix/
//Video link - https://www.youtube.com/watch?v=ZYpYur0znng&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=15

//This problem is little different than that which is one gfg
//https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1
//Here additionaly it is given that first element of row is larger than the last element of the last row

//Time complexity - O(row + column) approach
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(),cols=matrix[0].size();
        int i=0,j=cols-1;//When we are at top right of given matrix we have option to go for both smaller and larger elements
        while(i<=rows-1 && j>=0)
        {
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target) i++;//go in below row where there are larger elements
            else j--;//go to previous columns where there are smaller elements
        }
        return false;//default case if condition of while loop is not met and target hasn't been found yet
    }
};

//Striver's new approach of utilising the fact that first element of row is larger than the last element of the last row
//Time complexity -> O(log(mn))
//Here we see that if all the rows are placed side by side serially then they form a sorted array.
//index of that sorted array corresponds to index/(no. of columns) row and index%(no. of columns) column
//i.e., arr[index] = matrix[index/(no. of columns)][index%(no. of columns)]

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;//if matrix is empty
        
        int rows = matrix.size(), cols = matrix[0].size();
		int lo = 0;
        int hi = (rows * cols) - 1;//rows * cols give no. of elements in the matrix
        
        while(lo <= hi) {
            int mid = (lo + (hi - lo) / 2);
            if(matrix[mid/cols][mid % cols] == target) {
                return true;
            }
            if(matrix[mid/cols][mid % cols] < target) {
                lo = mid + 1;//search on right side
            }
            else {
                hi = mid - 1;//search on left side
            }
        }
        return false;//default case
    }
};

