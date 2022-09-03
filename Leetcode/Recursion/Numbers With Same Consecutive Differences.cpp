//Problem link - https://leetcode.com/problems/numbers-with-same-consecutive-differences/

class Solution {
public:
    void solve(int ind,int &n,int &k,string &temp,vector<int> &ans)
    {
        if(ind==n)
        {
            ans.push_back(stoi(temp));//We have constructed the n digit number
            return;
        }
        for(char c='0';c<='9';c++)
        {
            if(ind==0 && c=='0') continue;//number can't have zero at first digit
            if(ind==0)//if it's the first digit and it is not zero then we don't need to check anything else
            {
                temp.push_back(c);
                solve(ind+1,n,k,temp,ans);
                temp.pop_back();
            }
            else
            {
                if(abs(c-temp[ind-1])==k)//difference with last filled number should be k
                {
                    temp.push_back(c);
                    solve(ind+1,n,k,temp,ans);
                    temp.pop_back();
                }
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) 
    {
        vector<int> ans;
        string temp;
        solve(0,n,k,temp,ans);
        return ans;
    }
};
