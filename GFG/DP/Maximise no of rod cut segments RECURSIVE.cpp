//Problem link - https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#

//if n is the rod length and possble cut lengths are x,y and z then we have to get n1+n2+n3 such that
        //							x*n1 + y*n2 + z*n3 = n and
        //							n1 + n2 + n3 is maximum
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int getAns(int n,int x,int y,int z,vector<int> &dp)
    {
        if(n==0) return 0;//If rod has length zero then no division possible
        if(n<0) return INT_MIN;//Here we must have violated the condition that x*n1 + y*n2 + z*n3 = n


        
        if(dp[n] != -1) return dp[n];
        
        int n1,n2,n3;
        n1=n2=n3=0;
        
        n1 =1 + getAns(n-x,x,y,z,dp);//cut segment of length x
        
        
        n2 =1 + getAns(n-y,x,y,z,dp);//cut segment of length y
        
        
        n3 =1 + getAns(n-z,x,y,z,dp);//cut segment of length z
        
        dp[n] = max(max(n1,n2),n3);//return max of all three
        
        return dp[n];
        
        
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1,-1);
        int ans = getAns(n,x,y,z,dp);
        return ans>=0 ? ans : 0;//if dp[n] has negative value then it's division haven't been possible hence return 0
    }
};
