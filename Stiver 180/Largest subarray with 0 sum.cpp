//Problem link - https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
//Video link - https://www.youtube.com/watch?v=xmguZ6GbatA&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=24
//Time and space complexity -> O(n)

/*
Logic-> If sum of an array from i to j is S. Also sum of i to k is S then sum of
k+1 to j must be 0 so that sum of i to j comes to be 0
*/
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int maxi = 0 , sum = 0;
        unordered_map<int,int> sum_index;//what prefix sum is obtained upto what index
        
        for(int i=0;i<n;i++)
        {
            sum += A[i];
            if(sum==0) maxi = i+1;
            else
            {
                if(sum_index.find(sum)!=sum_index.end())//present there
                    maxi = max(maxi,(i-sum_index[sum]));/*Sum which was found
                    earlier is found again, hence sum from it's last occurence
                    upto here must be 0. We update maxi with largest possible
                    value*/
                    
                else sum_index[sum] = i;//sum_index.insert({sum,i});
                                        //if it wasn't found then insert it
            }
        }
        return maxi;
    }
};
