//Problem link - https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1#
//Brute force approch
class Solution{
 public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      sort(arr,arr+N);
      int count=1;
      int maxi = 1;
      for(int i=0;i<N-1;i++)
      {
          if(abs(arr[i]-arr[i+1])==1)
          {
              count++;
          }
          else if(arr[i]!=arr[i+1])
          {
              count = 1;
          }
          maxi = max(maxi,count);
      }
      return maxi;
    }
};
