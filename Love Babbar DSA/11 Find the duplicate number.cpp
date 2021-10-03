//Problem link - https://leetcode.com/problems/find-the-duplicate-number/
//Video link - https://www.youtube.com/watch?v=32Ll35mhWg0
//See this question also - https://github.com/shwetanknaveen/OnlineCoding/blob/master/GFG/Linked%20List/Remove%20loop%20from%20Linked%20list.cpp

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Naive solution
        // unordered_set<int> num;
        // int returnVal;
        // for(int i:nums)
        // {
        // if(num.find(i)!=num.end())
        // {
        //     returnVal=i;
        //     break;
        // }
        // else num.insert(i);
        // }
        // return returnVal;
        
        int slow = nums[0];
        int fast = nums[0];//initialising both to the start
        
        do{
            slow = nums[slow];//slow moves on distance
            fast = nums[nums[fast]];//fast moves two distances
        }while(slow!=fast);
        
        fast = nums[0];//fast is reinitialised to the start and now it will travel with slow pace, 
					   //now the point where they will meet will be the repeating point as it was the
					   // point in linked list question where the cycle was getting formed.
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;//here slow = fast
        
    }
};
