//Problem link - https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

/*
Let's define sum as the sum of all the numbers, before any moves; minNum as the min number int the list; n is the length of the list;

After, say m moves, we get all the numbers as x , and we will get the following equation

 sum + m * (n - 1) = x * n
and actually,

  x = minNum + m
it comes from two observations:

the minum number will always be minum until it reachs the final number, because every move, other numbers (besides the max) will be increamented too;
from above, we can get, the minum number will be incremented in every move. So, if the final number is x, it would be minNum + moves;
and finally, we will get

  sum - minNum * n = m
*/

//Video explanation-> Thinking it other way -> https://www.youtube.com/watch?v=GDg0iGWUU2M

class Solution {
public:
    int minMoves(vector<int>& nums) {
        long sum = 0;
        int mini = INT_MAX;
        for(int i:nums)
        {
            sum += i;
            mini = min(mini,i);
        }
        return sum-nums.size()*mini;
    }
};
