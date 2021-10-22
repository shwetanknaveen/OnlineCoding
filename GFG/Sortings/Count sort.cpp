//Video link - https://www.youtube.com/watch?v=imqr13aIBAY

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Complexity is O(max(n,max no. in the array))
void countSort(int arr[],int n){
	//int n= sizeof(arr)/sizeof(arr[0]);WRONG USE of sizeof() https://www.geeksforgeeks.org/using-sizof-operator-with-array-paratmeters/
	// https://www.geeksforgeeks.org/using-sizof-operator-with-array-paratmeters/
	
	int maxi = arr[0];//maximum element in the array
	
	for(int i=0;i<n;i++)
		maxi = max(maxi,arr[i]);
		
	int count[maxi+1];//last index of count array is maxi
	memset(count,0,sizeof(count));
	
	for(int i=0;i<n;i++)
	{
		count[arr[i]]++;
	}
	
	for(int i=1;i<=maxi;i++)//last index of count array is maxi
	{
		count[i] += count[i-1];//taking the cumulative sum->prefix sum
	}
	
	int output[n];
	for(int i=n-1;i>=0;i--)
	{
		output[--count[arr[i]]] = arr[i];//searching the input array from right to left and storing
										//the numbers at their right position
	}
	for(int i=0;i<n;i++)
	arr[i] = output[i];//storing back the output in the original array
}

int main()
{
	int n;
	cout<<"Enter size of array\t";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	countSort(arr,n);
	cout<<"\n Sorted array is:\n";
	
	for(int i: arr)
	cout<<i<<"  ";
	
	return 0;
}
