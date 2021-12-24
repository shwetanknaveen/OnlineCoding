//Problem link - https://leetcode.com/problems/combination-sum/
//Video link - 	https://www.youtube.com/watch?v=OyZFFqQtu98&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=50

//Time complexity -> O((2^target) * (target)) if candidate has '1' in it. We can pick any element any number of times
//Space complexity -> O(target)
//It is given that all the elements of candidates are unique
class Solution {
public:
    void findCombSum(vector<int> &candidates,int target,vector<int> &ds,vector<vector<int>> &ans,int ind)
    {
        if(target==0)//if got the target then just put the combination in ans and return
        {
            ans.push_back(ds);
            return;
        }
        if(ind>=candidates.size() || target<0) return;//if exploring outside the array or target < 0 then return
        
        if(target>=candidates[ind]) //only in this case we can pick
        {
            ds.push_back(candidates[ind]);
            findCombSum(candidates,target-candidates[ind],ds,ans,ind);//we have picked hence now required target = 
            														//target-candidates[ind]. Since we can pick the same
            														//element again hence we pass ind again and not ind+1
            ds.pop_back();//to explore next opportunity, when recursive call returns on the same level, we have to pop back
            			//the number. See Subset sum II problem https://leetcode.com/problems/subsets-ii/
        }
        findCombSum(candidates,target,ds,ans,ind+1);//NOTE-> This won't be in else case as we will be exploring the possibility
        											//without picking the candidate in any case.
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombSum(candidates,target,ds,ans,0);
        return ans;
    }
};
