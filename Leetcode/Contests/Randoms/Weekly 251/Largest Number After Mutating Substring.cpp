//Problem link - https://leetcode.com/problems/largest-number-after-mutating-substring/
class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        for(int i=0;i<num.length();i++)
        {
            if(num[i]-'0' < change[num[i]-'0'])//Change the largeset window from MSB side
            {
                while(i<num.length() && num[i]-'0' <= change[num[i]-'0'])
                {
                    num[i] = char(change[num[i]-'0'] + '0');
                    i++;
                }
                break;
            }
        }
        return num;
    }
};
