//Problem link - https://practice.geeksforgeeks.org/problems/minimum-swaps/1
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



//Youtube ref link - https://www.youtube.com/watch?v=1BxbBgNSwHo
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    /*We first sort the array then try to get the desired array with minimum number or swaps*/
	    int size = nums.size();
	    vector<pair<int,int>> vect(size);
	    for(int i=0;i<size;i++)
	    {
	    vect[i] = {nums[i],i};//vect[i] contains {i,j} where i is number and j is its index in the original array
	    }
	    sort(vect.begin(),vect.end());//sort the array on the basis of first value of pair 
	    int count=0;
	    for(int i=0;i<size;i++)
	    {
	        if(vect[i].second==i) continue;//if the element in the sorted array has same position as that in given array
	        else
	        {
	            count++;//swap is needed
	            swap(vect[i],vect[vect[i].second]);//swap this number with that number which is on the index where this number should be
	            i--;//We have to check again that the number which came here after swap is at right place or not
	        }
	    }
	    return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
