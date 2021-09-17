#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Normal partitioning as done in quick sort
//O(N)
int partition (int arr[], int low, int high)
    {
       // Your code here
       int i,j,temp;
       i = low -1;
       
       for(j=low;j<=(high-1);j++)// Pivot = arr[high]
       {
           if(arr[j]<arr[high])
           {
               temp = arr[++i];
               arr[i] = arr[j];
               arr[j] = temp;
           }
       }
       //when scan has been done to whole left of pivot element then swap the pivot ele-
       //ment at its right place
       temp = arr[high];
       arr[high] = arr[++i];
       arr[i] = temp;
       return i;//return the index where the pivot element has been inserted so that
                //further quicksorts will be called on its left and right
    }	
 
/*Average complexity O(n)
This algorithm returns the index of the element in the array arr which has rank = rank.
Meaniwhile it also changes arr and fits the required element whose rank is rank at its suitable place.
Rank of element is (no. of numbers greater than that number) + 1. ==>Larger the number lower will be its rank and vice versa.
So to find median and set the median at mid position we call this function with rank = n/2 +1 */ 
    
int FindRankIndex(int arr[],int l, int r,int rank)
{
	if(l<r)
	{
		//We know that our end element will be pivot hence to make randomized selection of pivot we can do following
		int p =rand()%(r-l+1) + l;
		swap(arr[p],arr[r]); 
		//end of logic for using randomized pivot
		
		
		int k = partition(arr,l,r);//Now all the elements on left of k will be less than arr[k] and on right of it will be greater than it
		//pivot which has been set at kth position will have rank = (r-k+1)
		
		if(rank==(r-k+1))//if its rank is same then we return its index 
		return k;
		
		
		else if(rank<(r-k+1))				
		return FindRankIndex(arr,k+1,r,rank);/*When rank of this element is greater than required rank then we start looking
		on right side towards larger elements which have smaller rank. Rank parameter doen't change because we are ignoring
		left side and smaller numbers don't affect the rank. What our element has rank in A[l to r] will be same as rank in
		A[(k+1) to r] if it's on right side of k*/
		
		else
		return FindRankIndex(arr,l,k-1,rank-(r-k+1));/*We start looking on left side towards smaller numbers which have lar
		-ger rank. If our required number has rank = rank in A[l to r] then it will have rank = rank - (r-k+1) in A[l to k-1]*/
	}
	else return r;
}

/*Using this algorithm if we wish to find k largest numbers then we call this function with rank = k+1 and then
return the last k numbers.
If we want k smallest numbers then we call with rank = n-k and return first k numbers
*/
int main()
{
	int n,r;
	cout<<"No. of elements\t";
	cin>>n;
	int arr[n];
	cout<<endl<<"Enter elements\n";
	for(int i=0;i<n;i++)
	cin>>arr[i];
	cout<<"Enter rank for median\t";
	cin>>r;
	cout<<endl<<"Array before finding median\n";
	for(int i : arr)
	cout<<i<<"  ";
	cout<<"Index for rank = "<<r<<"\t is ->"<<FindRankIndex(arr,0,n-1,r);//for median pass rank = n/2+1
	cout<<endl<<"Array after finding median\n";
	for(int i : arr)
	cout<<i<<"  ";
	
	int largest, smallest;
	cout<<"\nHow many largest numbers do you want?\t";
	cin>>largest;
	cout<<"\nHow many smallest numbers do you want?\t";
	cin>>smallest;

	FindRankIndex(arr,0,n-1,largest+1);
	cout<<endl<<largest<<" Largest numbers are "<<largest<<" numbers in the end of following array\n";
	for(int i : arr)
	cout<<i<<"  ";
	
	FindRankIndex(arr,0,n-1,n-smallest);
	cout<<endl<<smallest<<" Smallest numbers are "<<smallest<<" numbers in the begining of following array\n";
	for(int i : arr)
	cout<<i<<"  ";
	
	
	return 0;
}
	
