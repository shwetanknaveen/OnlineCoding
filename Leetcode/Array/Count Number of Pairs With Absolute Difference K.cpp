//Problem link - https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/


/*
abs(num1-num2) = k   ==> num1-num2=k or num2-num1=k
                     ==> num1 = k+num2 or num2=k+num1
Let's think in repect of one number
*/
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
                m[nums[i]]++;
        }
        for(int i:nums)
        {
            int num2 = k+i;
            if(m.find(num2)!=m.end())
            {
                if(num2==i)			/*Let's array=[1,2,3] and k=0 then for i=1 num2 = 1+0=1 whose frequency is 1 but we can't
								 include 1 as num2=1 is i itself hence it's frequence should be taken 1 less as we are using i */
                    c=c+m[num2]-1;    
                else
                    c=c+m[num2];
            }
            
        }
        return c;
    }
};
