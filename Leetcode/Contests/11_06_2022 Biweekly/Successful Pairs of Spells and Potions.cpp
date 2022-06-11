//Problem link - https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& sp, vector<int>& pot, long long suc) {
        sort(pot.begin(),pot.end());
        vector<int> ans;
        long prod;
        for(int i:sp)
        {
            long search = ceil(double(suc)/i);//potion index which first satisy the success criteria -> pot * i >= suc
            if(search>1e5)//this value won't exist in potion 
            {
                ans.push_back(0);
                continue;
            }
            int ind = lower_bound(pot.begin(),pot.end(),search)-pot.begin();
            if(ind==pot.size()) ans.push_back(0);
            else ans.push_back(pot.size()-ind);
        }
        return ans;
    }
};
