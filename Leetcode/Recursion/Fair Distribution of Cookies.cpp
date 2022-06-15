//Problem link - https://leetcode.com/problems/fair-distribution-of-cookies/

class Solution {
public:
    void solve(vector<int> &cookies,vector<int> &children,int ind,int &ans,int maxi)
    {
        if(ind==cookies.size())//All cookies packet have been given
        {
            ans = min(ans,maxi);//ans has to be minimum unfairness
            return;
        }
        for(int i=0;i<children.size();i++)//now this cookie packet at index ind can be given to which child
        {
            children[i] += cookies[ind];//give this packet at index ind to child at index i
            solve(cookies,children,ind+1,ans,max(maxi,children[i]));//maximum values can change if this packet is given to child at i
            children[i] -= cookies[ind];//remove the given cookie for the next recursive call
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k,0);
        int ans = INT_MAX;
        solve(cookies,children,0,ans,0);
        return ans;
    }
};
