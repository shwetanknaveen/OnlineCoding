/*
Write a program that reads N integers, then prints on a separate line the value of each distinct element along with the number 
of times it occurs. the values should be printed in descending order of occurrences.

Note: If the two or more number has the same number of occurrences, the number who is smaller will come first in the ascending
order.

Sample Input

-7 -7 3 3 5 -7 -1

Sample Output

-7 3

3 2

5 1
*/

#include<bits/stdc++.h>
using namespace std;
bool comparator(pair<int,int> p1,pair<int,int> p2)
{
    if(p1.first>p2.first) return true;
    else if(p1.first==p2.first)//if same occurence
    {
        if(p1.second<p2.second) return true;//then smaller should come first
        else return false;
    }
    else return false;
}
int main()
{
    map<int,int> mp;
    vector<pair<int,int> > occNum;
    int n;
    while(1)
    {
        cin>>n;
        if(n==-1)
            break;
        else
        {
            mp[n]++;
        }
    }
    map<int, int>::iterator it;
    for(it = mp.begin(); it != mp.end(); it++)
        occNum.push_back(make_pair(it->second,it->first));
    sort(occNum.begin(),occNum.end(),comparator);
    for(int i=0;i<occNum.size();i++)
    {
        cout<<occNum[i].second<<" "<<occNum[i].first;
        if(i!=occNum.size()-1)
            cout<<"\n";
    }
    return 0;
    
}
