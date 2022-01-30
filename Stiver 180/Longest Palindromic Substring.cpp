//Problem link - https://leetcode.com/problems/longest-palindromic-substring/

//Approach 1 -Brute force method T(n) = O(n^3)
class Solution {
public:
    bool isPalindrome(string &s,int i,int j)
    {
        while(i<j)
            if(s[i++] != s[j--])
                return false;
        return true;
    }
    string longestPalindrome(string s) {
        int len = s.length();
        for(int l = len;l>=1;l--)
        {
            for(int i=0;(i+l-1)<len;i++)//last index of string length = l starting with i is (i+l-1)
            {
                if(isPalindrome(s,i,i+l-1))
                    return s.substr(i,l);
            }
        }
        return " ";//default case to prevent compiling issue otherwise we always get ans in above loop
    }
};

//Approach 2 - Time complexity = O(n^2)	Space complexity = O(1)

class Solution {
public:
    pair<int,int> lengthOfPalin(string &s,int &len,int &ind)//returns indices of that max length palindromic substring that
    														//extends on both sides of s[ind]	T(n) = O(n)
    {
        int start,end,len1,len2;
        start = end = ind;//for odd length palindromes
        while(start>=0 && end<len && s[start]==s[end])
        {
            start--;
            end++;
        }
        len1 = end - start - 1;//here string inside start and end is palindrome excluding s[start] and s[end] characters
        int restoreStart = start, restoreEnd = end;
        
		start = ind;//for even length palindromes
        end = ind+1;
        while(start>=0 && end<len && s[start]==s[end])
        {
            start--;
            end++;
        }
        len2 = end - start - 1;//here string inside start and end is palindrome excluding s[start] and s[end] characters
        
        if(len1>len2)//if odd length palindrome was of greater length then restore it's start,end indices to final return value
        {
            start = restoreStart;
            end = restoreEnd;
        }
        
        
        
        return make_pair(start+1,end-1);//string from start+1 to end-1 is palindrome including s[start+1] and s[end-1] characters
    }
    string longestPalindrome(string s) {
        int len = s.length(),maxi = 1,start = 0,end = 0;
        string ans;
        for(int i=0;i<len;i++)
        {
            pair<int,int> startEnd = lengthOfPalin(s,len,i);
            int length = startEnd.second - startEnd.first + 1;//here palindrome string includes s[startEnd.first] and
            												//s[startEnd.second] characters as we returned value from
            												//lengthOfPalin() in such a way
            
            if(maxi<length)
            {
                maxi = length;
                start = startEnd.first;
                end = startEnd.second;
            }
        }
        ans = s.substr(start,end-start+1);
        return ans;
    }
};
