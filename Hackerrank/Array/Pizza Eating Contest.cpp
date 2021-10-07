//Problem link - https://www.hackerearth.com/problem/algorithm/the-pizza-eating-contest-397ec3cd-7df06718/
#include <iostream>
#include <stdio.h>
#include<algorithm>
using namespace std;
 
int main() {
	int n;
	cin>>n;
	int arr[n];
	int sum=0;
	for(int i=0; i<n;++i){
		cin>>arr[i];
	}	
	//We will pick the three elements from the max side and the least of them that is
	//the third one will be added in our sum and we will choose one from smaller side
	//to make our set of 4.
	sort(arr, arr+n, greater<int>());//sorting in descending order
	 int i=2;
	 for(int j=0; j<n/4;j++){
	 	sum =(sum +arr[i]);
	 	i+=3;//mind it that it's not +4, read the above logic
	 }
        
        
	cout<<sum;
	return 0;
}
//input = 28 7 2 4 4 6 6 10 7 8 5 5 8 4 5 5 8 4 4 10 10 3 1 9 10 5 7 8 10
