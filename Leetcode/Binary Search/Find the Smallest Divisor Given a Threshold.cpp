//Problem link - https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/


//Binary search in answer search space
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int thres) {
        int left = 1, right = 1e6,mid,sum;
        while(left<=right)
        {
            sum = 0;
            mid = left + (right-left)/2;
            for(int i:nums)
                sum += (i+mid-1)/mid;
            if(sum>thres)//divisor is small and hence need to be increased
            {
                left = mid+1;
            }
            else//divisor is enough large hence it can be decreased
            {
                right = mid-1;
            }
        }
        return left;//left must have passed right and right must have decreased more than needed or left must have increased so that sum<=thres
        			//hence left must hold the answer in the last.
    }
};
