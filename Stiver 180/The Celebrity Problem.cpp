//Problem link - Leetcode premium - https://leetcode.com/problems/find-the-celebrity/
//Problem link - GFG - https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1/

//Approach - 1 Brute force solution GFG			 Time complexity = O(n^2)
class Solution 
{
    public:
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int ans = -1;
        for(int i=0;i<n;i++)
        {
            bool doesntKnowAnyone = true, knownByEveryone = true;
            for(int j=0;j<n;j++)
            {
                if(M[i][j] == 1 && i!=j)//same guy is given as not knowing himself that's why i!=j check
                {
                    doesntKnowAnyone = false;
                    break;
                }
            }
            if(doesntKnowAnyone)//if ith guy doesn't know anyone then he is potential celebrity, we have to check that 
            					//whether he is known by everyone or not
            {
                for(int j=0;j<n;j++)
                {
                    if(M[j][i] == 0 && i!=j) //same guy is not known to himself that's why i!=j check
                    						//Notice the indices M[i][j] tells whether i knows j(=1) or not (=0)
                    {
                        knownByEveryone = false;
                        break;
                    }
                }
            }
            if(doesntKnowAnyone && knownByEveryone)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

//Approach - 1 Brute force solution Leetcode		Time complexity = O(n^2)
/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int ans = -1;
        for(int i=0;i<n;i++)
        {
            bool doesntKnowAnyone = true, knownByEveryone = true;
            for(int j=0;j<n;j++)
            {
                if(knows(i,j) == 1 && i!=j)//same guy is given as not knowing himself that's why i!=j check
                {
                    doesntKnowAnyone = false;
                    break;
                }
            }
            if(doesntKnowAnyone)//if ith guy doesn't know anyone then he is potential celebrity, we have to check that 
            					//whether he is known by everyone or not
            {
                for(int j=0;j<n;j++)
                {
                    if(knows(j,i) == 0 && i!=j) //same guy is not known to himself that's why i!=j check
                    						//Notice the indices,knows(i,j) tells whether i knows j(=1) or not (=0)
                    {
                        knownByEveryone = false;
                        break;
                    }
                }
            }
            if(doesntKnowAnyone && knownByEveryone)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
