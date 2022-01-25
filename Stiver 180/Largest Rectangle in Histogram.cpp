//Problem link - https://leetcode.com/problems/largest-rectangle-in-histogram/
//Video link - https://www.youtube.com/watch?v=X0X6G-eWgQ8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=81

//This question is inspired from SDE180/"next greater element" and SDE180/"previous smaller element"

//Brute force solution T(n) = O(n^2)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0,n=heights.size();
        for(int i=0;i<n;i++)
        {
            int leftSmaller = i,rightSmaller = i;
            while(++rightSmaller<n && heights[rightSmaller]>=heights[i]);
            while(--leftSmaller>=0 && heights[leftSmaller]>=heights[i]);
            ans = max(ans,(rightSmaller-leftSmaller-1)*heights[i]);
        }
        return ans;
    }
};

//Time complexity -> O(n)	Space complexity -> O(n) Solution 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nearestLeftSmallerInd(n),nearestRightSmallerInd(n);
        stack<pair<int,int>> stac;  //pair<int,int> <value,index>
        
        for(int i=0;i<n;i++)//storing the index of nearest tower on left having height less than this tower's height 
        {
            while(!stac.empty() && stac.top().first>=heights[i])//We could have also pushed index on stack as Striver did
                stac.pop();										//it in https://github.com/striver79/SDESheet/blob/main/largestRectangleHistorgram2passCpp
            if(stac.empty()) nearestLeftSmallerInd[i] = -1;//there is no tower on left having height less than this tower's height
            else nearestLeftSmallerInd[i] = stac.top().second;//save the index
            
            stac.push(make_pair(heights[i],i));//as we pushed this value onto stack as we did it while finding NGE
        }
        
        while(!stac.empty()) stac.pop();//Clear stack for next usage
        
        for(int i=n-1;i>=0;i--)
        {
            while(!stac.empty() && stac.top().first>=heights[i])
                stac.pop();
            if(stac.empty()) nearestRightSmallerInd[i] = n;
            else nearestRightSmallerInd[i] = stac.top().second;
            
            stac.push(make_pair(heights[i],i));
        }
        
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans = max(ans,(nearestRightSmallerInd[i]-nearestLeftSmallerInd[i]-1)*heights[i]);
        }
        return ans;
        
    }
};
