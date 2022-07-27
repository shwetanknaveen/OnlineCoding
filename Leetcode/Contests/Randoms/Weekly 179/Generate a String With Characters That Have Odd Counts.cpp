//Problem link - https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/

class Solution {
public:
    string generateTheString(int n) {
        string ans;
        if(n&1)//if n is odd then push odd number of a's
        {
            while(n--)
                ans.push_back('a');
        }
        else//push odd number of a's and one b in last
        {
            for(int i=0;i<n-1;i++)
                ans.push_back('a');
            if(n>=2)
                ans.push_back('b');
        }
        return ans;
    }
};
