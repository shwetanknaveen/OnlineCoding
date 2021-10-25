//Problem link - https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
/*
Intution- If there is an sub-array which has sum 0 then while calculating prefix
sum, we will get more than one sum having same value.
If prefix sum itself is zero then obviously there is an subarray with sum = 0
*/
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_set<int> sums;
        int val=0;
        for(int i=0;i<n;i++)
        {
            val += arr[i];
            if(val==0 || sums.find(val)!=sums.end())
            return true;
            else sums.insert(val);
        }
        return false;//default case
    }
};
