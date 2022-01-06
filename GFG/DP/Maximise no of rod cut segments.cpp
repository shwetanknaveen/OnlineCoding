//Problem link - https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#


//Approach 1-> Bottom up approach
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        
        //if n is the rod length and possble cut lengths are x,y and z then we have to n1+n2+n3 such that
        //							x*n1 + y*n2 + z*n3 = n and
        //							n1 + n2 + n3 is maximum
        
        vector<int> dp(n+1,-1);//initialise it with -1
        //dp[i] indicates maximum number of segments in the length i
        dp[0] = 0;//in zero length rod 0 segments are possible
        for(int i=0;i<=n;i++)
        {
            if(dp[i]==-1)
            continue;//no segments are possible to cut with rod length of i
            
            if(i+x <= n)
            dp[i+x] = max(1+dp[i],dp[i+x]);//max possible no. of segments with rod length = i+x is max(1,2) 
            								//1- We cut x length then we got 1 segment and add it to no. of segments which we can get in length = (i+x)-x=i i.e., dp[i]
            								//2- We don't cut the rod of length i+x
            
			if(i+y <= n)
            dp[i+y] = max(1+dp[i],dp[i+y]);//max possible no. of segments with rod length = i+y is max(1,2) 
            								//1- We cut y length then we got 1 segment and add it to no. of segments which we can get in length = (i+y)-y=i i.e., dp[i]
            								//2- We don't cut the rod of length i+y
            
            if(i+z <= n)
            dp[i+z] = max(1+dp[i],dp[i+z]);//max possible no. of segments with rod length = i+z is max(1,2) 
            								//1- We cut z length then we got 1 segment and add it to no. of segments which we can get in length = (i+z)-z=i i.e., dp[i]
            								//2- We don't cut the rod of length i+z
            
        }
        return dp[n]==-1 ? 0 : dp[n];
    }
};

//Approach 2-> Top down approach

//if n is the rod length and possble cut lengths are x,y and z then we have to n1+n2+n3 such that
        //							x*n1 + y*n2 + z*n3 = n and
        //							n1 + n2 + n3 is maximum
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int getAns(int n,int x,int y,int z,vector<int> &dp)
    {
        if(n==0) return 0;
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
