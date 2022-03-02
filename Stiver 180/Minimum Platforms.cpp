//Problem link - https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
//Video link -	https://www.youtube.com/watch?v=dxVcMDI7vyI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=47
//Time complexity -> O(nlogn)		Space complexity -> O(1)


//NOTE - Here we sort separately the arrival time and departure time which is little different than 'N meetings in one room'
//problem
#include <bits/stdc++.h>
using namespace std;


//Approach 1 -> Time complexity = O(nlog(n))
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int arriv = 0, dept = 0, max = 0;
    	for(int i=0;i<n;i++)
    	{
    	    if(arr[arriv]>dep[dept])//coming after some train has departed then no new platform is needed
    	    {
    	        arriv++;//look for next coming train
    	        dept++;//train has departed
    	    }
    	    else//coming before some train has departed
    	    {
    	        max++;//new platform needed
    	        arriv++;//look for new upcoming train
    	    }
    	}
    	return max;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends


//Approach 2 -> Difference array
class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n)
    {
    	vector<int> diff(2401, 0);
        for(int i=0; i<n; i++) {
            diff[arr[i]] += 1;
            diff[dep[i]+1] -= 1;
        }
        int mx = diff[0];
        for(int i=1; i<2401; i++) {
            diff[i] += diff[i-1];
            mx = max(mx, diff[i]);
        }
    	return mx;
    }
};
