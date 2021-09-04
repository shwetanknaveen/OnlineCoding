#include <bits/stdc++.h>
using namespace std;
 

int helper(vector<int> arr, int left, int right,vector<vector<int>> &dp)
{
    
    if (left > right)
        return 0;
 

    if (dp[left][right] != -1) {
        return dp[left][right];
    }
 
    int ans = (1) + helper(arr, left + 1,right,dp);
 
    for (int i = left + 1;i <= right; ++i) {
 
        if (arr[i] == arr[left]) {
 
            ans = min(ans,helper(arr, left + 1,i - 1,dp)+ helper(arr, i, right,dp));
        }
    }
 
    // Store the result
    dp[left][right] = ans;
 
    // Return answer
    return ans;
}
 
// Function to remove the elements
int maxPoints(vector<int> arr)
{   
    int len = arr.size();
    
    vector<vector<int>> dp(len+1,vector<int>(len+1,-1));//we can directly provide default value as -1

    return helper(arr, 0, len - 1,dp);
}

int main() {
	// your code goes here
	vector<int> num{1,2,2,2,1,1};
//	vector<int> num{1,2,1,3,1};
//	vector<int> num{1,2,2,2,1,1,3,3,3,2,2,1,1};
//	vector<int> num{1,1,1,1,1,1,1,1,1,1,1,1,1};
	cout <<maxPoints(num)<<endl;
	
	return 0;
}
