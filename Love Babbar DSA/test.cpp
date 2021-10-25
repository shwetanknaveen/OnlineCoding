#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

    void negativeAtEvenIndex(int arr[],int n,int i)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>=0)
            {
                swap(arr[j],arr[i]);
                return;
            }
        }
    }
    void positiveAtOddIndex(int arr[],int n,int i)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<0)
            {
                swap(arr[j],arr[i]);
                return;
            }
        }
    }
	void rearrange(int arr[], int n) {
	    // code here
	    for(int i=0;i<n;i++)
	    {
	        if((i&1) && arr[i]>=0)//positive number at odd index
	        positiveAtOddIndex(arr,n,i);
	        else if(!(i&1) && arr[i]<0)//negative number at even index
	        negativeAtEvenIndex(arr,n,i);
	    }
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
