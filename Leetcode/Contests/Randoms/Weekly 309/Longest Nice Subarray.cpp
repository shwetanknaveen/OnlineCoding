//Problem link - https://leetcode.com/problems/longest-nice-subarray/

//Approach 1 -> My contest approach -> O(n^2)
class Solution {
public:
    int longestNiceSubarray(vector<int> &nums) 
    {
        int ans = 1, n = nums.size();
        for(int i=0,j=1;i<n && j<n;)
        {
            int k = i;
            while(k<j && ((nums[k] & nums[j])==0)) k++;
            if(k==j)//this new addition of number in the subarray is ok
            {
                ans = max(ans,j-i+1);
                j++;//look to add new one in this subarray
            }
            else i=k+1;//set starting of the window
            if(i>=j) j=i+1;//window has to expand from left to right hence right boundary has to be on right of left boundary
        }
        return ans;
    }
};

/*
Approach 2 -> O(n)

Each bit of numbers in which are in nice subarray has to be unique
*/

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        int ans = 1,mask = 0,n = nums.size();
        for(int i=0,j=0;i<n && j<n;j++)
        {
            while((mask&nums[j]))//all those number which have some bit as same then drop them and shrink window from left
            {
                mask ^= nums[i];//Use exor for dropping
                i++;
            }
            
            mask |= nums[j];//take the number on the right
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};
