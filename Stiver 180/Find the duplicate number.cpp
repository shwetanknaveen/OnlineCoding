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
        
        //REMARK: Note the proof that how duplicate number i.e., at second collision
        //is at junction in the reference video from time 5:46
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

//If all the numbers in the arrray are distinct except that one repeating number
//then following solution can also work
/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int ans = 0;//EXOR with 0 is identity
        for(int i=1;i<=n;i++)
            ans ^= i;
        for(int i=0;i<=n;i++)
            ans ^= nums[i];
        return ans;
    }
};
*/
