//Problem link - https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1/
//Problem link - https://www.codingninjas.com/codestudio/problems/max-of-min_982935?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

//Approach 1 	Time complexity = O(n^2)		Utilising the approach in "Sliding Window Maximum"
#include<bits/stdc++.h>
vector<int> maxMinWindow(vector<int> a, int n) {
    	vector<int> ans;
    	for(int k=1;k<=n;k++)//for each window size
        {
            int maxi = INT_MIN;
            deque<int> deq;
		    for(int i=0;i<n;i++)
		    {   
		        while(!deq.empty() && a[deq.back()]>a[i])//pop all the numbers from back which are smaller than this
		            deq.pop_back();
		        deq.push_back(i);
		        while(deq.front()<(i-k+1) && !deq.empty())//at ith index, the first index of current window is i-k+1
		            deq.pop_front();					//so if element at front is out of scope then remove it
		        if(i>=k-1)//first window will complete at k-1 index and then next window's last element will have +1 index
		            maxi = max(maxi,a[deq.front()]);//ans.push_back(nums[deq.front()]);
		    }
            ans.push_back(maxi);
        }
   		return ans;
}

//Approach 2 Time Complexity = O(n)
/*
We will follow some reverse strategy for building our final solution instead of finding minimums for every possible window.
We will find how many windows our current element can be the answer.To find that we will calculate the indexes of the next
smaller and previous smaller element for every element given in the array. The next smaller element is some number that is 
smaller than the current element and lies nearest on the right-hand side of the current element. Similarly, the previous 
smaller is some number that is smaller than the current element and lies nearest on the left-hand side of the current element.
If there is no next smaller element for the current number then we will assume its index having value N and if there is no 
previous smaller element for the current number then we will assume its index having value -1.The above two arrays of the 
next smaller and previous smaller can be done in linear time with the help of Monotonic Stack.Suppose ‘next[i]’ = index of 
next smaller element, ‘prev[i]’ = index of previous smaller element. Now, we know the ‘ARR[i]’ will be the minimum of the 
window of size -> size = next[i] - prev[i] - 1. So, we will directly use the value of ‘ARR[i]’ for updating the answer of 
window having size = next[i] - prev[i] - 1. We should note that in ans[] window sizes are from 0 index that is answer
for window size = 1 is stored at ans[0]

After doing this for every element we can update our answer for windows of some 
different lengths i.e, we are still left with some window sizes for which the answer is not calculated yet.It happens because
suppose some arr[i] is smaller for window size ws and it will be updated but it will also be minimum for many more window
sizes. 
So to fill the remaining entries we will use some observations listed below:-The answer for some window having size ‘L’ 
would always be greater than or equal to the answer for a window having a length greater than L i.e, L+1, L+2 .... so on.
Hence, we will update the remaining uncalculated answer for some windows having length ‘L’ with the maximum suffix starting 
from length ‘L+1’.We are sure that answer for largest window must be updated as smallest number won't be having next/previous
smaller element
*/

class Solution
{
    public:
    vector<int> indPrevSmaller(int arr[],int &n)
    {
        vector<int> ans(n);
        stack<int> stackInd;
        
        for(int i=0;i<n;i++)
        {
            while(!stackInd.empty() && arr[stackInd.top()]>=arr[i])
                stackInd.pop();
                
            if(stackInd.empty())
                ans[i] = -1;//No previous element is smaller than this
            else ans[i] = stackInd.top();
            
            stackInd.push(i);
        }
        return ans;
    }
    vector<int> indNextSmaller(int arr[],int &n)
    {
        vector<int> ans(n);
        stack<int> stackInd;
        
        for(int i=n-1;i>=0;i--)
        {
            while(!stackInd.empty() && arr[stackInd.top()]>=arr[i])
                stackInd.pop();
                
            if(stackInd.empty())
                ans[i] = n;//No next element is smaller than this
            else ans[i] = stackInd.top();
            
            stackInd.push(i);
        }
        return ans;
    }
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> ans(n,INT_MIN);
        vector<int> prevSmallerInd = indPrevSmaller(arr,n);
        vector<int> nextSmallerInd = indNextSmaller(arr,n);
        
        int winForWhichThisIsAns;
        for(int i=0;i<n;i++)
        {
            winForWhichThisIsAns = nextSmallerInd[i] - prevSmallerInd[i] - 1;
            ans[winForWhichThisIsAns-1] = max(ans[winForWhichThisIsAns-1],arr[i]);//As in ans, window size is in 0 based index
        }
        
        for(int i=n-2;i>=0;i--)
            ans[i] = max(ans[i],ans[i+1]);
        return ans;
    }
};
