//Problem link - https://leetcode.com/problems/combination-sum-ii/
//Video link - https://www.youtube.com/watch?v=G1fRTGRxXU8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=51


//Time complexity -> O(n * 2^n) where n is size of set, Space complexity -> O(n) to store ds
//there are 2^n subsets and each subset will take O(n) time to get copied in ans.

class Solution {
public:
    void findCombSum2(vector<int> &candidates,int target,int ind,vector<int> &ds, vector<vector<int>> &ans)
    {
        if(target==0)//if got the target then just put the combination in ans and return
        {
            ans.push_back(ds);
            return;
        }
        if(ind>=candidates.size() || target<0) return;//if exploring outside the array or target < 0 then return
        
        for(int i=ind;i<candidates.size();i++)
        {
            if(i!=ind && candidates[i] == candidates[i-1]) continue;//if it is not the first time we are seeing the number 
            											//at this level rather we have already seen it then skip this number
            
            if(target >= candidates[i])//only in this case we can pick
            {
                ds.push_back(candidates[i]);
                findCombSum2(candidates,target-candidates[i],i+1,ds,ans);//we have picked hence now required target = 
            														//target-candidates[ind]. Since we can't pick the same
            														//element again hence we pass ind+1
                ds.pop_back();//to explore next opportunity, when recursive call returns on the same level, we have to pop 
            			//back the number. See Subset sum II problem https://leetcode.com/problems/subsets-ii/
            }
            // findCombSum2(candidates,target,i+1,ds,ans); //if we do this and don't break in else case(all further numbers
														//are larger than target) that there are duplicate number then for 
														//loop will execute again and ans will get duplicated subsets.
            else break;//as all further numbers will be greater than target hence break out of this for loop
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());//so that equal numbers in candidates come together.
        findCombSum2(candidates,target,0,ds,ans);
        return ans;
    }
};
