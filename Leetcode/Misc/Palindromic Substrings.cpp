//Problem link - https://leetcode.com/problems/palindromic-substrings/
//See also "Striver 180/Longest Palindromic Substring"

class Solution {
public:
    int isPalindrome(int ind,string &s)
    {
        int start,end,ans = 0;
        
        //for odd length palindrome
        start = end = ind;
        while(start>=0 && end<s.length() && s[start]==s[end])
        {
            start--;
            end++;
            ans++;
        }
        
        //for even length palindrome
        start = ind;
        end = ind+1;
        while(start>=0 && end<s.length() && s[start]==s[end])
        {
            start--;
            end++;
            ans++;
        }
        return ans;
        
    }
    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0;i<s.length();i++)
        {
            ans += isPalindrome(i,s);
        }
        return ans;
    }
};
