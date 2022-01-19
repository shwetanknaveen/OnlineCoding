//Problem link - https://www.spoj.com/problems/AGGRCOW/
//Video link - https://www.youtube.com/watch?v=wSOfYesTBRk&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=71
//Time Complexity-> O(nlog(n))
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool isValid(vector<int> &stalls,int cows,int minDistance)//is it possible to allocate cows no. of cows to stalls with
														//minimum distance = minDistance
{
	//get sorted stalls here
	int n=stalls.size(),prevStall = 0;
	for(int i=0;i<n && cows>0;i++)
	{
		if(i==0)//if this is first stall. Then allot this stall to one cow without comparing its distance with any other
				//stall
		{
			prevStall = stalls[0];
			cows--;//one cow has been alloted
			continue;//look for the next cow
		}
		if(stalls[i]-prevStall>=minDistance)//if we can allot this stall to a cow with minDistance constraint
		{
			cows--;
			prevStall = stalls[i];
		}
	}
	if(cows>0) return false;//all the cows coudn't be allocated
	return true;
}

int getAns(int &c,vector<int> &stalls)
{
	sort(stalls.begin(),stalls.end());
	int low = 1,//minimum distance has to be 1 as cows are aggressive
	high = stalls[stalls.size()-1]-stalls[0],//maximum distance can be difference of stalls at maximum distances
	mid,res;
	while(low<=high)
	{
		mid = low + (high-low)/2;
		if(isValid(stalls,c,mid))
		{
			res = mid;//store this limit
			low = mid+1;//if this limit on minimum distance is possible then we can search for larger limits as we need max
						//ans
		}
		else
		{
			high = mid-1;//If that much minDist=mid was not possible to allocate with then we reduce the search space
		}
	}
	return res;//return the stored ans;
}
int main() {
	int t,n,c;
	cin>>t;
	while(t--)
	{
		cin>>n>>c;
		vector<int> stalls(n);
		for(int i=0;i<n;i++)
			cin>>stalls[i];
		cout<<getAns(c,stalls);
		if(t!=0) cout<<endl;
	}
	return 0;
}
