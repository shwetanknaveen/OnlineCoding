//Problem link - https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    void helper(int ind,int sum,int &n,int k,vector<int> &thisComb, vector<vector<int>> &ans)
    {
     if(k==0)//all the numbers have been used
     {
        if(sum==n)//if required sum has been achieved then this is a one of possible combination
            ans.push_back(thisComb);
         return;
     }
        if(sum>n || ind>9) return;//if present sum is exceeding required sum or we are using any number greater than 9 then this combination
        							//is not the required combination and hence no need to look further
        thisComb.push_back(ind);//push this number in present combination
        helper(ind+1,sum+ind,n,k-1,thisComb,ans);//go to next number with adding this number in present sum
        thisComb.pop_back();//pop the last pushed number so as to explore the next possibility on return of control when recursion call
        					//returns to this level
        helper(ind+1,sum,n,k,thisComb,ans);//Don't use this number and go on further to explore possiblity without using this number in
        									//the combinatioin
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> thisComb;
        vector<vector<int>> ans;
        helper(1,0,n,k,thisComb,ans);//We can start using numbers from 1 hence ind = 1 and initial sum is 0
        return ans;
    }
};
