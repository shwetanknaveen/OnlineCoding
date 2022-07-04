//Problem link - https://leetcode.com/problems/candy/
//For solution explanatins -> See leetcode solutions

//Approach 1 -> Brute Force -> Gives TLE (O(n^2))

class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n = ratings.size(),count = 0;
        vector<int> candies(n,1);
        bool hasChanged = true;
        while(hasChanged)
        {
            hasChanged = false;
            for(int i=0;i<n;i++)
            {
                if(i != n-1 && ratings[i]>ratings[i+1] && candies[i]<=candies[i+1])
                {
                    candies[i] = candies[i+1] +1;
                    hasChanged = true;
                }
                if(i>0 && ratings[i]>ratings[i-1] && candies[i]<=candies[i-1])
                {
                    candies[i] = candies[i-1] +1;
                    hasChanged = true;
                }
            }
        }
        for(int i:candies)
            count += i;
        return count;
    }
};

//Apporach 2 -> (O(n) Space and O(n) Time complexity solution)

class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n = ratings.size(),count = 0;
        vector<int> leftToRight(n,1),rightToLeft(n,1);
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
                leftToRight[i] = leftToRight[i-1] + 1;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
                rightToLeft[i] = rightToLeft[i+1] + 1;
        }
        for(int i=0;i<n;i++)
            count += max(leftToRight[i],rightToLeft[i]);
        return count;
    }
};
