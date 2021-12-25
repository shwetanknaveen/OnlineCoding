//Problem link - https://leetcode.com/problems/palindrome-partitioning/
//Video link - youtube.com/watch?v=WBgsABoClE0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=52

//Time Complexity : O(N*2^N), where N is the length of string.At worst there can be 2^N substrings and all of them may be palindrome 
//This is the worst-case time complexity when all the possible substrings are palindrome.
//Space complexity : O(N)
class Solution {
public:
    bool isPalindrome(string s,int start,int end)
    {
        while(start<end)
        {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    void getPartitions(int ind,string s,vector<string> &palinSubStrings,vector<vector<string>> &ans)
    {
        if(ind==s.size())//if partition is happening at the end then nothing left to explore more
        {
            ans.push_back(palinSubStrings);
            return;
        }
        for(int i=ind;i<s.size();i++)//iterate from current place and see for all the possibilites of next partition
        {
            if(isPalindrome(s,ind,i))//if there can be partition at ith index->(Upto here we only care that whether partition
									//at ith index is resulting into a palindrome string from ind to i)
            {
                palinSubStrings.push_back(s.substr(ind,i-ind+1));//then put the substring from ind to i in the set of 
                												//palindrome substrings
                getPartitions(i+1,s,palinSubStrings,ans);//call the function recursively from next index to explore further
                										//partitions
                palinSubStrings.pop_back();//to explore next opportunity, when recursive call returns on the same level, 
            		//we have to pop back the number. See Subset sum II problem https://leetcode.com/problems/subsets-ii/
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> palinSubStrings;
        getPartitions(0,s,palinSubStrings,ans);
        return ans;
    }
};
