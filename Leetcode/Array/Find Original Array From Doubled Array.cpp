//Problem link - https://leetcode.com/problems/find-original-array-from-doubled-array/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) 
    {
        map<int,int> numFreq;
        for(int i:changed)
            numFreq[i]++;
        vector<int> ans;
        for(auto &p:numFreq)
        {
            if(p.second == 0)
                continue;//It has already been dealt with
         
            if(numFreq[p.first * 2] < p.second)
                return {};//Two times values are not enough for this hence returning {}
            
            if(p.first == 0)// Since 0 * 2 = 0 only
            {
                if(p.second & 1)
                {
                    //This value is 0 and it is not even in number
                    return {};//For two 0s in changed, there should be one 0 originally
                }
                p.second /= 2;
            }
            int pushTimes = p.second;//these many times this value exist in original array
            numFreq[p.first * 2] -= p.second;//2 x(thisValus) is used for this many time for this value
            while(pushTimes--)
                ans.push_back(p.first);
        }
        if(ans.size() != changed.size()/2)//Original size is not half hence returning {}
            return {};
        return ans;
    }
};
