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
        return ans;
    }
};
