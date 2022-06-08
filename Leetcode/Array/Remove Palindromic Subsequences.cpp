//Problem link - https://leetcode.com/problems/remove-palindromic-subsequences/

class Solution {
public:
    bool isPalin(string &s)
    {
        int i=0,j=s.length()-1;
        while(i<j)
        {
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int removePalindromeSub(string s) 
    {
         if(isPalin(s)) return 1;//if given string itself is palindrome then delete it in one step
            return 2;//otherwise delete all a(s) in one step and all b(s) in the next step
    }
};
