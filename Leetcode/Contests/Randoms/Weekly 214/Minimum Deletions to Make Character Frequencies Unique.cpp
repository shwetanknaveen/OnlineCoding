//Problem link - https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
//See same question -> "Leetcode/Misc/Minimum Deletions to Make Character Frequencies Unique"
class Solution {
public:
    int minDeletions(string s) {
        map<char,int> freq;
        int maxFreq = 0;
        for(char c:s)
        {
            freq[c]++;
        }
        int ans = 0;
        priority_queue<int> pq;
        for(auto p:freq)
            pq.push(p.second);
        
        int last = INT_MAX;
        while(!pq.empty())
        {
            int thisFreq = pq.top(),del;
            if(thisFreq>=last)
            {
                if(last==0)
                {
                    del = thisFreq;//delete all
                }
                else
                {
                    del = max(0,thisFreq-(last-1));//delete such that it becomes less than 1 by last freq
                    if(del==thisFreq)
                        last = 0;
                    else
                        last = last-1;
                }
                ans +=del;
            }
            else
            {
                last = thisFreq;
            }
            pq.pop();
        }
        return ans;
    }
};
