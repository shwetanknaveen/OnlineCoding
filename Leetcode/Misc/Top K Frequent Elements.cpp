//Problem link - https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i:nums)
            mp[i]++;
        vector<pair<int,int>> freqNum;
        for(auto p:mp)
            freqNum.push_back(make_pair(p.second,p.first));
        sort(freqNum.rbegin(),freqNum.rend());//Sort in descending order as per frequencies
        vector<int> ans;
        for(auto p:freqNum)
        {
            if(k--)//Push top k frequncies numbers
                ans.push_back(p.second);
            else break;
        }
        
        return ans;
    }
};
