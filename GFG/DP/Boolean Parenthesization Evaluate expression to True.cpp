//Problem link - https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1/#
//Video link - Recursion code -> https://www.youtube.com/watch?v=pGVguAcWX4g&lc=Ugx3sFAkrcFhkLuM84V4AaABAg
//Memoization - https://www.youtube.com/watch?v=bzXM1Zond9U&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=39

//Variation of matrix chain multiplication format
class Solution{
public:
	//i and j will always be pointing to T or F
    int solve(string &S,int i,int j,bool isReqTrue,vector<vector<vector<int>>> &dp)
    {
        //if(i>j) return 0;//no character hence no way to get T/F basically no need for this base condition or for saftey it 
        //has been merged below
        if(i>=j)//one character is pointed
        {
            if(isReqTrue) return (S[i]=='T');//if true was required and here we have true then return 1 else return 0
            else return (S[i]=='F');//if false was required and here we have false then return 1 else return 0
        }
        
        if(dp[i][j][isReqTrue] != -1) return dp[i][j][isReqTrue];
        int ans = 0;
        for(int k=i+1;k<=j-1;k=k+2)//k will always point to a operator and will break
                                    //the epression in two parts, one from i to k-1 and 
                                    //one from k+1 to j
        {
            int lT = solve(S,i,k-1,true,dp);//number of parenthesization ways to evaluate left expression to true
            int lF = solve(S,i,k-1,false,dp);//number of parenthesization ways to evaluate left expression to false
            int rT = solve(S,k+1,j,true,dp);//number of parenthesization ways to evaluate right expression to true
            int rF = solve(S,k+1,j,false,dp);//number of parenthesization ways to evaluate right expression to false
            
            if(S[k] == '&')
            {
                if(isReqTrue)//if true was required
                    ans += lT * rT;//both expressions around & should be true
                else
                    ans += lF*rF + lF*rT + lT*rF;
            }
            if(S[k] == '^')
            {
                if(isReqTrue)
                    ans += lF * rT + lT * rF;
                else
                    ans += lT*rT + lF*rF;
            }
            if(S[k] == '|')
            {
                if(isReqTrue)
                    ans += lT * rT +  lF*rT + lT*rF;
                else
                    ans += lF*rF;
            }
        }
        return dp[i][j][isReqTrue] = ans%1003;
    }
    int countWays(int N, string S){
        int i=0;
        int j=N-1;//i and j will always be pointing to T or F
        
        //We know that dimensions of dp depend upon no. of variables whose value change in function calls
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(N+1,vector<int>(2,-1)));
        return solve(S,i,j,true,dp);
    }
};


