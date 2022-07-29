//Problem link - https://leetcode.com/problems/find-and-replace-pattern/

class Solution {
public:
    bool isMatch(string &word,string &patt,int &len)
    {
        unordered_map<char,char> pattToWord,wordToPatt;
        for(int i=0;i<len;i++)
        {
            if(pattToWord.find(patt[i])==pattToWord.end() && wordToPatt.find(word[i])==wordToPatt.end())
            {
                pattToWord[patt[i]] = word[i];
                wordToPatt[word[i]] = patt[i];
            }
            else if(pattToWord[patt[i]] != word[i] || wordToPatt[word[i]] != patt[i])//both way mapping should be same
                return false;
        }
        return true;
        
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int len = pattern.length();
        for(string word:words)
            if(isMatch(word,pattern,len))
                ans.push_back(word);
        
        return ans;
    }
};
