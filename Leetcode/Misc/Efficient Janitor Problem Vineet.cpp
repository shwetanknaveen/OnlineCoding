//Problem link - https://www.hackerearth.com/problem/algorithm/efficient-vineet/

/*
Algorithm - Take as many heavy items as possible and club them with as many as light items as possible
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<double> bags(n);
    double cap;
    for(int i=0;i<n;i++)
    cin>>bags[i];
    int ans = 0;
    sort(bags.begin(),bags.end());
    int front = 0 , back = n-1;//front and back point to a bag which hasn't been picked up yet
    while(front<back)
    {
        cap = 3.0;
        while(bags[back]<=cap && back>=0)
        {
            cap -=bags[back];
            back--;
        }
        while(bags[front]<=cap && front<n)
        {
            cap -=bags[front];
            front++;
        }
        ans++;
    }
    if(front == back) ans++;//if front == back then above loop wouldn't have entered then we have to make ans from 0 to 1.
    						//Also after above loop execution if front=back and both are pointing to a bag which hasn't been 
    						//picked up yet hence it will require a trip
    cout<<ans;
    return 0;
}

