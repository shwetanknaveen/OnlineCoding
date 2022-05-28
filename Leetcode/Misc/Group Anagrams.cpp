//Problem link - https://leetcode.com/problems/group-anagrams/

//Approach 1
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string &str:strs)//map each string to its sorted string. In this way every string will be mapped to its lexicographically smallest
        					//anagram and thus all anagrams will be mapped to same key
        {
            string sortedStr = str;
            sort(sortedStr.begin(),sortedStr.end());
            mp[sortedStr].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto &pair:mp)
            ans.push_back(pair.second);//Just push all the groups
        return ans;
    }
};

//Approach 2 -> For better time complexity using count sort

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            mp[strSort(s)].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
private:
    string strSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');//append counter[c] times of character -> (c+'a') into t
        }
        return t;
    }
};
