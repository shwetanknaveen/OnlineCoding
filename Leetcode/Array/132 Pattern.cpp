//Problem link - https://leetcode.com/problems/132-pattern/
//Self video explanation - https://www.youtube.com/watch?v=3fQORixMtd8&list=PLudlC33BR8eEiSWH654z2GKEF3Ckz6QWB&index=4
//Apporach 1 -> Brute force -> Gives TLE

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<=n-3;i++)
        {
            for(int j=i+1;j<=n-2;j++)
            {
                if(nums[j]<=nums[i])
                    continue;
                for(int k=j+1;k<n;k++)
                {
                    if(nums[k]>nums[i] && nums[k]<nums[j]) return true;
                }
            }
        }
        return false;
    }
};

//Approach 2 
// i<j<k and nums[i] < nums[k] < nums[j]
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int atK = INT_MIN;
        stack<int> st;//stack will contain numbers in increasing fashion from top to bottom
        for( int i = nums.size()-1; i >= 0; i -- ){
            if( nums[i] < atK ) return true;//as in the previous step for number on right side(say at j), we saw a number at k that was JUST 
											//smaller than it and now this number is smaller than that number at k hence 321 triplet is possible.
											//We already found two numbers on right side such that number at k was just smaller than number at
											//j. Hence to follow the condition that number at this index is smaller than smaller of the already
											//found pair is that the smaller one the found pair is just smaller and not the smallest.
											//And that is what we found -> Number at k was just smaller than number at j
											
            else while( !st.empty() && nums[i] > st.top())//We will drop from stack if the number on stack is smaller than this number
			{ 											//We won't update atK even if the number on stack is equal to this number
              atK = st.top();//for this index, keep the number on right side which is JUST smaller than this number in atK variable 
			  st.pop(); 
            }
            st.push(nums[i]);
        }
        return false;
    }
};
