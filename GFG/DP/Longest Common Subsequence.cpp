//Problem link - https://leetcode.com/problems/longest-common-subsequence/
//Video link - https://www.youtube.com/watch?v=hR3s9rGlMTU&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=21

//VERY VERY IMPORTANT NOTE-> IT IS NOT NECESSARY THAT DP MATRIX IS FILLED SAME IN BOTH TOP DOWN AND BOTTOM UP METHOD
//HERE FOR EXAMPLE DP[i][j] IN TOP DOWN METHOD MEANS i and j AS STARTING INDICES AND IN BOTTOM UP METHOD AS ENDING INDICES
//OF THE STRINGS


class Solution {
public:
	/*
	dp[i][j] is the length of longest common subsequence in string A from index 0 to i and string B from index 0 to j
	*/
    int LCS(string &A,string &B,int &l1,int &l2,int ind1,int ind2,vector<vector<int>> &dp)
    //passing string A and B not as reference thrown TLE since it had to be copied many time
    {
        if(ind1>=l1 || ind2>=l2) return 0;//if we are searching outside the strings then there can't be common subsequence
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(A[ind1] == B[ind2]) 
        dp[ind1][ind2] = (1 + LCS(A,B,l1,l2,ind1+1,ind2+1,dp));//if this character is same in both the strings then count this
        														//character in common part and count the common subsequence in remaining 
        														//part
        
        else 
        dp[ind1][ind2] = max(LCS(A,B,l1,l2,ind1+1,ind2,dp),LCS(A,B,l1,l2,ind1,ind2+1,dp));
        				//if current character is not same then we can skip this character from either of string
        
        return dp[ind1][ind2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int l1=text1.length(), l2=text2.length();
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,-1));
        int ans = LCS(text1,text2,l1,l2,0,0,dp);
		/* //CODE TO PRINT THE ACTUAL LCS
		string LCSsubseq = "";
        int i=l1,j=l2;
        while(i>0 && j>0)//if any of i or j is 0 then corresponding string is empty
        {
            if(text1[i-1]==text2[j-1])
            {
                LCSsubseq.push_back(text1[i-1]);
                i--;	//moving towards 
                j--;	//upper left corner
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                    i--;
                else j--;	//moving towards max cell
            }
        }
        reverse(LCSsubseq.begin(),LCSsubseq.end());
        cout<<"LCS = "<<LCSsubseq<<endl;

		//ABOVE CODE WORKS WHEN WE HAVE FILLED DP USING BOTTOM UP METHOD AND THERE DP[L1][L2] CONTAINS THE MAXIMUM VALUE
		//BUT WHEN WE FILL THE DP USING TOP DOWN METHOD,OUT MAX VALUE IS IN DP[0][0] SINCE HERE IN TOP DOWN CODE ind1 and
		//ind2 ARE STARTING INDICES HENCE WE FIND LCS IN FOLLOWING WAY
		
		string LCSsubseq = "";
        int i=0,j=0;
        while(i<l1 && j<l2)
        {
            if(text1[i]==text2[j])
            {
                LCSsubseq.push_back(text1[i]);
                i++;//moving towards
                j++;//lower right corner
            }
            else
            {
                if(dp[i+1][j]>dp[i][j+1])
                    i++;
                else j++;//moving towards max cell
            }
        }
        //Here no need to reverse as i and j were our starting indices hence we got the subsequence in right order
        cout<<"LCS = "<<LCSsubseq<<endl;
        
		*/
		
		
        return ans;
    }
};
