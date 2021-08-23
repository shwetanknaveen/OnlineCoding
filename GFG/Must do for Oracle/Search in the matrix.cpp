//Problem link - https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1

class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int n, int m, int x)
	{
	    // your code here
	    if (n == 0||m==0)
        return 0;
   
    int smallest = mat[0][0], largest = mat[n - 1][m - 1];
    if (x < smallest || x > largest)
        return 0;
   
    // set indexes for top right element
    int i = 0, j = m - 1;//we have option for both smaller and larger if we start from either top right or bottom left
    while (i < n && j >= 0)
    {
        if (mat[i][j] == x)
        {
            return 1;
        }
        if (mat[i][j] > x)
            j--;
        else
            i++;
    }
    return 0;
	}
};
