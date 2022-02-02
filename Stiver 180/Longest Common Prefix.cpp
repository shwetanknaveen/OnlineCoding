//Problem link - https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        
        for(int i = 0;;i++)//we can scan till length of minimum length string
        {
            char c = strs[0][i];
            for(string str:strs)
            {
                if(i>=str.length() || str[i] != c)//this character doesn't match hence return the answer constructed till here 
                    							//will all common prefix or this index is exceeding length of this string
					return ans;
            }
            ans += strs[0][i];//i'th character is same in all the strings
        }
        return ans;
    }
};
