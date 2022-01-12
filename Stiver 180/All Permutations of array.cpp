//Problem link - https://leetcode.com/problems/permutations/

//APPROACH 1 ->Recursion with extra space
//Video link -> https://www.youtube.com/watch?v=YK78FU5Ffjw&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma

//Time complexity O(n! x n)
//Space complexity O(n)
class Solution {
public:
    
    void solve(vector<int> &nums,vector<int> taken,vector<int> &ds,vector<vector<int>> &ans,int nTaken,int &n)
    {
        if(nTaken==n)//number of elements taken in the data structure ds is equal to all the elements then simply push 
        			//this state of ds into ans and return
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<n;i++)//at each stage of recursion, start iterating from first element and check if it's taken or not
        {
            if(taken[i] == -1)//element not taken
            {
                taken[i]=0;//now element is marked taken
                ds.push_back(nums[i]);//since element is now being taken hence push it in the ds
                solve(nums,taken,ds,ans,nTaken+1,n);//increase number of taken elements
                
                ds.pop_back();//when recursive call returns at this level then pop off the taken element for exploring next option
                taken[i]=-1;//mark it as not taken
                
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> taken(n,-1);//initially no element is taken
        vector<int> ds;
        vector<vector<int>> ans;
        solve(nums,taken,ds,ans,0,n);//0 as initially no element is taken
        return ans;
    }
};

//APPROACH 2->Recursion without extra space
//Video link -> https://www.youtube.com/watch?v=f2ic2Rsc9pU&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=53

//Time complexity O(n! x n)
//Space complexity O(n)
class Solution {
public:
    void solve(vector<int> &nums,int ind,vector<vector<int>> &ans)
    {
        if(ind == nums.size())//if index is crossing the array boundary then push the current state of permutated numbers
        					//in the array to ans
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=ind;i<nums.size();i++)//try swapping this number with every number ahead
        {
            swap(nums[i],nums[ind]);
            solve(nums,ind+1,ans);//recursively call the function from next index
            swap(nums[i],nums[ind]);//swap back to original state so that when recursion call returns to this level it can
            	`					//explore other possibilites
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,0,ans);
        return ans;
    }
};
