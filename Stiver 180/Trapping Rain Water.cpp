//Problem link - https://leetcode.com/problems/trapping-rain-water/
//Video link - https://www.youtube.com/watch?v=m18Hntz4go8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=43

//Approach 1 - > Brute force approach ,	Time complexity -> O(n)	Space complexity -> O(n)

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


//Approach 2 -> Two pointer approach	Time complexity -> O(n) Space complexity -> O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1, leftMax = 0, rightMax =0, res = 0;
        
        //IDEA -> If right side is larger than current tower then we see that if current left tower is smaller than tallest 
        //left if so then we keep account of water stored because of difference in height of tallest left and current 
        //left tower.
		//Similarily if left side is larger than current right tower then we that if current right tower is smaller than
		//tallest right is so then we keep account of water stored because of difference in height of tallest right and 
		//current right tower  
        while(left<=right)
        {
            if(height[left]<=height[right])
            {
                if(height[left]>leftMax) leftMax = height[left];
                else res += leftMax - height[left];
                left++;
            }
            else//heigh[left]>height[right]
            {
                if(height[right]>rightMax) rightMax = height[right];
                else res += rightMax - height[right];
                right--;
            }
        }
        return res;
    }
};
