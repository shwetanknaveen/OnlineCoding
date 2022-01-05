//Problem link - https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/?category[]=Dynamic%20Programming&category[]=Dynamic%20Programming&page=4&query=category[]Dynamic%20Programmingpage4category[]Dynamic%20Programming#
//Aditya verma link - https://www.youtube.com/watch?v=_gPcYovP7wc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=7

class Solution{   
public:

    int recursiveSubsetSum(int N,int arr[],int sum,vector<vector<int>> &dp)
    {
    	//0 = false AND 1 = true
        if(sum == 0) return 1;//if required sum is 0 then it's always possible
        if(N == 0) return 0;//here obviously sum != 0 and hence sum is not possible with 0 element
        
        if(dp[N][sum] != -1) return dp[N][sum];
        
        if(sum>=arr[N-1])//if current element under consideration has weight<= required sum
        dp[N][sum] = (recursiveSubsetSum(N-1,arr,sum-arr[N-1],dp)) ==1 || (recursiveSubsetSum(N-1,arr,sum,dp) == 1)? 1 : 0;//if it was possible to get the sum either way, with or without choosing the element then we put 1(possible)
        			 /*We choose the element and subtract its weight		We leave the element and sum as it is*/
        else
        dp[N][sum] = recursiveSubsetSum(N-1,arr,sum,dp);//if current element under consideration has weight > required sum
        
        return dp[N][sum];
    }
    bool isSubsetSum(int N, int arr[], int sum){
        vector<vector<int>> dp(N+1,vector<int>(sum+1,-1));//initialise dp matrix with -1
                        
        return (recursiveSubsetSum(N,arr,sum,dp) == 1 ? true : false);
    }
    
    
};


////Above code with using index variable ind

class Solution{   
public:

    int recursiveSubsetSum(int N,int arr[],int sum,vector<vector<int>> &dp,int ind)
    {
    	//0 = false AND 1 = true
        if(sum == 0) return 1;//if required sum is 0 then it's always possible
        if(ind >= N) return 0;//here obviously sum != 0 and hence sum is not possible with 0 element
        	`				//if ind>=N, it means that we are exploring outside given array
        
        if(dp[N][sum] != -1) return dp[N][sum];
        
        if(sum>=arr[ind])//if current element under consideration has weight<= required sum
        dp[N][sum] = (recursiveSubsetSum(N,arr,sum-arr[ind],dp,ind+1)) ==1 || (recursiveSubsetSum(N,arr,sum,dp,ind+1) == 1)? 1 : 0;//if it was possible to get the sum either way, with or without choosing the element then we put 1(possible)
        			 /*We choose the element and subtract its weight		We leave the element and sum as it is*/
        else
        dp[N][sum] = recursiveSubsetSum(N,arr,sum,dp,ind+1);//if current element under consideration has weight > required sum
        
        return dp[N][sum];
    }
    bool isSubsetSum(int N, int arr[], int sum){
        vector<vector<int>> dp(N+1,vector<int>(sum+1,-1));//initialise dp matrix with -1
                        
        return (recursiveSubsetSum(N,arr,sum,dp,0) == 1 ? true : false);//initially we start exploring from the first index hence ind=0
    }
    
};
