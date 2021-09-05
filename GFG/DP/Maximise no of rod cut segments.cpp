//Problem link - https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#

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
