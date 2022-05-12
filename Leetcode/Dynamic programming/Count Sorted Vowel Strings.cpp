//Problem link - https://leetcode.com/problems/count-sorted-vowel-strings/

//Approach 1
//We assume that all the vowels are present in a vector in sorted order starting from index 0 to 4. We will build the string only in sorted
//order
class Solution {
public:
    int helper(int ind,int len,int &n,vector<vector<int>> &dp)
    {
        if(len==n)//if length of the present built string is reached to the required length then this is one possible combination
            return 1;
        if(ind>4) return 0;//if we are using alphabet outside a,e,i,o or u then no possible string with given constraint
        if(dp[ind][len] != -1) return dp[ind][len];
        int n1 = helper(ind,len+1,n,dp);//We use this vowel in the string and hence increase the length but we don't increase ind as we can
        								//use this vowel again (Like unbounded knapsack)
        int n2 = helper(ind+1,len,n,dp);//We don't use this vowel and go on further to explore for building the string with remaining vowels
        return dp[ind][len] = n1+n2;
    }
    int countVowelStrings(int n) {
        vector<vector<int>> dp(5,vector<int>(n+1,-1));
        return helper(0,0,n,dp);
    }
};

//Approach 2
/*
We know that non negative solution of n1+n2+n3+n4+n5 = n is dividing 1,1,1,1.....(n times) into 5 parts (4 partitioners are required to
divide into 5 parts). Hence number of solutions is (n+5-1)C4. We have n+4 places to fill (n 1s and 4 partitioners) and we have to choose
4 places for partitioners from these places.We observe that order of 1's doesn't affect the count of solutions as they all are same.
Now we map the given problem into the above problem in following way.
We can think a,e,i,o and u as n1,n2 ...n5 and here too change of order should be restricted because it is given that string should be formed
in sorted order.
(n+4)C4 = (n+4)*(n+3)*(n+2)*(n+1))/24
*/

class Solution {
public:
    int countVowelStrings(int n) {
        return ((n+4)*(n+3)*(n+2)*(n+1))/24;
    }
};
