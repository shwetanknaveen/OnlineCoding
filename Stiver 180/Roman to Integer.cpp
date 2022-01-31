//Problem link - https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int getVal(char c)
    {
        if(c=='I')
            return 1;
        else if(c=='V')
            return 5;
        else if(c=='X')
            return 10;
        else if(c=='L')
            return 50;
        else if(c=='C')
            return 100;
        else if(c=='D')
            return 500;
        else if(c=='M')
            return 1000;
        return 0;
    }
    int romanToInt(string s) {
        int val = 0,len = s.length(),prev = 0,curr;
        for(int i=len-1;i>=0;i--)//remember to traverse from right to left
        {
            curr = getVal(s[i]);
            if(curr>=prev)//if number on left is greater or equal then it will be added
                val += curr;
            else//if number on left is smaller then it will be subtracted
                val -= curr;
            
            prev = curr;//update the previous number which is on the right of current number, for next iteration
        }
        return val;
    }
};
