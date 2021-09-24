//Problem link - https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1#

//Refer to below link for concept used in this question 
// https://github.com/shwetanknaveen/OnlineCoding/blob/master/GFG/Sortings/Find%20Rank%20Index.cpp

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int partition(int arr[],int l,int r)
    {
        int pivot = arr[r];
        int i=l-1;
        for(int j=l;j<r;j++)
        {
            if(arr[j]<pivot)
            swap(arr[++i],arr[j]);
        }
        swap(arr[++i],arr[r]);
        return i;
    }
    int findRankIndex(int arr[],int l,int r,int rank)
    {
        if(l<r)
        {
            int n=r-l+1;//number of elements
            int randNo = rand()%n+l;
            swap(arr[randNo],arr[r]);//randomising the pivot
            int k = partition(arr,l,r);
            if(rank==(r-k+1)) return k;
            else if((r-k+1)>rank) return findRankIndex(arr,k+1,r,rank);
            else return findRankIndex(arr,l,k-1,rank-(r-k+1));
        }
        else return l;
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        int n=r-l+1;
        return arr[findRankIndex(arr,l,r,n-k+1)];
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends
