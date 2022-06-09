//Problem link - https://leetcode.com/problems/count-numbers-with-unique-digits/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n+1,0);//dp[i] is number of numbers having unique digits and which have digits less than or equal to i. All number < 10^n 
								//have at max n digits
        dp[0] = 1;//if n = 0 => number should be <10^0 => <1 and there is only one such number that is 0
        for(int i=1;i<=n;i++)
        {
            int val = 1;
            for(int j=0,dig = 9;j<i;j++)//Number of numbers of 3 digits having unique digits = 9 		*	 	9		 *		 8
            							//												0 at MSB is			One number 		Two numbers already
            							//												excluded			already used	used hence can't
            							//																					be repeated
            							//Similarily Number of numbers of 4 digits having unique digits = 9 * 9 * 8 * 7
            {
                val *= dig;
                if(j>0) dig--;//value starts decreasing from 9 after two times
            }
            dp[i] += dp[i-1] + val;//for e.g., total number of numbers having unique digits which is less than 10^5
            						// = number of 4 digit numbers having unique digits + number of 3 digit numbers having unique digtis
            						// + number of 2 digit numbers having unique digtis + number of 1 digit numbers having unique digtis
        }
            
        return dp[n];
    }
};
