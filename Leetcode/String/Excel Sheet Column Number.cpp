//Problem link - https://leetcode.com/problems/excel-sheet-column-number/


//Approach 1 -> PnC approach
class Solution {
public:
    int titleToNumber(string cT) 
    {
        int len = cT.size(),nShortLen = 0;
        for(int shorterLen = 1;shorterLen<len;shorterLen++)//for string of length len, all strings before it is 26 + 26x26 + 26 x 26 x....(len-1) times
        {
            nShortLen += pow(26,shorterLen);
        }
        int nThisLen = 0;
        /*
        Let's say the column name is ZYX so all column length before this having length 3 is calculated as ->
        Step - 1-> Character before Z is Y so before Z came at 0th index, count of strings before it would be 25 x 26 x 26 as Y is the 25th character
        Step - 2-> Fixing Z at 0th index, before Y came at 1st index, count of strings before it would be 24 x 26 as X before Y is 24th character
        Step - 3-> Fixing Z at 0th index and Y at 1st index, count of strings before it would be 23
        */
        for(int i=0;i<len;i++)
            nThisLen += (cT[i]-'A')*pow(26,len-i-1);
        
        int allColsBefore = nShortLen + nThisLen;
        return allColsBefore+1;//We add 1 for this column number because all columns before it have been calculated in allColsBefore
    }
};
//Approach 2 -> Smarter approach
class Solution {
public:
    int titleToNumber(string columnTitle) {
        /*
        Suppose there is a number 123576. So how do we construct this number starting from 0?
        We keep result = 0 and start looking from left to right of the number and do result = result x 10 + (value of digit). We multiply by 10 becasue there are 10 values for a digit in decimal number system. Now consider the column name
        in same manner. Here we have 26 values.
        */
        int ans = 0;
        for(char c:columnTitle)
            ans = ans*26 + (c-'A'+1);
        return ans;
    }
};
