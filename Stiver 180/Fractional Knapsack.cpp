//Problem - https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#
//Video link - https://www.youtube.com/watch?v=F_DDzYnxO14&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=50
//Time complexity ->O(nlog(n))	Space complexity -> O(1)

#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comparator(Item i1,Item i2)
    {
        return ((double)i1.value/(double)i1.weight > (double)i2.value/(double)i2.weight);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double profit = 0.0;
        sort(arr,arr+n,comparator);
        for(int i=0;i<n && W>=0;i++)
        {
            if(arr[i].weight<=W)
            {
                profit += arr[i].value;
                W -= arr[i].weight;
            }
            else
            {
                profit += (double(arr[i].value)/double(arr[i].weight))*double(W);
                W = 0;
            }
        }
        return profit;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
