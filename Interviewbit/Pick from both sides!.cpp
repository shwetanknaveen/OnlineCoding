//Problem link - https://www.interviewbit.com/problems/pick-from-both-sides/

//Approach 1 -> Dynamic apporach
int helper(vector<int> &A,int i,int j,int B,vector<vector<int>> &dp)
{
    if(B==0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = max(A[i]+helper(A,i+1,j,B-1,dp),A[j]+helper(A,i,j-1,B-1,dp));
}
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return helper(A,0,n-1,B,dp);
}

/*
WHY CHANGING B DOESN'T PLAY ROLE IN DP MATRIX DIMENSION

dp[i][j] represents the maximum sum in the array considering it from ith to jth index.
We can pass a constant n which is number of elements in the array A and then we can write base case of recursion in terms of i,j and n.
At any moment, number of numbers selected is = (i+(n-1-j))


*/

//Approach 2 -> Greedy approach

int Solution::solve(vector<int> &A, int B) {
    int ans = 0,n=A.size();
    int i,j,incl,excl;
    for(i=0;i<B;i++)
        ans += A[i];
    i--;//We make the first window from extreme left of size B. i points to the last element taken in the window.
    
    //Now we will start looking from right side and check that we can take numbers from right side at cost of dropping numbers at right side
    //of first window such that cost is maximised
    int pres = ans;//Present sum is ans
    for(j=n-1;j>=n-1-B;j--)//if all the numbers are taken from right side then in that case, index of leftmost taken number will be n-1-B
    {
        incl = A[j];//this number will be included
        excl = A[i--];//this number will be excluded
        pres = pres+incl-excl;//after inclusion and exclusion, sum will be pres
        ans = max(ans,pres);//final answer has to be maximum
    }
    return ans;
}

