//Problem link - https://leetcode.com/problems/non-decreasing-array/
//Video link - https://www.youtube.com/watch?v=bIYyRYT5hig&list=PLudlC33BR8eEiSWH654z2GKEF3Ckz6QWB&index=11
class Solution {
public:
    int getNext(int ind,vector<int> &nums)
    {
        return ind<nums.size()-1 ? nums[ind+1] : INT_MAX;//last index number assumes that there is infinity at its right
    }
    int getPrev(int ind,vector<int> &nums)
    {
        return ind>0 ? nums[ind-1] : INT_MIN;//first index number assumes that there is -infinity at its left
    }
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        bool first = true;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])//needs correction
            {
                if(first)//it is first time that correction is needed
                {
                    first = false;
                    if(getNext(i+1,nums)>nums[i])//if number at nums[i+2] is larger than nums[i] then promote nums[i+1] to nums[i] 
                    {
                        nums[i+1] = nums[i];
                    }
                    else
                    {
                        nums[i] = getPrev(i,nums);//reduce the value of nums[i] as much as possible
                    }
                    i--;//after change recheck the present index for the condition
                }
                else return false;
            }
        }
        return true;
    }
};
