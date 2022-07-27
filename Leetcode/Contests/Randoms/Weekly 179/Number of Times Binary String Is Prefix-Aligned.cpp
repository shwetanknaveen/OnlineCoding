//Problem link - https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned/

class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        set<int> indexSetToOne;
        int ans = 0;
        for(int i:flips)
        {
            indexSetToOne.insert(i);//This index has been set to 1 from 0
            if(*(indexSetToOne.rbegin())==indexSetToOne.size())//If indexSetToOne.size()=7 and last element of indexSetToOne is 7 then it
                ans++;                                      //means that indexSetToOne has numbers from 1 to 7.
        }
        return ans;
            
    }
};
