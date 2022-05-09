//Problem link - https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//Similar to "Striver 180/All Permutations of array"
class Solution {
public:
    void helper(int ind,string &digits,vector<string> &ans,string &thisStr,unordered_map<char,vector<char>> &mp)
    {
        if(ind>=digits.size())//if digits have been exhausted
        {
            if(!thisStr.empty())
                ans.push_back(thisStr);//if string formed upto here is not empty then put it in the vector<string> answer
            return;
        }
        for(char c:mp[digits[ind]])//iterate over all characters on this digit (button)
        {
            thisStr.push_back(c);//push this char in this string
            helper(ind+1,digits,ans,thisStr,mp);//go to next digit
            thisStr.pop_back();//remove the last pushed character so as to explore the next possiblity when recursion call returns back to 
            				//this level
        }
        
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,vector<char>> mp;
        mp['2'] = {'a','b','c'};
        mp['3'] = {'d','e','f'};
        mp['4'] = {'g','h','i'};
        mp['5'] = {'j','k','l'};
        mp['6'] = {'m','n','o'};
        mp['7'] = {'p','q','r','s'};
        mp['8'] = {'t','u','v'};
        mp['9'] = {'w','x','y','z'};
        vector<string> ans;
        string thisStr;
        helper(0,digits,ans,thisStr,mp);
        return ans;
    }
};
