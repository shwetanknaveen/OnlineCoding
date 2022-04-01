//Problem link - https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        if (nums.empty()) return 0;
        
        int result = INT_MIN, maxProd = 1, minProd = 1;
        //keep maxProd as large as possbile and minProd as small as possible
        
        //When 0 is encountered then maxProd and minProd, both are set 0 in the loop
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0){//if upcoming number is -ve then multiplication with it will make maxProd as -ve and vice versa hence we swap them
                swap(maxProd, minProd);
            }
            maxProd = max(maxProd*nums[i], nums[i]);//in previous steps, maxProd might be set 0 hence if coming number is 
            										//say x then maxProd should be x.
            minProd = min(minProd*nums[i], nums[i]);
            
            result = max(result, maxProd);
        }
        
        return result;
    }
};


/*
candidates = (A[i], imax * A[i], imin * A[i])
imax = max(candidates)
imin = min(candidates)
*/
