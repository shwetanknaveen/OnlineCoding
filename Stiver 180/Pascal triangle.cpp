//Problem link - https://leetcode.com/problems/pascals-triangle/submissions/
//Video link - https://www.youtube.com/watch?v=6FLvhQjZqvM&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=8
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++)
        {
            ans.push_back(vector<int>());//this way values are push_back() in 2d vector
            for(int j=0;j<=i;j++)
            {
                if((i-1)>=0)//we can go one row above
                {
                    if((j-1)>=0 && j!=i)//we can go one column back in above row and this is not last column which means value just above this value exists
                    {
                        ans[i].push_back(ans[i-1][j] + ans[i-1][j-1]);//this way values are push_back() in 2d vector
                        											  //sum of above value and its left value
                    }
                    else if((j-1)>=0)//we can go one column back in above row but this is last column which means value just above this value doesn't exist
                    {
                        ans[i].push_back(ans[i-1][j-1]);//this way values are push_back() in 2d vector
                    }
                    else//first column
                    {
                        ans[i].push_back(1);//this way values are push_back() in 2d vector
                    }
                }
                else//we can't go one row above as this is the first row
                {
                    ans[i].push_back(1);//this way values are push_back() in 2d vector
                }
            }
        }
        return ans;
    }
};

/*
for rows = 5
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/

//Pascal value at r row and c column is (r-1)C(c-1)



//Striver best solution
/*
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows);//give value for number of rows

        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);//no. of column in each row is row number and here indexing is from zero
            r[i][0] = r[i][i] = 1;//first and last value is 1
  
            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];//values from second column upto second last column is sum of value just above it and its left value
        }
        
        return r;
    }
};
*/

