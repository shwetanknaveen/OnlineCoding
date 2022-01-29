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

//Approach 2 Time complexity = O(n) 	Space complexity = O(n)
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        deque<int> deq;
       for(int i=0;i<n;i++)//initially everyone is potential celebrity
           deq.push_back(i);
        
        int potentialCeleb;
        while(!deq.empty())
        {
            if(deq.size()==1)//if only one person is remaining then he is potential celebrity
            {
                potentialCeleb = deq.front();
                break;
            }
            
            if(M[deq.front()][deq.back()])//if front guy know back guy then front guy can't be potential celebrity
                deq.pop_front();
            else if(M[deq.back()][deq.front()])//if back guy know front guy then he can't be potential celbrity
                deq.pop_back();
            else//both don't know each other hence both can't be celebrity
            {
                deq.pop_front();
                deq.pop_back();//we have already insured that there are more than 1 elements on the deque
            }
        }
        for(int i=0;i<n;i++)
            if(i!=potentialCeleb && (M[potentialCeleb][i] || !M[i][potentialCeleb]))//if the last remaining guy knows someone or not known by someone then there is no celebrity at all
                return -1;
        
        return potentialCeleb;
    }
};

//Approach 3 => Utilising the approach 2
//Time complexity = O(n)	Space complexity = O(1)

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int potentialCeleb = 0;
        for(int i=0;i<n;i++)
        {
            if(M[potentialCeleb][i])
                potentialCeleb = i;//earlier potentialCeleb knows i hence he can't be celebrity but  i can be which will be checked further
        }
        for(int i=0;i<n;i++)
            if(i!=potentialCeleb && (M[potentialCeleb][i] || !M[i][potentialCeleb]))//if the last remaining guy knows someone or not known by someone then there is no celebrity at all
                return -1;
        
        return potentialCeleb;
    }
};
