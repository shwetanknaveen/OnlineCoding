//Problem link - https://leetcode.com/problems/time-needed-to-buy-tickets/

//Approach 1 Brute Force
//Time complexity = O(tickets[k] x N)

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int size= tickets.size();
        int ans = 0;
        for(int i=0;tickets[k]>0;i=(i+1)%size)
        {
            if(tickets[i]>0)//if this person still wants to buy ticket
            {
                tickets[i]--;
                ans++;//will take time
            }
        }
        return ans;
    }
};

//Approach 2

/*
For i <= k, A[i] contributes min(A[k], A[i]) steps.
For i > k, A[i] contributes min(A[k] - 1, A[i]) steps
*/

class Solution {
public:
    int timeRequiredToBuy(vector<int>& A, int k) {
        int ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            ans += min(A[k] - (i > k), A[i]);
        }
        return ans;
    }
};
