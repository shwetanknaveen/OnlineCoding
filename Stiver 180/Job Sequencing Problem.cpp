//Problem link -	https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
//Video link -	https://www.youtube.com/watch?v=LjPx4wQaRIs&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=47
//Time complexity -> O(n2) 		Space complexity-> O(max deadline)
//Approach -> We sort as per profit in descending order and then fill the job nearest to its deadline. If we find slot as 
//occupied then we start looking at earlier dates

// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comparator(Job j1, Job j2)//to sort in descending order of profit
    {
        if(j1.profit>j2.profit) return true;//give priority to profit
        else if(j1.profit==j2.profit) return (j1.dead<j2.dead);//if profit same then less deadline is prioritised
        else return false;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comparator);
        vector<int>  dates(101,-1);
        int num=0,prof = 0;
        for(int i=0;i<n;i++)
        {
            
            for(int j=arr[i].dead;j>0;j--)//start looking from deadline itself towards earlier dates
            {
                if(dates[j] == -1)//if this date is not occupied
                {
                    prof += arr[i].profit;
                    num++;
                    dates[j] = 1;
                    break;//schedule next job
                }
            }
        }
        vector<int> ans(2);
        ans[0] = num;
        ans[1] = prof;
        return ans;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends
