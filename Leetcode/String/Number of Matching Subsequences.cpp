//Problem link - https://leetcode.com/problems/number-of-matching-subsequences/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> charInd(26);
        for(int i=0;i<s.length();i++)//Save all the indices for characters in s in increasing order in charInd
            charInd[s[i]-'a'].push_back(i);
        int ans = 0;
        for(auto word:words)
        {
            bool matchedComplete = true;
            int presentInd = -1;//Initial matching character can be at 0th index also in s which is greater than -1
            for(char c:word)
            {
                auto nextMatchingAtInd = upper_bound(charInd[c-'a'].begin(),charInd[c-'a'].end(),presentInd);//which just next index in s matches with this character c in word
                if(nextMatchingAtInd==charInd[c-'a'].end())//there is no char c in s ahead
                {
                    matchedComplete = false;
                    break;
                }
                else presentInd = *nextMatchingAtInd;//advance the pointer directly to that charcter in s
            }
            if(matchedComplete) ans++;
        }
        return ans;
    }
};
