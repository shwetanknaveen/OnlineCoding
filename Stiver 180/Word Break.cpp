//Problem link - https://practice.geeksforgeeks.org/problems/word-break1352/1
//Problem link on leetcode - https://leetcode.com/problems/word-break/
//See question "Palindrome Partitioning"
class Solution
{
public:
    bool check(string &A,int start,unordered_set<string> &dict,vector<int> &dp)
    {
        if(start>=A.length())//upto here(till end) all partitions were found in dict
        {
            return true;
        }
        if(dp[start] != -1) return dp[start];
        
		bool ans = false;
        for(int i=start;i<A.length();i++)
        {
            if(dict.find(A.substr(start,i-start+1))!=dict.end())
            /*	If word upto here is found in dictionary then do a partition here
            	and check from next index for remaining word
            */
            {
                ans = ans 			|| 			check(A,i+1,dict,dp);
                	/*
                	Partition upto here			if somehow further partition brings true for remaining string then
                								it make ans as true otherwise ans will remain false
                	*/
            }
        }
        return dp[start] = ans;
    }
    int wordBreak(string A, vector<string> &B) {
        vector<int> dp(A.length()+1,-1);
        unordered_set<string> dict;
        for(string s:B)
        {
            dict.insert(s);
        }
        return check(A,0,dict,dp);
    }
};




//We can write also as following

class Solution
{
public:
    bool check(string &A,int start,unordered_set<string> &dict,vector<int> &dp)
    {
        if(start>=A.length())//upto here(till end) all partitions were found in dict
        {
            return true;
        }
        if(dp[start] != -1) return dp[start];
        
		bool ans = false;
        for(int i=start;i<A.length();i++)
        {
            if(dict.find(A.substr(start,i-start+1))!=dict.end())
            /*	If word upto here is found in dictionary then do a partition here
            	and check from next index for remaining word
            */
            {
                ans = check(A,i+1,dict,dp);
                if(ans) break;//if any partition gives true for whole string then we can break and report that partition
                			//with given condition is possible
            }
        }
        return dp[start] = ans;
    }
    int wordBreak(string A, vector<string> &B) {
        vector<int> dp(A.length()+1,-1);
        unordered_set<string> dict;
        for(string s:B)
        {
            dict.insert(s);
        }
        return check(A,0,dict,dp);
    }
};
