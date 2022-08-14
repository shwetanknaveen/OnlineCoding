//Problem link - https://leetcode.com/problems/construct-smallest-number-from-di-string/

class Solution {
public:
    void solve(int ind,string &pattern,string &temp,string &ans,int last,unordered_set<int> &taken)
    {
        if(ans != "") return;//We are filling number from left to right and in increasing order hence
                            //if ans is found, it will be gauranteed as lexicographically as smallest
        
        if(ind==pattern.length()+1)//all characters has been filled upto length (n+1) hence this is ans
        {
            ans = temp;
            return;
        }
        for(int i=1;i<=9;i++)//Let's see that which number can be filled at indices in the ans
        {
            if(ind==0)//this is the first character so no need to check anything
            {
                temp += to_string(i);
                taken.insert(i);
                solve(ind+1,pattern,temp,ans,i,taken);
                temp.pop_back();
                taken.erase(i);
            }
            else//this is not first character in ans from left
            {
                if(pattern[ind-1]=='I' && i>last && taken.find(i)==taken.end())
                {
                    temp += to_string(i);
                    taken.insert(i);
                    solve(ind+1,pattern,temp,ans,i,taken);
                    temp.pop_back();
                    taken.erase(i);
                }
                else if(pattern[ind-1]=='D' && i<last && taken.find(i)==taken.end())
                {
                    temp += to_string(i);
                    taken.insert(i);
                    solve(ind+1,pattern,temp,ans,i,taken);
                    temp.pop_back();
                    taken.erase(i);
                }
            }
        }
    }
    string smallestNumber(string pattern) 
    {
        string ans = "",temp = "";
        unordered_set<int> taken;
        solve(0,pattern,temp,ans,0,taken);//no matter that what we pass value of last for ind=0
        return ans;
    }
};
