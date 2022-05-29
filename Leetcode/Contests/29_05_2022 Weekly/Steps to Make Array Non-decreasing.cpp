//Problem link - https://leetcode.com/problems/steps-to-make-array-non-decreasing/
//Video link - https://www.youtube.com/watch?v=NQGduRE1Crk
class Solution {
public:
    int totalSteps(vector<int>& nums) 
    {
        stack<pair<int,int>> st;
        int ans = 0;
        for(int i = nums.size()-1;i>=0;i--)
        {
            int count = 0;//How many steps are taken to remove the numbers which are smaller than nums[i]  and are on its right side
            while(!st.empty() && st.top().first<nums[i])
            {
                thisSeq = max(count+1,st.top().second);//Why this step is important
                st.pop();
            }
            st.push(make_pair(nums[i],count));
            ans = max(ans,count);//Answer is maximum steps required
        }
        return ans;
    }
};

//Why following code doesn't work and the above code works
//Video explanation - https://www.youtube.com/watch?v=KcAfy6ZbtU8&list=PLudlC33BR8eEiSWH654z2GKEF3Ckz6QWB&index=9


//This code doesn't work
class Solution {
public:
    int totalSteps(vector<int>& nums) 
    {
        stack<int> st;
        int ans = 0;
        for(int i = nums.size()-1;i>=0;i--)
        {
            int thisSeq = 0;
            while(!st.empty() && st.top()<nums[i])
            {
                st.pop();
                thisSeq++;
            }
            st.push(nums[i]);
            ans = max(ans,thisSeq);
        }
        return ans;
    }
};
