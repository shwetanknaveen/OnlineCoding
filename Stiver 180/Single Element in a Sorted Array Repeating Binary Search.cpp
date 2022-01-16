//Problem link - https://leetcode.com/problems/single-element-in-a-sorted-array/
//Video link - https://www.youtube.com/watch?v=PzszoiY5XMQ&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=65

//Approach - 1 Striver approach
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1; 
        while(low <= high) {
            int mid = low +(high-low)/2; 
            
            if(mid&1)//if mid is odd then first occurence of this repeating number should be on the even index before mid
            {
                if(nums[mid]==nums[mid-1])//it is eqal => left half doesn't contain the number
                						//if mid is odd then mid-1 won't go less than zero so need to check it
                {
                    low=mid+1;
                }
                else//it is not equal and left half contains the number
                {
                    high=mid-1;
                }
            }
            else//mid is even => first occurence of this repeating number should be on the odd index after mid
            {
                if(mid+1 >= nums.size()) break;//it means mid = nums.size()-1 and it happens when low = high= mid = nums.size()-1 and the required number is on the last index
                //this is extra condition which we have to put here
                //we can't check nums[mid+1] here and we have to break
                
                if(nums[mid]==nums[mid+1])//it is equal and left part doesn't contain the required number
                {
                    low = mid+1;
                }
                else//it is not equal and left part contains the required number
                {
                    high = mid-1;
                }
                
            }
        }
        return nums[low]; 
    }
};

//Neater code of striver approach
//NOTE-> if mid is odd then mid^1 gives even number just before it but if mid is even then mid^1 gives odd number just 
//ahead of it

int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 2;//low can give ans at last index too hence asigning high in this manner 
        while(low <= high) {
            int mid = (low + high) >> 1; 
            if(nums[mid] == nums[mid^1]) {
                low = mid + 1; 
            } 
            else {
                high = mid - 1; 
            }
        }
        return nums[low]; 
    }
