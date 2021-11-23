//Problem link - https://leetcode.com/problems/majority-element/
//Video link - https://www.youtube.com/watch?v=AoX3BPWNnoE&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=17
//Boyer-Moore voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0,ans;
        for(int i:nums)
        {
            if(count==0)
                ans = i;
            if(i==ans)
                count++;
            else count--;
        }
        //Only that element will be retained in ans whose count woudn't have been zero. Obviously our ans has count greater than
        // n/2 so it will reside in ans after the loop
        return ans;
    }
};
