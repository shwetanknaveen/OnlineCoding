//Problem link - https://leetcode.com/problems/longest-consecutive-sequence/solution/
//video link - https://www.youtube.com/watch?v=qgizvmgeyUM
//see video for complexity analysis
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> setOfNums;
        for(int i: nums)
            setOfNums.insert(i);//put all the elements in the set
        int size = nums.size();
        if(size == 0) return 0;//if there is no element in the vector itself then return 0
        int maxi = 1;
        int curr;
        for(int i=0;i<size;i++)
        {
            if(setOfNums.find(nums[i]-1)!=setOfNums.end())
                continue;//if there exist an element for which this element is the consecutive element then we leave this
                		//element and we will start our counting from the least element which will be in the consecutive set
            int start = nums[i];//this is the element for which no lower consecutive value exist hence we will start our 
            					//counting from here
            curr = 0;//current count = 0 --> each time we start counting for different consecutive set
            while(setOfNums.find(start)!=setOfNums.end())//keep on counting untill we keep on finding next consecutive element
            {
                curr++;
                start = start + 1;//next consecutive element will be +1
            }
            maxi = max(maxi,curr);//maximum will be the maximum of current best and what we just found
        }
        return maxi;
    }
};

