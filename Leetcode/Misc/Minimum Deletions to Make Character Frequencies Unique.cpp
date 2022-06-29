//Problem link - https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(char c:s)
            freq[c-'a']++;
        sort(freq.rbegin(),freq.rend());
        int reqDel = 0,available = INT_MAX;
        for(int f:freq)
        {
            if(f>available)
            {
                reqDel += f-available;//now present available won't be available anymore and it has to be reduced by 1
            }
            else
            {
                available = f;//acutally available will be f-1 which will be done below in available--
            }
            available--;
            if(available<0) available = 0;//0 is always available
        }
        
        
        return reqDel;
    }
};
