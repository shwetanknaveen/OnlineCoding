//Problem link - https://leetcode.com/problems/count-the-hidden-sequences/

/*
Let the first number of array be x then next number in the array will be x+differences[0] and similarily there are other
numbers in the array. The maximum increase/decrease that can happen to x is calculated as maxIncrease and maxDecrease below.
Let's take the example of the testcase

Input: differences = [1,-3,4], lower = 1, upper = 6
Output: 2
Explanation: The possible hidden sequences are:
- [3, 4, 1, 5]
- [4, 5, 2, 6]

Let first number be x then numbers are as following
	x, x+1, x-2, x + 2
	
So now, minimum = x-2 >= 1 		and 		maximum = x + 2 <= 6
generalising 
			x+maxDecrease >= low	and x+maxIncrease <= upper			**maxDecrease will have negative sign
		=>  x >= low - maxDecrease and  x <= upper - maxIncrease 
		
		=> 	low - maxDecrease <= x <= upper - maxIncrease
		
Now if 1<= x <= 2 then number of values x can take is (2-1)+1 =2 Hence in above case

number of values for x = (upper - maxIncrease) - (low - maxDecrease) + 1
						= (upper - lower) - (maxIncrease - maxDecrease) +1
*/



class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long prefSum = 0,maxIncrease = 0, maxDecrease = 0;
        for(int diff:differences)
        {
            prefSum += diff;
            maxIncrease = max(maxIncrease,prefSum);
            maxDecrease = min(maxDecrease,prefSum);
        }
        
        return max(0L, (upper-lower) - (maxIncrease - maxDecrease) +1);//second argument of max() is long hence cast 1st one 
        															  //also to long
        															  //If there is no possible value then answer has to be 0
    }
};
