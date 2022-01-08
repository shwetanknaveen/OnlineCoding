/*Here when we fill the dp matrix using top down approach we assume that i and j are ending indices in string A and B
Hence maximum value of dp is when we start from beginning of both strings i.e., at dp[l1-1][l2-1].
*/

class Solution {
public:
    int LCS(string &A,string &B,int &l1,int &l2,int ind1,int ind2,vector<vector<int>> &dp)
    //passing string A and B not as reference thrown TLE since it had to be copied many time
    {
        if(ind1<0 || ind2<0) return 0;//if we are searching outside the strings then there can't be common subsequence
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(A[ind1] == B[ind2]) 
        dp[ind1][ind2] = (1 + LCS(A,B,l1,l2,ind1-1,ind2-1,dp));//if this character is same in both the strings then count this
        														//character in common part and count the common subsequence in remaining 
        														//part
        
        else 
        dp[ind1][ind2] = max(LCS(A,B,l1,l2,ind1-1,ind2,dp),LCS(A,B,l1,l2,ind1,ind2-1,dp));
        				//if current character is not same then we can skip this character from either of string
        
        return dp[ind1][ind2];
    }
    
    /*INTUTION for shortest common supersequence->We right both strings but include LCS part only once
    
    */
    string shortestCommonSupersequence(string str1, string str2) {
        int l1=str1.length(), l2=str2.length();
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,-1));
        int LCSlen = LCS(str1,str2,l1,l2,l1-1,l2-1,dp);
        string SCSstring;
        int i=l1-1,j=l2-1;
        while(i>=0 && j>=0)//any of i and j can't exceed string boundaries
        {
            if(str1[i]==str2[j])
            {
                SCSstring.push_back(str1[i]);//push the common part only once
                i--;	//moving towards 
                j--;	//upper left corner
            }
            
            else if (j==0){//if second string has been reached to its starting index and this character didn't match
                SCSstring.push_back(str1[i]);
                i--;
            }
            
            else if (i==0){//if first string has been reached to its starting index and this character didn't match
                SCSstring.push_back(str2[j]);
                j--;
            }
            
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    SCSstring.push_back(str1[i]);//We are about to move up hence we will miss one character from first 
                    							//string so we have to push it in our ans first
                    i--;
                }
                else
                {
                    SCSstring.push_back(str2[j]);//We are about to move left hence we will miss one character from second 
                    							//string so we have to push it in our ans first
                    j--;	//moving towards max cell
                }
            }
        }
        while(i>=0)//pushing the remaining part of string 1
            SCSstring.push_back(str1[i--]);
        while(j>=0)//pushing the remaining part of string 2
            SCSstring.push_back(str2[j--]);
        reverse(SCSstring.begin(),SCSstring.end());
        //We don't have to reverse as i and j were our starting indices and we started from top left of our dp matrix
        //hence we got our supersequence in right order
        
        return SCSstring;
        
    }
};
