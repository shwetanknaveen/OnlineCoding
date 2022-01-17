//Problem link - https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int len = s.length();
        int i;
        for(i=0;i+k<=len;i=i+k)
            ans.push_back(s.substr(i,k));
        int remLength = len%k;
        if(remLength!=0)
        {
            string temp = s.substr(i,len-i);
            remLength = k-len%k;;//how many fill characters we have to fill
            while(remLength)
            {
                temp.push_back(fill);
                remLength--;
            }
            ans.push_back(temp);
                
        }
        return ans;
        
    }
};
