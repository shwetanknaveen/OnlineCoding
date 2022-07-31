//Problem link - https://leetcode.com/problems/word-subsets/

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26,0);
        for(auto wordIn2:words2)
        {
            vector<int> thisFreq(26,0);
            for(auto c:wordIn2)
                thisFreq[c-'a']++;
            for(int i=0;i<26;i++)
                maxFreq[i] = max(maxFreq[i],thisFreq[i]);
        }
        vector<string> ans;
        for(auto wordIn1:words1)
        {
           vector<int> thisFreq(26,0);
           bool isUniv = true;
           for(auto c:wordIn1)
               thisFreq[c-'a']++;
           for(int i=0;i<26;i++)
           {
             if(thisFreq[i]<maxFreq[i])
             {
                 isUniv = false;
                 break;
             }
           }
           if(isUniv) ans.push_back(wordIn1);
        } 
        
        return ans;
    }
};
