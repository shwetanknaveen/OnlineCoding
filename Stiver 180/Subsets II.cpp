//Problem link - https://leetcode.com/problems/subsets-ii/
//Video link - https://www.youtube.com/watch?v=RIn3gOkbhQE&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=54

//Approach -1 Power set methond using bit manipulation
//Time complexity -> O(n * 2^n) where n is size of set, Space complexity -> O(n)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> setOfVects;//unordered_set won't work here because unordered_set is using std::hash template to 
									//compute hash for its entries and there is no std::hash for pairs. You have to define 
									//custom hash to use unordered_set.
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<(1<<n);i++)//No. of all possible subsets = 2^n = 1<<n
        {
            vector<int> vect;
            for(int j=0;j<n;j++)
            {
                if(i & (1<<j))//check in that number, jth bit is set or not i.e., jth element of array nums is taken or not
                    vect.push_back(nums[j]);
            }
            sort(vect.begin(),vect.end());//sorting before inserting is neccessary as {1,4} and {4,1} are same subsets
            setOfVects.insert(vect);
        }
        for(vector<int> i : setOfVects)
            ans.push_back(i);
        return ans;
    }
};

//Approach 2-> Recursion

class Solution {
public:
    void findSubsets(int ind,vector<int> &nums,vector<vector<int>> &ans,vector<int> &ds)
    {
        ans.push_back(ds);//at this stage elements upto index ind have been explored and corresponding subset is in ds 
        					//hence put it in ans
        for(int i=ind;i<nums.size();i++)
        {
            if(i!=ind && nums[i] == nums[i-1]) continue;//if it is not the first time we are seeing the number at this 
            											//level rather we have already seen it then skip this number
            ds.push_back(nums[i]);//if it is first time we are seeing the number then add it to the subset
            findSubsets(i+1,nums,ans,ds);//increase the index to explore further
            
			ds.pop_back();//will remove the currently taken element on this level for the next recursive call when recursion 
						//will take another path. Let's take example when we are considering all those subsets having size
						//1. let's say nums = {1,2,3,4}. On first go when ds is empty, it will pick 1 and go on exploring 
						//further. In that path {1} will be pushed to ans. When it recursive call returns to this level we
						//have to remove 1 from ds so that all subsets of size 1 i.e., {2},{3}, and {4} also get pushed to ans;
						//that's why we are doing ds.pop_back() here.
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());//so that equal numbers come together
        findSubsets(0,nums,ans,ds);
        return ans;
    }
};
