//Problem link - https://leetcode.com/problems/valid-palindrome/

//Approach 1 - Using extra space to build new string
class Solution {
public:
    bool check(string &s)
    {
        int start = 0,end = s.length()-1;
        while(start<end)
        {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string newS;
        for(char c:s)
        {
            if(isalpha(c) || isdigit(c))
            {
                newS.push_back(tolower(c));
            }
        }
        return check(newS);
    }
};

//Approach 2 - Better approach
class Solution {
public:
    bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
        while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
        while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
        if (tolower(s[i]) != tolower(s[j])) return false; // Exit and return error if not match
    }
    
    return true;
}
};
