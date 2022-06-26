//Problem link - https://leetcode.com/problems/count-asterisks/

class Solution {
public:
    int countAsterisks(string s) {
        int lineCount = 0,ans = 0;
        for(char c:s)
        {
            if(c=='|')
                lineCount++;
            else if(c=='*')
            {
                if(lineCount%2==0)
                    ans++;
            }
        }
        return ans;
    }
};
