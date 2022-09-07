//Problem link - https://leetcode.com/problems/check-distances-between-same-letters/

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) 
    {
        unordered_map<char,int> firstOccr;
        for(int i=0;i<s.length();i++)
        {
            if(firstOccr.find(s[i])==firstOccr.end())
            {
                firstOccr[s[i]] = i;
            }
            else
            {
                int thisDist = i-firstOccr[s[i]]-1;
                if(thisDist != distance[s[i]-'a']) return false;
            }
        }
        return true;
    }
};
