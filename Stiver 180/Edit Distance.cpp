//Problem link - https://leetcode.com/problems/edit-distance/

//We are converting word1 to word2 here so changes will be done in word1
class Solution {
public:
    int helper(string &w1,string &w2,int ind1,int ind2,vector<vector<int>> &dp)
    {
           if(ind1 >= w1.length() && ind2 >= w2.length()){
               return 0;
           }  
           else if(ind1 >= w1.length()){
                return w2.length()-ind2;//these many characters have to be added in word1
            }
            else if(ind2 >= w2.length()){
                return w1.length() - ind1;//these many characters have to be deleted from word2
            }
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(w1[ind1] == w2[ind2])//if characters at this index match then no need of any operation and we have to look ahead for remaining characters
            dp[ind1][ind2] = helper(w1,w2,ind1+1,ind2+1,dp);
        
        else
        {
            int byInsert = 1+helper(w1,w2,ind1,ind2+1,dp);//We did insertion in word1 hence still the character at ind1
            											//which didn't match with character at ind2 is there hence we don't
            											//increase ind1. We inserted the character which is in word2 at index
            											//=ind2 at index just before ind1 in word1
            int byDel = 1+helper(w1,w2,ind1+1,ind2,dp);//We have deleted character at ind1 in word1 hence we move the index
            											//ind1 one ahead. Character at ind2 which didn't match is still there
            											//in word2 hence we don't increase ind2
            int byRep = 1+helper(w1,w2,ind1+1,ind2+1,dp);

			//Taking minimum of all 3
            dp[ind1][ind2] = min(byInsert,byDel);
            dp[ind1][ind2] = min(dp[ind1][ind2],byRep);
        }
        
        return dp[ind1][ind2];
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
        return helper(word1,word2,0,0,dp);
    }
};
