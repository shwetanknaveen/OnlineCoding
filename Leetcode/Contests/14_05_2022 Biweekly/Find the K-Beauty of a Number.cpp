//Problem link - https://leetcode.com/contest/biweekly-contest-78/problems/find-the-k-beauty-of-a-number/
class Solution {
public:
    
    int divisorSubstrings(int num, int k) {
        string str = to_string(num);
        int n = str.length(),ans=0;
        for(int i=0;i<=n-k;i++)
        {
            string thisStr = str.substr(i,k);
            int div = stoi(thisStr);
            if(div !=0 && num%(div)==0) ans++;
        }
        return ans;
    }
};
