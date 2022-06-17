//Problem link - https://leetcode.com/problems/longest-string-chain/
//See problem "Leetcode/Dynamic Programming/Largest Divisible Subset"
class Solution {
public:
    static bool cmp(string &s1,string &s2)//sort in ascending order of string length
    {
        return s1.length()<s2.length();//If we do <= here, it will throw heap overflow error because of comparator property violation
        								// https://stackoverflow.com/a/52745280/6743289
    }
    bool check(string &pred,string &succ)
    {
        if(succ.length()-pred.length() != 1) return false;//successor word must has exactly one character more than predecessor word
        bool skip = true;
        int i,j;
        for(i=0,j=0;i<pred.length();)
        {
            if(pred[i]!=succ[j])
            {
                if(skip)//if this character is not same and this is happening for the first time then this word will be added in predecessor
                {
                    skip = false;
                    j++;//skip this character in successor word and look for matching other characters
                }
                else return false;//if this mismatch is not for the first time then return false
            }
            else
            {
                i++;
                j++;
            }
        }
        return true;
    }
    //lastInd is index of word in words which was last picked in current set(hypothetically as we are not maintaining any set, we just need its size)
    void solve(vector<string> &words,int lastInd,int ind,vector<int> &dp,int &ans,int tempCount)
    {
        if(ind>=words.size()) 
        {
            ans = max(ans,tempCount);
            return;
        }
        if(lastInd==-1 || (check(words[lastInd],words[ind]) && dp[ind]<tempCount))
        {
            dp[ind] = tempCount;
            solve(words,ind,ind+1,dp,ans,tempCount+1);//this word can be picked
        }
        solve(words,lastInd,ind+1,dp,ans,tempCount);//leave this word and look for other words
    }
    int longestStrChain(vector<string>& words) 
    {
        sort(words.begin(),words.end(),cmp);
        int nWords = words.size();
        vector<int> dp(nWords,0);
        int ans = 0;
        solve(words,-1,0,dp,ans,0);
        return ans;
    }
};
