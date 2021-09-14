//Problem link - https://leetcode.com/problems/trapping-rain-water/submissions/

/*Approach-> We keep maximum height of the tower on left and maximum height of the tower on the right.Let the be h1 and h2
.Water that can stored be over this tower is 0 if min(h1,h2) is less than current tower's height otherwise it's the diff-
-erence between min(h1,h2) and current tower's height. Total water stored is sum of all water stored over all these towers
store over the current tower is 
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> leftMax(size);
        vector<int> rightMax(size);
        
        int maxi = 0;
        
        for(int i=0;i<size;i++)
        {
            maxi = max(height[i],maxi);
            if(i==0)
            {
                leftMax[i] = 0;//max height of any left tower for the first tower is zero
            }
            else
            {
                leftMax[i] = maxi;
            }
        }
        maxi = 0;
        for(int i=size-1;i>=0;i--)
        {
            maxi = max(height[i],maxi);
            if(i==size-1)
            {
                rightMax[i] = 0;//max height of any right tower for the last tower is zero
            }
            else
            {
                rightMax[i] = maxi;
            }
        }
        
        int water = 0;
        int mini;
        for(int i=0;i<size;i++)
        {
            mini = min(leftMax[i],rightMax[i]);
            if(mini<=height[i])
            {
                continue;//if minimum of the tallest towers on left and right is less than this tower
                        //height itself then no water can stay over this tower.
            }
            else
            {
                water += mini - height[i];//water stored just above a tower is the difference in the                                               //tower height from current one and the minimum one from the 
                                          //tallest from left and right
            }
        }
        
        return water;
    }
};
