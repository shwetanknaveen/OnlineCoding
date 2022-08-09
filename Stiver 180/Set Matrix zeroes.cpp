//Problem link - https://leetcode.com/problems/set-matrix-zeroes/
//Video link - https://www.youtube.com/watch?v=M65xBewcqcI&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=8
//Time complexity - O(mn) Space complexity O(1)
/*
Setting of zeroes shouldn't be cascaded that is if because of one zero, a cell is set
zero...then that cell shouldn't force other cells in its row and column to be zeroes
*/
//Approach 1 (Brute Force) -> Time complexity - O(mn) Space complexity - O(m+n)
//Save rows and columns in two maps rows and columns of those cells which have 0s and then traverse the matrix and set all 
//cells 0 depending on this
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,int> row,col;
        int rows = matrix.size(), cols = matrix[0].size();
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(matrix[i][j] == 0)
                    row[i] = col[j] = 1;
            }
        }
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(row[i] || col[j])
                    matrix[i][j] = 0;
            }
        }
    }
};

//Approach 2
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

        //IMPORTANT - first column has to be dealt seperately with the flag col0
        //why it is done see in the video at 6:30 and 8:50
        
    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = 0;//if there is 0 anywhere in first column then set col0 as 0
        for (int j = 1; j < cols; j++)//first column is dealt seperately in above line
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;//flag the leftmost and topmost cell as 0
    }

    for (int i = rows - 1; i >= 0; i--) {//traverse from back
        for (int j = cols - 1; j >= 1; j--)//till second column
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0) matrix[i][0] = 0;//first column is dealt seperately here
		//if flag col0 is 0 then set the first column cell as 0
    }
    }
};
