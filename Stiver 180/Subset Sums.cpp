//Problem link - https://practice.geeksforgeeks.org/problems/subset-sums2234/1#
//Video link - https://www.youtube.com/watch?v=rYkfBRtMJr8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=52


#include<bits/stdc++.h> 
using namespace std; 
class Solution
{
public:
    void getAns(vector<int> arr, int N,vector<int> &ans,int sum)
    {
        if(N==0)//if no element is remaining to explore then push the sum
        {
            ans.push_back(sum);
            return;
        }
        getAns(arr,N-1,ans,sum+arr[N-1]);//select the current element and add it into the sum
        //IMPORTANT NOTE -> Vector doesn't throw error on accessing -1 index that is here arr[-1] give 0
        
        getAns(arr,N-1,ans,sum);//leave the current element and don't include it in the sum
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        getAns(arr,N,ans,0);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  
