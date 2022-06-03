//Problem link - https://leetcode.com/problems/koko-eating-bananas/
//Same problem as - "Leetcode/Binary Search/Find the smallest Divisor given a threshold" https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = INT_MAX,mid,sum;

        while(left<=right)
        {
            sum = 0;

            mid = left + (right-left)/2;

            for(int i:piles)
                sum += (i+mid-1)/mid;//taking ceil(i/mid) as (i+mid-1)/mid
                
            if(sum>h)//totol time required to eat banana is higher than h hence rate of eating banana must be increased

            {

                left = mid+1;

            }

            else//total time is less than h hence rate of eating banana may be decreased

            {

                right = mid-1;

            }

        }

        return left;//left must have passed right and right must have decreased more than needed or left must have increased so that sum<=thres

        			//hence left must hold the answer in the last.

    
    }
};
