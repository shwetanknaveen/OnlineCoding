//Problem link - https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int n= special.size();
        int ans = special[0]-bottom;//First check for non special floors between smallest special floor and bottom floor which has been rented
        ans = max(ans,top-special[n-1]);//Then store maximum by comparing it with no. of non special floors between largest special floor and
        								//the top floor which has been rented
        for(int i=1;i<n;i++)//start checking the count of non-special floor between two special floors
        {
            ans = max(ans,special[i]-special[i-1]-1);
        }
        return ans;
    }
};
