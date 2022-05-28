//Problem link - https://leetcode.com/problems/sender-with-largest-word-count/

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int> mp;
        for(int i=0;i<messages.size();i++)
        {
            int wC = 1;
            for(char c:messages[i])
            {
                if(c==' ')
                    wC++;
            }
            mp[senders[i]] += wC;
        }
        string ans;
        int maxCount = INT_MIN;
        for(auto itr=mp.begin();itr != mp.end();itr++)//map keys are sorted in lexicographical order
                                                    //hence in this way we will pick lexicographically largest key if more than one key have same word count
        {
            if(itr->second>=maxCount)
            {
                ans = itr->first;
                maxCount = itr->second;
            }
        }
        return ans;
            
    }
};
